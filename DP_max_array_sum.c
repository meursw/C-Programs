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

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* make_array(const unsigned int);
int dp_max_sum(const int*, const unsigned int, int*, int*);
void print_array(const int*, int);

int main() {
    srand(time(0));

    unsigned int size = rand() % 10 + 1;
    int *array = make_array(size);
    int *parent_array = (int*)malloc(sizeof(int)*size);

    printf("Produced array: \n");
    print_array(array, size);

    int start_of_seq = 0;

    int max_sum = dp_max_sum(array, size, parent_array, &start_of_seq);

    printf("Maximum sum of elements in the array: %d\n", max_sum);
    printf("The sequence of elements is:");

    printf("```\n");
    print_array(parent_array,size);
    printf("%d",start_of_seq);

    free(array);
    free(parent_array);
}

int* make_array(unsigned int size) {
    int *arr = (int*)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 64 - 32;
    }

    return arr;
}

void print_array(const int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int dp_max_sum(const int *arr, const unsigned int size, int *parent_array, int* sos) {
    int *solutions = (int*)malloc(sizeof(int)*size);
    solutions[0] = arr[0];
    parent_array[0] = 0;

    int max = solutions[0];

    for(int i = 1; i < size; i++) {

        solutions[i] = (
            solutions[i-1] + arr[i] > arr[i] ? 
            solutions[i-1] + arr[i] : 
            arr[i]
        );

        parent_array[i] = (
            solutions[i-1] + arr[i] > arr[i] ? 
            parent_array[i-1] : 
            i
        );

        if(solutions[i] > max) {
            max = solutions[i];
            *sos = i;
        }

    }

    free(solutions);
    return max;
}