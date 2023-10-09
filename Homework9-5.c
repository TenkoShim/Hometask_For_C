#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* scanArr(size_t* Size_of_Arr) {
    int* arr = NULL;  // �������������� ��������� �� ������ ��� NULL
    int size = 0;     // �������� ������ �������
    int capacity = 0; // ������ ���������� ������ ��� �������
    int num;

    while (1) {
        printf("Enter element (0 for end): ");
        scanf("%d", &num);

        
        if (size >= capacity) {
            // ���� ������ ��������, ����������� ��� ������ � �������������� realloc
            capacity = (capacity == 0) ? 1 : capacity * 2; // ��������� ������
            arr = (int*)realloc(arr, capacity * sizeof(int));
            if (!arr) {
                perror("Error of memory");
                exit(EXIT_FAILURE);
            }
        }

        // ��������� ��������� ����� � ������
        arr[size] = num;
        size++;
        if (num == 0) {
            break; // ���� ������� 0, ��������� ����
        }
    }

    // ��������� ������ ������� �� ����������� ������� � �������������� realloc
    arr = (int*)realloc(arr, size * sizeof(int));
    *Size_of_Arr = size;
    if (!arr) {
        perror("Error of memory");
        exit(EXIT_FAILURE);
    }

    return arr;
}

int main() {
    size_t size = 0;
    int* numbers = scanArr(&size);

    printf("Your numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    free(numbers); // ����������� ������, ���������� ��� �������

    return 0;
}