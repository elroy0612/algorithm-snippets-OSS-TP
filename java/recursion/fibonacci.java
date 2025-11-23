/*
 * Title   : Fibonacci Sequence (Recursion)
 * Problem : Example snippet
 * Category: Recursion
 * Language: Java
 * Author  : (Author name or GitHub ID)
 * Note    : Simple recursive implementation (O(2^N))
 */

import java.util.Scanner;

class fibonacci {

    public static long fib(int n) {
        if (n <= 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter n (a non-negative integer): ");
        int n = scan.nextInt();

        System.out.println("F(" + n + ") = " + fib(n));

        System.out.println("Fibonacci numbers from 0 to " + n + ":");
        for (int i = 0; i <= n; i++) {
            System.out.print(fib(i));
            if (i < n) {
                System.out.print(" ");
            }
        }
        System.out.println();

    }

}

