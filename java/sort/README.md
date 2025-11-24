## Java / Sorting

This directory contains Java implementations of sorting algorithms.
It follows the same I/O flow as the C versions (enter count → enter elements → print sorted result).

### Files

### selection_sort.java

Algorithm: Selection Sort

Idea: At each step, find the minimum in the remaining range and swap with the current position

### Time: O(N²) / Space: O(1)

I/O:

Input: number of elements N (1–100), followed by N integers

Output: the array before sorting, then the array after sorting (line break after every 10 numbers)

### bubble_sort.java

Algorithm: Bubble Sort

Idea: Repeatedly compare adjacent elements and “bubble” larger ones to the right

Time: O(N²) / Space: O(1)

I/O:

Input: number of elements N (1–100), followed by N integers

Output: the array before sorting, then the array after sorting (line break after every 10 numbers)

How to Run
### Navigate
cd java/sort

### Compile
javac selection_sort.java
javac bubble_sort.java

### Run
java selection_sort
### Enter the number of elements to sort(1~100): 5
### Enter 5 integers:
3 1 4 1 5
### ... outputs follow

java bubble_sort
### Enter the number of elements (1 ~ 100): 5
### Enter 5 integer values:
3 1 4 1 5
... outputs follow
