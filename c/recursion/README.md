
# C / Recursion

This directory contains implementations of basic **Recursive Algorithms** written in C.  
The following algorithms are currently included:

- **Factorial (N!)**
- **Power Function (N^P)**

Each program reads input from the user and computes the result using **pure recursion**.

---

## Implemented Algorithms

### 1) Factorial — `factorial.c`
- **Algorithm:** Recursive Factorial  
- **Time Complexity:** O(N)  
- **Description:**  
  Computes the factorial of a non-negative integer using a simple recursive definition.  
- **Supports:**  
  - Valid input range: **0 to 20**  
  - Uses `unsigned long long` (max ~20!)  
  - Handles invalid input (negative numbers, overflow)  

#### How it works
- Base Case: **0! = 1**  
- Recursive Case: **n! = n × (n-1)!**

---

### 2) Power Function — `power.c`
- **Algorithm:** Recursive Power Function  
- **Time Complexity:** O(|P|)  
- **Description:**  
  Computes \( N^P \) using recursion, supporting positive, zero, and negative exponents.  
- **Supports:**  
  - Integer exponent P (can be negative)  
  - Floating-point base N  
  - Computes:  
    - Positive power → `N * power(N, P - 1)`  
    - Zero power → `1`  
    - Negative power → `1 / power(N, -P)`  

---

## How to Run
  
### Navigate

```bash
cd c/recursion
```

  

### Compile and Execute

```bash
gcc factorial.c -o factorial
./factorial

gcc power.c -o power
./power
```

---
## Example Output

### Factorial Example

Enter an integer to calculate its factorial  (0~20): 6  
6! = 720

---

### Power Example

N^P  (P  must  be  an  integer)  
Enter  the  base  number  (N):  2  
Enter  the  exponent  (P):  3
2^3  is  8
