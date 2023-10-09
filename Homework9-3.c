#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
void printArr(int arr[], size_t len) {
	for (size_t i = 0; i < len; i++) {
		printf("%d\n", arr[i]);
	}
}
int DeleteSubArr(int arr1[], int arr2[], size_t len1, size_t len2) {
	int j = 0;
	for (int i = 0; i < len1; i++) {
		if (arr1[i] == arr2[j]) {
			j++;
			if (j == len2) {
				for (int w = 0; w < len2;w++) {
					len1 = deleElem(arr1, len1, i-(j-1));
				}
				i = 0;
			}
		}
		else {
			j = 0;
		}
	}
	return len1;
}
int deleElem(int arr[], size_t len, int del_ind) {
	for (int i = del_ind; i < len; i++) {
		arr[i] = arr[i + 1];
	}
	return (len - 1);
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
	printf("Your Array before delete subArray:\n");
	printArr(arr1, len1);
	len1 = DeleteSubArr(arr1, arr2, len1, len2);
	printf("After:\n");
	printArr(arr1, len1);
}
