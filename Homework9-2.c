#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
int read_int() {
	int a;
	scanf("%d", &a);
	return a;
}
void scanArr(int arr[], size_t len) {
	for (size_t i = 0; i < len; i++) {
		arr[i] = read_int();
	}
}
int* findInArr(int arr[], size_t len, int x) {
	for (size_t i = 0; i < len; i++) {
		if (arr[i] == x) {
			return &arr[i];
		}
	}
	return NULL;
}
int* findSubArr(int arr1[],int arr2[],size_t len1,size_t len2) {
	int j = 0;
	int count = 0;
	for (int i = 0; i < len1; i++) {
		if (arr1[i] == arr2[j]) {
			count++;
			j++;
			if (j == len2) {
				return findInArr(arr1, len1, arr2[0]);
			}
		}
		else{
			j = 0;
		}
	 }
}

int main() {
	printf("Enter length of your array one=");
	int len1 = read_int();
	void* ptr1 = malloc(len1 * sizeof(int));
	int* arr1 = (int*)ptr1;
	printf("Enter elements of array two:\n");
	scanArr(arr1, len1);
	printf("Enter length of your array two=");
	int len2 = read_int();
	void* ptr2 = malloc(len2 * sizeof(int));
	int* arr2 = (int*)ptr2;
	printf("Enter elements of array two:\n");
	scanArr(arr2, len2);
	int* s = findSubArr(arr1, arr2, len1, len2);
	int y = *s;
	printf("%p\n", s);
	printf("%d", y);
}*/