/*
 * Title    : Selection Sort
 * Problem  : Sort N integers in ascending order
 * Category : sorting
 * Language : Java
 * Author   : Yeonjun Cho
 * Note     : Reads N(1~100) integers, sorts them in ascending order, and prints the result.
 */

import java.util.Scanner;

public class SelectionSort {
    static final int MAX_SIZE = 100;

    // Selection sort
    static void sort(int[] array, int size) {
        for (int j = 0; j < size; j++) {
            int min = array[j];
            int pos = j;

            for (int i = j; i < size; i++) {
                if (array[i] < min) {
                    min = array[i];
                    pos = i;
                }
            }

            int tmp = array[pos];
            array[pos] = array[j];
            array[j] = tmp;
        }
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

        System.out.print("Enter the number of elements to sort(1~100): ");
        int size = sc.nextInt();

        if (size < 1 || size > MAX_SIZE) {
            System.out.println("Invalid size.");
            return;
        }

        // Allocate exactly as many elements as needed (saves memory)
        int[] array = new int[size];

        System.out.println("Enter " + size + " integers:");
        for (int i = 0; i < size; i++) {
            array[i] = sc.nextInt();
        }

        System.out.println("\nBefore sort:");
        printArray(array, size);

        sort(array, size);

        System.out.println("\nSorted result:");
        printArray(array, size);

        sc.close();
    }
}
