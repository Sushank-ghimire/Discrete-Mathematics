# 📦 Space Complexity Cheatsheet

Space Complexity refers to the **total amount of memory** used by an algorithm, including input values, variables, data structures, and function call overhead. It is typically expressed as a function of the input size `n`.

---

## 📘 Components of Space Complexity

1. **Fixed Part**: Independent of input size.
   - Example: Constants, variables, pointers.
2. **Variable Part**: Depends on input size.
   - Example: Arrays, recursion stack, dynamic allocations.

---

## 🧮 Common Space Complexities

| Notation | Description                         | Example Code (in C)       |
| -------- | ----------------------------------- | ------------------------- |
| O(1)     | Constant space                      | Only fixed variables used |
| O(n)     | Linear space                        | Array of size n           |
| O(log n) | Logarithmic space (e.g., recursion) | Binary search             |
| O(n²)    | Quadratic space                     | 2D arrays                 |

---

## 🔹 Examples in C

### 1. **O(1) - Constant Space**

```c
#include <stdio.h>

void printSum(int a, int b) {
    int sum = a + b; // Only one variable used
    printf("Sum: %d\n", sum);
}
```

### 2. **O(n) - Linear Space**

```c
#include <stdio.h>

void storeElements(int n) {
    int arr[n]; // Space grows with n
    for(int i = 0; i < n; i++) arr[i] = i;
}
```

### 3. **O(log n) - Logarithmic Space (Recursion)**

```c
#include <stdio.h>

void binarySearch(int low, int high) {
    if (low > high) return;
    int mid = (low + high) / 2;
    binarySearch(low, mid - 1);     // Recursion uses log n stack space
    binarySearch(mid + 1, high);
}
```

### 4. **O(n²) - Quadratic Space**

```c
#include <stdio.h>

void createMatrix(int n) {
    int matrix[n][n]; // 2D array uses n² space
}
```

---

## 📌 Tips to Reduce Space Complexity

- Use variables instead of arrays when possible.
- Reuse variables.
- Use iterative solutions instead of recursion (tail recursion).
- Free dynamically allocated memory.

---

## 📋 Important Notes

- Input size is **not** counted in space complexity unless explicitly duplicated.
- Stack memory usage (like recursion) is counted.
- Memory-efficient algorithms are crucial for embedded and low-memory systems.

---

## 🔚 Conclusion

Space Complexity helps determine how much memory an algorithm uses. Optimize it along with time complexity for better-performing software.
