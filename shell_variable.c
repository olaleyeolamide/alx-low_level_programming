#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_VARIABLES 10

char* findCharacter(const char* str, char ch) {
    while (*str != '\0' && *str != ch) {
        str++;
    }
    return (*str == ch) ? (char*)str : NULL;
}

size_t stringLength(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

void replaceVariables(char* command, char* variables[MAX_VARIABLES], int variableCount) {
    char* ptr = command;
    char* start;
    char* end;
    char variableName[MAX_COMMAND_LENGTH];
    char* replacement;

    while ((start = findCharacter(ptr, '$')) != NULL) {
        // Check for $? variable
        if (*(start + 1) == '?') {
            end = start + 2;
            char errorCode = errno;
            int numDigits = 0;
            while (errorCode != 0) {
                errorCode /= 10;
                numDigits++;
            }
            replacement = variableName;
            variableName[numDigits] = '\0';
            for (int i = numDigits - 1; i >= 0; i--) {
                variableName[i] = (errno % 10) + '0';
                errno /= 10;
            }
        }
        // Check for $$ variable
        else if (*(start + 1) == '$') {
            end = start + 2;
            int pid = getpid();
            int numDigits = 0;
            int pidCopy = pid;
            while (pidCopy != 0) {
                pidCopy /= 10;
                numDigits++;
            }
            replacement = variableName;
            variableName[numDigits] = '\0';
            for (int i = numDigits - 1; i >= 0; i--) {
                variableName[i] = (pid % 10) + '0';
                pid /= 10;
            }
        }
        // Check for other variables
        else {
            end = start + 1;
            while (*end != '\0' && (*end == '_' || (*end >= 'a' && *end <= 'z') || (*end >= 'A' && *end <= 'Z') ||
                                   (*end >= '0' && *end <= '9'))) {
                end++;
            }
            int variableNameLength = end - start - 1;
            for (int i = 0; i < variableNameLength; i++) {
                variableName[i] = *(start + i + 1);
            }
            variableName[variableNameLength] = '\0';
            replacement = NULL;

            for (int i = 0; i < variableCount; i++) {
                int j = 0;
                while (variables[i][j] != '\0' && variables[i][j] == variableName[j]) {
                    j++;
                }
                if (variables[i][j] == '=') {
                    replacement = variables[i] + j + 1;
                    break;
                }
            }
        }

        if (replacement != NULL) {
            size_t replacementLength = stringLength(replacement);
            memmove(start, replacement, replacementLength);
            ptr = start + replacementLength;
            memmove(ptr, end, stringLength(end) + 1);
        } else {
            ptr = end;
        }
    }
}

int main() {
    char* command = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    char* variables[MAX_VARIABLES];
    int variableCount = 0;

    while (1) {
        // Prompt for user input
        printf("Enter a command: ");
        characters = getline(&command, &bufsize, stdin);

        // Remove newline character from input
        if (characters > 0 && command[characters - 1] == '\n') {
            command[characters - 1] = '\0';
        }

        // Ignore empty lines and comments
        if (characters <= 1 || command[0] == '#') {
            continue;
        }

        // Handle variable replacement
        replaceVariables(command, variables, variableCount);

        // Execute the command
        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            continue;
        } else if (child_pid == 0) {
            // Child process
            char* args[] = { "/bin/sh", "-c", command, NULL };
            execve("/bin/sh", args, NULL);
            _exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            waitpid(child_pid, &status, 0);

            if (WIFEXITED(status)) {
                printf("Command executed with status code: %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Command terminated by signal: %d\n", WTERMSIG(status));
            }
        }

        // Update $? variable
        char* errorCode = (char*)malloc(MAX_COMMAND_LENGTH);
        char errorCodeDigits[MAX_COMMAND_LENGTH];
        int errorCodeLength = 0;
        int errnoCopy = errno;
        while (errnoCopy != 0) {
            errorCodeDigits[errorCodeLength++] = (errnoCopy % 10) + '0';
            errnoCopy /= 10;
        }
        errorCodeDigits[errorCodeLength] = '\0';
        int index = 0;
        for (int i = errorCodeLength - 1; i >= 0; i--) {
            errorCode[index++] = errorCodeDigits[i];
        }
        errorCode[index] = '\0';
        variables[variableCount] = errorCode;
        variableCount++;
    }

    // Free allocated memory
    for (int i = 0; i < variableCount; i++) {
        free(variables[i]);
    }
    free(command);
    return 0;
}
