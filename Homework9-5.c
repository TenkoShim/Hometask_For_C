#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* scanArr(size_t* Size_of_Arr) {
    int* arr = NULL;  // Инициализируем указатель на массив как NULL
    int size = 0;     // Исходный размер массива
    int capacity = 0; // Размер выделенной памяти для массива
    int num;

    while (1) {
        printf("Enter element (0 for end): ");
        scanf("%d", &num);

        
        if (size >= capacity) {
            // Если массив заполнен, увеличиваем его размер с использованием realloc
            capacity = (capacity == 0) ? 1 : capacity * 2; // Удваиваем размер
            arr = (int*)realloc(arr, capacity * sizeof(int));
            if (!arr) {
                perror("Error of memory");
                exit(EXIT_FAILURE);
            }
        }

        // Добавляем введенное число в массив
        arr[size] = num;
        size++;
        if (num == 0) {
            break; // Если введено 0, завершаем ввод
        }
    }

    // Уменьшаем размер массива до актуального размера с использованием realloc
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

    free(numbers); // Освобождаем память, выделенную для массива

    return 0;
}