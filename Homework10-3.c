#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char** splitIntoWords(const char* str, int* wordCount) {
    if (str == NULL || wordCount == NULL) {
        return NULL;
    }

    int length = strlen(str);
    char** words = NULL;
    int count = 0;
    int wordStart = -1;

    for (int i = 0; i <= length; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (wordStart != -1) {
                count++;
                wordStart = -1;
            }
        }
        else {
            if (wordStart == -1) {
                wordStart = i;
            }
        }
    }

    if (count == 0) {
        *wordCount = 0;
        return NULL;
    }

    words = (char**)malloc(count * sizeof(char*));
    if (words == NULL) {
        *wordCount = 0;
        return NULL;
    }

    int wordIndex = 0;
    wordStart = -1;
    for (int i = 0; i <= length; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (wordStart != -1) {
                int wordLength = i - wordStart;
                words[wordIndex] = (char*)malloc(wordLength + 1);
                if (words[wordIndex] == NULL) {
                    for (int j = 0; j < wordIndex; j++) {
                        free(words[j]);
                    }
                    free(words);
                    *wordCount = 0;
                    return NULL;
                }
                strncpy(words[wordIndex], str + wordStart, wordLength);
                words[wordIndex][wordLength] = '\0';
                wordIndex++;
                wordStart = -1;
            }
        }
        else {
            if (wordStart == -1) {
                wordStart = i;
            }
        }
    }

    *wordCount = count;
    return words;
}

void freeWords(char** words, int wordCount) {
    if (words == NULL) {
        return;
    }

    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }

    free(words);
}

int main() {
    const char* inputString[100];
    fgets(inputString, sizeof(inputString), stdin);
    int wordCount = 0;
    char** words = splitIntoWords(inputString, &wordCount);

    if (wordCount > 0) {
        printf("Your str: \"%s\"\n", inputString);
        printf("Words count: %d\n", wordCount);
        printf("Words:\n");
        for (int i = 0; i < wordCount; i++) {
            printf("%s\n", words[i]);
        }

        freeWords(words, wordCount);
    }
    else {
        printf("Str dont have any words\n");
    }

    return 0;
}