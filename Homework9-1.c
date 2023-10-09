#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*int read_int() {
	int a;
	scanf("%d", &a);
	return a;
}
void printArr(int arr[], size_t len) {
	for (size_t i = 0; i < len; i++) {
		printf("%d\n", arr[i]);
	}
}
int* concat(int arr1[], int arr2[], size_t len1, size_t len2,size_t*retPlace) {
	size_t all = len1 + len2;
	int* newArr = (int*)malloc(all * sizeof(int));
	for (size_t i = 0; i < len1; i++) {
		newArr[i] = arr1[i];
	}
	size_t j = 0;
	for (size_t i = len1; i < all; i++) {
		newArr[i] = arr2[j];
		j++;
	}
	*retPlace = all;
	return newArr;
}
int main() {
	int arr1[] = { 1,2,3,4 };
	int arr2[] = { 5,6,7,8,9 };
	size_t all;
	int* Arr = concat(arr1, arr2, 4, 5,&all);
	printArr(Arr,all);
	return 0;
}*/