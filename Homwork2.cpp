#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

double** IdentityMatrix(int size) {
    double** mrx = (double**)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++) {
        mrx[i] = (double*)malloc(size * sizeof(double));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                mrx[i][j] = 1.0;
            } else {
                mrx[i][j] = 0.0;
            }
        }
    }

    return mrx;
}

int compare(const void *a, const void *b) {
    int intA = *((int*)a);
    int intB = *((int*)b);

    return intA - intB;
}

int* sortArray(int* arr, int size, bool ascending) {
    int* arrsort = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrsort[i] = arr[i];
    }

    if (ascending) {
        qsort(arrsort, size, sizeof(int), compare);
    } else {
        qsort(arrsort, size, sizeof(int), compare);
        int temp;
        for (int i = 0; i < size / 2; i++) {
            temp = arrsort[i];
            arrsort[i] = arrsort[size - 1 - i];
            arrsort[size - 1 - i] = temp;
        }
    }

    return arrsort;
}

void printNumbers(int n) {
    if (n > 0) {
        printNumbers(n - 1);
        printf("%d ", n);
    }
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

double findRoot(double a, double b, double tolerance) {
    double c = (a + b) / 2.0;
    double fc = cos(pow(c, 5)) + pow(c, 4) - 345.3 * c - 23;

    if (fabs(b - a) < tolerance) {
        return c;
    }

    if (fabs(fc) < tolerance) {
        return c;
    }

    if (cos(pow(a, 5)) + pow(a, 4) - 345.3 * a - 23 * fc < 0) {
        return findRoot(a, c, tolerance);
    }

    return findRoot(c, b, tolerance);
}


int findClosestToAverage(int arr[], int size) {
    if (size <= 0) {
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    double average = (double)sum / size;

    int closest = arr[0];
    int minDifference = abs(arr[0] - average);

    for (int i = 1; i < size; i++) {
        int difference = abs(arr[i] - average);
        if (difference < minDifference) {
            closest = arr[i];
            minDifference = difference;
        }
    }

    return closest;
}

int hasDuplicates(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int size = 3; 
    double** identityMatrix = IdentityMatrix(size);

    printf("Единичная матрица %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%f ", identityMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(identityMatrix[i]);
    }
    free(identityMatrix);

    int size2 = 5;
    int arr[] = {3, 1, 4, 1, 5};
    bool ascending = true;
    int* sortedArr = sortArray(arr, size2, ascending);

    printf("Отсортированный массив:\n");
    for (int i = 0; i < size2; i++) {
        printf("%d ", sortedArr[i]);
    }
    printf("\n");

    free(sortedArr);

    int n;
    printf("Введите натуральное число n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Число должно быть натуральным.\n");
    } else {
        printf("Числа от 1 до %d: ", n);
        printNumbers(n);
        printf("\n");
    }

    const int size3 = 100000000;
    int* arr3 = (int*)malloc(size3 * sizeof(int));

    for (int i = 0; i < size3; i++) {
        arr3[i] = i;
    }

    int target3 = size3 - 1;

    clock_t start = clock();
    int linearResult = linearSearch(arr3, size3, target3);
    clock_t end = clock();
    double linearTime = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    int binaryResult = binarySearch(arr3, 0, size3 - 1, target3);
    end = clock();
    double binaryTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (linearResult != -1) {
        printf("Линейный поиск: Элемент %d найден на индексе %d, время выполнения: %f сек\n", target3, linearResult, linearTime);
    } else {
        printf("Линейный поиск: Элемент %d не найден, время выполнения: %f сек\n", target3, linearTime);
    }

    if (binaryResult != -1) {
        printf("Двоичный поиск: Элемент %d найден на индексе %d, время выполнения: %f сек\n", target3, binaryResult, binaryTime);
    } else {
        printf("Двоичный поиск: Элемент %d не найден, время выполнения: %f сек\n", target3, binaryTime);
    }

    free(arr3);

    int size4;
    printf("Введите размер массива: ");
    scanf("%d", &size4);

    if (size4 <= 0) {
        printf("Размер массива должен быть положительным.\n");
        return 1;
    }

    int* arr4 = (int*)malloc(size4 * sizeof(int));
    if (arr4 == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < size4; i++) {
        scanf("%d", &arr4[i]);
    }

    int closest = findClosestToAverage(arr4, size4);

    if (closest != -1) {
        printf("Элемент, наиболее близкий к среднему значению: %d\n", closest);
    } else {
        printf("Массив пуст.\n");
    }

    free(arr4);

    int size5 = 5;
    int arr5[] = {3, 1, 4, 1, 5};
    int hasDuplicatesResult = hasDuplicates(arr5, size5);

    if (hasDuplicatesResult) {
        printf("В массиве есть одинаковые элементы.\n");
    } else {
        printf("В массиве нет одинаковых элементов.\n");
    }

    return 0;
}

