#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* make_array(unsigned int);
int dp_max_sum(int*, unsigned int);

int main() {
    srand(time(0));

    unsigned int size = rand() % 16 + 1;
    int *array = make_array(size);

    int max_sum = dp_max_sum(array,size);

    printf("Maximum sum of elements in the array: %d", max_sum);
}

int* make_array(unsigned int size) {
    int *arr = (int*)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 32 + 1;
    }

    return arr;
}

int dp_max_sum(int *arr, unsigned int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}