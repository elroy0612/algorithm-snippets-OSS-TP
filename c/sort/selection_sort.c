/*
 * Title    : Selection Sort
 * Problem  : Sort N integers in ascending order
 * Category : sorting
 * Language : C
 * Author   : YeongWoong Kim
 * note     : Reads N(1~100) integers, sorts them in ascending order, and prints the result.
 */

#include <stdio.h>
#define MAX_SIZE 100

// Function prototype
void sort(int array[], int size);
void print_array(int array[], int size);

int main() {
    int size;

    // Ask the user for the number of elements
    printf("Enter the number of elements to sort(1~100): ");
    scanf_s("%d", &size);

    // Validate size
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }

    int array[MAX_SIZE];

    // Input elements from the user
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &array[i]);
    }

    // Print before sorting
    printf("\nBefore sort:\n");
    print_array(array, size);

    // Call selection sort function
    sort(array, size);

    // Print sorted result
    printf("\nSorted result:\n");
    print_array(array, size);

    return 0;
}

// Selection sort function
void sort(int a[], int size) {
    int i, j, min, position, temp;

    // Loop for each position in the array
    for (j = 0; j < size; j++) {
        min = a[j];
        position = j;

        // Find the minimum value in the remaining array
        for (i = j; i < size; i++) {
            if (a[i] < min) {
                min = a[i];
                position = i;
            }
        }

        // Swap the found minimum with the current position
        temp = a[position];
        a[position] = a[j];
        a[j] = temp;
    }
}

void print_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", a[i]);
        if (i != 0 && (i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}
