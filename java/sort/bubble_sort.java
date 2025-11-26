/*
 * Title    : Bubble Sort
 * Problem  : Sort N integers in ascending order
 * Category : sorting
 * Language : Java
 * Author   : Yeonjun Cho
 * Note     : Reads N(1~100) integers, sorts them in ascending order, and prints the result.
 */

import java.util.Scanner;

class BubbleSort {
    static final int MAX_SIZE = 100;

    // Bubble sort with reduced inner loop (size - 1 - pass)
    static void bubbleSort(int[] array, int size) {
        for (int pass = 0; pass < size - 1; pass++) {
            for (int j = 0; j < size - 1 - pass; j++) {  // <- shrink range each pass
                if (array[j] > array[j + 1]) {
                    swap(array, j, j + 1);
                }
            }
        }
    }

    static void swap(int[] array, int i, int j) {
        int hold = array[i];
        array[i] = array[j];
        array[j] = hold;
    }

    static void printArray(int[] array, int size) {
        for (int i = 0; i < size; i++) {
            System.out.print(array[i] + "\t");
            if (i != 0 && (i + 1) % 10 == 0) System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements (1 ~ " + MAX_SIZE + "): ");
        int size = sc.nextInt();

        if (size < 1 || size > MAX_SIZE) {
            System.out.println("Invalid size.");
            sc.close();
            return;
        }

        // allocate exact size to avoid wasting space
        int[] a = new int[size];

        System.out.println("Enter " + size + " integer values:");
        for (int i = 0; i < size; i++) {
            a[i] = sc.nextInt();
        }

        System.out.println("Data items in original order");
        printArray(a, size);

        bubbleSort(a, size);

        System.out.println("\nData items in ascending order");
        printArray(a, size);

        sc.close();
    }
}
