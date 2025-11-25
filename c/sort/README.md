
# C / Sort

This directory contains implementations of basic **Sorting Algorithms** written in C.  
The following algorithms are currently included:

- **Bubble Sort**
- **Selection Sort**

Each program reads N integers from the user, sorts them in **ascending order**, and prints the result.

---

## Implemented Algorithms

### 1) Bubble Sort — `bubble_sort.c`
- **Algorithm:** Bubble Sort  
- **Time Complexity:** O(N²)  
- **Description:**  
  Repeatedly compares adjacent elements and swaps them if they are in the wrong order.  
- **Features:**  
  - Accepts up to 100 integers  
  - Sorts in ascending order  
  - Prints output with a newline after every 10 numbers  

---

### 2) Selection Sort — `selection_sort.c`
- **Algorithm:** Selection Sort  
- **Time Complexity:** O(N²)  
- **Description:**  
  Finds the minimum value in the unsorted portion of the array and swaps it with the current position.  
- **Features:**  
  - Accepts up to 100 integers  
  - Prints the array before and after sorting  
  - Formats output with a newline every 10 numbers  

---

## How to Run

### Navigate
```bash
cd c/sort
```

### Compile and Execute
```
gcc bubble_sort.c -o bubble
./bubble

gcc selection_sort.c -o selection
./selection
```

#### Enter the number of elements to sort(1~100): 5
#### Enter 5 integers:
 9
 3
 4
 1
 8
#### Before sort:
#### 9		3		4		1		8
#### Sorted result:
#### 1		3		4		8		9
