#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int read_int() {
	int a;
	scanf("%d", &a);
	return a;
}
void printArr(int arr[], size_t len) {
	for (size_t i = 0; i < len; i++) {
		printf("%p\n", arr[i]);
	}
}
void swap(int* pa, int* pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}
void printArr_2D(int arr[], size_t len1, size_t len2) {
	for (size_t i = 0; i < len1; i++) {
		for (size_t j = 0; j < len2; j++) {
			printf("%d ", arr[(i * len2) + j]);
		}
		printf("\n");
	}
}
int main() {
	int arr[4][4] = { {1,1,1,1},{2,2,2,2}, {3,3,3,3}, {4,4,4,4} };
	printArr_2D(arr, 4, 4);
	//revert_diognale
	int z = 4 - 1;
	int lenz = 4 - 4 / 2;
	int k=4-2;
	int k_;
	for (size_t i = 0; i < lenz; i++) {
		k_ = k - i;
		for (size_t j = 1+i; j < 4; j++) {
			swap(&arr[i][j], &arr[z][k_]);
			k_--;
		}
		z--;
	}
	printf("\n");
	printArr_2D(arr, 4, 4);
	return 0;

}