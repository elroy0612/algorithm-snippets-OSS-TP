# algorithm-snippets-OSS-TP

This repository collects **frequently used algorithm code snippets** implemented in multiple languages.  
The goal is to organize example code by algorithm topics such as sorting, searching, DP, graphs, etc.

> Goal: **“Create an algorithm code collection that you can quickly reuse when needed.”**
---

## Repository Structure

Directories are divided by language → then by algorithm topic.

Example:

```
algorithm-snippets-OSS-TP/
  ├── c/
  │   ├── sort/
  │   │   └── merge_sort.c
  │   └── dp/
  │       └── lis.c
  ├── java/
  │   └── recursion/
  │       └── fibonacci.java
  └── python/
      └── greedy/
          └── coin_change.py
```

- Language folders: `c`, `java`, `python`
- Example topic folders: `sort`, `dp`, `graph`, `greedy`, `recursion`, `string`, `tree`

---

## Usage

1. Clone the repository

```bash
git clone https://github.com/elroy0612/algorithm-snippets-OSS-TP.git
cd algorithm-snippets-OSS-TP
```

2. Move to the language/topic folder you want and check the code

```bash
cd python/dp
```

3. Example commands to run by language

- **C**

  ```bash
  gcc merge_sort.c -o merge_sort
  ./merge_sort
  ```

- **Java**

  ```bash
  javac fibonacci.java
  java fibonacci
  ```

- **Python**

  ```bash
  python coin_change.py
  ```

---

## File Naming & Header Comment Rules

### 1) File name

- Format: `problemname_description.extension`
- Use only lowercase letters + underscores (`_`)

Examples:

- `two_sum_bruteforce.py`
- `binary_search.c`
- `boj_11053_lis.cpp`
- `merge_sort.java`

### 2) Header comment example

**C / Java**

```c
/*
 * Title   : Longest Increasing Subsequence
 * Problem : BOJ 11053
 * Category: DP
 * Language: C
 * Author  : (Author name or GitHub ID)
 * Note    : O(N^2) DP implementation
 */
```

**Python**

```python
"""
Title   : Two Sum
Problem : LeetCode 1
Category: Hash / Brute force
Language: Python
Author  : (Author name or GitHub ID)
Note    : O(N) hashmap solution
"""
```

---

## Contributing

1. **Choose a language/topic folder**
   - Example: Python DP problem → `python/dp/`
   - Example: C sorting example → `c/sort/`

2. **Follow the file naming rule**
   - Example: `boj_11053_lis.py`, `merge_sort.c`

3. **Add metadata in the header comment**
   - Include Title, Problem, Category, Language, Author, Note, etc.

4. **Remove unnecessary debug output**
   - Remove temporary `print`, `cout`, `printf`, etc.

5. **Commit message examples**

```text
[python] add LIS solution for BOJ 11053
[c] implement merge sort example
[java] add recursion fibonacci example
```

> Pattern: `[language] verb + description`

---

## Future Plans

- Fill in basic algorithms for sorting, searching, recursion, DP, and graphs in each language  
- For the same problem, **collect multiple languages / multiple approaches (O(N^2), O(N log N), etc.)**  

---

## License

This repository will be distributed under the MIT License.  
See the `LICENSE` file for more details.

---

## References

- Yong Ju Jung, *Introduction to C Programming - Passing Arrays to Functions*
- Won Kim, *Program Patterns - Recursion, Update/Copy/Move Patterns*
- bugrasarikaya, *bellman-ford-algorithm*
