#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int palindrom(const char* str) {
	size_t len= strlen(str);
	size_t half_len = len / 2;
	len-=2;
	for (size_t i = 0; i < half_len; i++) {
		if (str[i] == ' ') {
			continue;
		}
		if (str[len-i] == ' ') {
			len--;
		}
		if (str[i] != str[len-i]) {
			return 0;
		}
	}
	return 1;
}
int main() {
	char str[10];
	fgets(str, sizeof(str), stdin);
	if (palindrom(str)==1) {
		printf("Str is palidrom\n");
	}
	else {
		printf("Str is not a palidrom\n");
	}
	return 0;
}

