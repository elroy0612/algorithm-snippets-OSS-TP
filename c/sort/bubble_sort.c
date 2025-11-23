/*
 * Title    : Bubble Sort
 * Problem  : Sort N integers in ascending order
 * Category : sorting
 * Language : C
 * Author   : YeongWoong Kim
 * note     : Reads N(1~100) integers, sorts them in ascending order, and prints the result.
 */

#include <stdio.h>
#define MAX_SIZE 100   // maximum number of elements allowed

// function prototypes
void bubblesort(int* array, const int size);   // sort array in ascending order
void swap(int* element1ptr, int* element2ptr);   // swap two integer values

int main() {
    int a[MAX_SIZE];   // array to store input values
    int size;   // actual number of elements
    int i;

    // read number of elements from the user
    printf("Enter the number of elements (1 ~ %d): ", MAX_SIZE);
    scanf_s("%d", &size);

    // validate size
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }

    // read array values from the user
    printf("Enter %d integer values:\n", size);
    for (i = 0; i < size; i++) {
        scanf_s("%d", &a[i]);
    }

    // print original array
    printf("Data items in original order\n");
    for (i = 0; i < size; i++) {
        printf("%d\t", a[i]);
        if (i != 0 && (i + 1) % 10 == 0)
            printf("\n");   // print a newline after every 10 numbers
    }

    // sort the array
    bubblesort(a, size);

    // print sorted array
    printf("\nData items in ascending order\n");
    for (i = 0; i < size; i++) {
        printf("%d\t", a[i]);
        if (i != 0 && (i + 1) % 10 == 0)
            printf("\n");
    }

    printf("\n");
    return 0;   // successful termination
}

// sort an array of integers using the bubble sort algorithm
void bubblesort(int* array, const int size) {
    int pass;
    int j;

    // outer loop controls the number of passes
    for (pass = 0; pass < size - 1; pass++) {
        // inner loop compares adjacent elements
        for (j = 0; j < size - 1; j++) {
            // swap adjacent elements if they are out of order
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    } 
}

// swap the values pointed to by element1ptr and element2ptr
void swap(int* element1ptr, int* element2ptr) {
    int hold = *element1ptr;
    *element1ptr = *element2ptr;
    *element2ptr = hold;
}
