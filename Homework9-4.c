#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int** createPascalTriangle(size_t len1) {
	int** triangle = (int**)malloc(len1 * sizeof(int*));
	for (size_t i = 0; i < len1; i++) {
		triangle[i] = (int*)malloc((i+1) * sizeof(int));
	}
	return triangle;
}

void fillPascalTriangle(int** triangle, int len) {
    for (int i = 0; i < len; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}
void printPascalTriangle(int**  triangle, size_t len) {
	for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}
void freePascalTriangle(int** triangle, size_t len) {
    for (int i = 0; i < len; i++) {
        free(triangle[i]);
    }
    free(triangle);
}
int main() {
    int numRows;
    printf("Enter count of columns : ");
    scanf("%d", &numRows);
    int** pascalTriangle = createPascalTriangle(numRows);
    fillPascalTriangle(pascalTriangle, numRows);
    printf("Triangale of Pascal:\n");
    printPascalTriangle(pascalTriangle, numRows);

    freePascalTriangle(pascalTriangle, numRows);

    return 0;
}
