#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char* trim(const char* str) {
	if (str == NULL) {
		return NULL;
	}
	int len = strlen(str);
	int start = 0;
	int end = len - 1;

	while (start < len && isspace(str[start])) {
		start++;
	}
	while (end >= 0 && isspace(str[end])) {
		end--;
	}
	if (start > end) {
		return _strdup("");
	}
	int newLen = end - start + 1;
	char* result = (char*)malloc(newLen + 1);
	if (result == NULL) {
		return NULL;
	}

	strncpy(result, str + start, newLen);
	result[newLen] = '\0'; 

	return result;
}

int main() {
	char str[100];
	fgets(str, sizeof(str), stdin);
	char* Str_trimmed = trim(str);
	printf("%s", Str_trimmed);
	free(Str_trimmed);
	return 0;
}
