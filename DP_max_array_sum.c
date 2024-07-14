#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
Basic dynamic programming problem.
    Given an array of elements (integers) find the maximum consecutive sum inside the array.

How to solve the problem:
    1) Define the problems: We split the problems into smaller arrays from element 1-j (where j = {1,...,n})
    Basically we approach the problem from a bottom up approach, solving smaller problems first (sub-arrays)
    and from these solutions we can construct the final solution. (An integer, the maximum sum.)
    
    2) Define the choices: In each iteration we may choose to include the solution of the previous problem, continuing the 
    list of numbers from the last index, or starting anew, from index j.

    3) Define the recursive relation: This is how we choose from the choices mentioned above. We take the max between the 
    solution of the previous problem and the value of the element at index j.
*/

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