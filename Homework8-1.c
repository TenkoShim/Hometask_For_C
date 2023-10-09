#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int read_int() {
	int a;
	scanf("%d", &a);
	return a;
}
void swap(int* pa, int* pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}
int length_number(int x) {
	int count = 0;
	while (x) {
		x /= 10;
		count++;
	}
}
void number_to_Arr(int a, int zar[], size_t len) {
	int i = 0;
	while (a) {
		zar[i] = a % 10;
		a /= 10;
		i++;
	}
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

void revertArr(int arr[], size_t len) {
	int z = len - 1;
	int lenz = len - len / 2;
	for (size_t i = 0; i < lenz; i++) {
		swap(&arr[i], &arr[z]);
		z--;
	}

}
int maxInArr(int arr[], size_t len) {
	int max = 0;
	for (size_t i = 0; i < len; i++) {
		if (max <= arr[i]) {
			max = arr[i];
		}
	}
	return max;
}
int findInArr(int arr[], size_t len, int x) {
	for (size_t i = 0; i < len; i++) {
		if (arr[i] == x) {
			return &arr[i];
		}
	}
	return NULL;
}
void extractDigits(int arr[], size_t len, int x) {
	int lenx = length_number(x);
	void* ptr = malloc(lenx * sizeof(int));
	int* zar = (int*)ptr;
	number_to_Arr(x, zar, lenx);
	revertArr(zar, lenx);
	for (size_t i = 0; i < lenx; i++) {
		arr[i] = zar[i];
	}
	printArr(arr, len);
	free(zar);
}
int compareArrays(int arr1[], int arr2[], size_t len1, size_t len2) {
	size_t test = len1 < len2 ? len1 : len2;
	size_t i = 0;
	for (i; i < test; i++) {
		if (arr1[i] > arr2[i]) return 1;
		if (arr1[i] < arr2[i]) return -1;
	}
	if (len1 < len2) return -1;
	if (len1 > len2) return 1;
	return 0;
}
int main() {
	//Please bigger than 10 because of task 6
	printf("Enter n-->");
	int len = read_int();
	void* ptr = malloc(len * sizeof(int));
	int* arr = (int*)ptr;
	printf("Your array before scanArr:\n");
	printArr(arr, len);
	printf("Enter elements:\n");
	scanArr(arr, len);
	printf("After scanArr\n");
	printArr(arr, len);
	revertArr(arr, len);
	printf("After revertArr\n");
	printArr(arr, len);
	maxInArr(arr, len);
	printf("Enter your X=");
	int x = read_int();
	printf("Place of x in array ->%d\n", findInArr(arr, len, x));
	printf("Enter you Digit->");
	int Digit = read_int();
	extractDigits(arr, len, Digit);
	//Array for exercise
	printf("Enter length of your array one=");
	int len1 = read_int();
	void* ptr1 = malloc(len1 * sizeof(int));
	int* arr1 = (int*)ptr1;
	printf("Enter elements of array one:\n");
	scanArr(arr1, len1);
	printf("Result of your work = %d", compareArrays(arr, arr1, len, len1));
	free(arr1);
	free(arr);
	return 0;

}