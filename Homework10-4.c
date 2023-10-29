#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
//make you code more safer
int init(char c, int base) {
	if (isdigit(c)) {
		return (c - '0');
	}
	else if (isalpha(c)) {
		return (10 + (c - 'A'));
	}
	return -1; // Uncorected
}
int s2i(const char* str, int alf,jmp_buf* env) {
	if (alf<2 || alf>16) {
		if (env == NULL) {
			exit(-1);
		}
		else {
			longjmp(*env, 1);
		}
	}

	int count = 0;
	int result = 0;
	int mysize = (sizeof(str)/2)-1;
	int sign = 1;
	if (str[0] == '-') {
		count++;
		sign = -1;
	}
	while (str[count] != '\0') {
		int digit = init(str[count], alf);
		if (digit == -1) {
			if(env == NULL) {
				exit(-1);
			}
		else {
			longjmp(*env, 1);
			}
		}
		if (result > (INT_MAX - (digit*pow(alf,mysize)))) {
			if (env == NULL) {
				exit(-1);
			}
			else {
				longjmp(*env, 1);
			}
		}
		result = result + (init(str[count],alf) * pow(alf, mysize));
		mysize--;
		count++;
	}
	return result * sign;
}

int main() {
	jmp_buf env;
	if (setjmp(env) == 0) {
		char str[] = "1A3F"; // Your str
		int base = 16;
		int result = s2i(str, base, &env);
		printf("Result: %d\n", result);
	}
	else {
		printf("Error!:uncorect str or overflow \n");
	}

	return 0;
}