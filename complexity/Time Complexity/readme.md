# ⏱️ Time Complexity in Algorithms

## 📖 Introduction

**Time Complexity** is a theoretical concept that describes how the runtime of an algorithm increases with the size of the input (`n`). It helps evaluate the efficiency of algorithms and their ability to scale with large inputs.

---

## 📌 Why Study Time Complexity?

- To predict the performance of an algorithm.
- To choose the most efficient solution.
- To optimize programs for speed.
- To compare different approaches to the same problem.

---

## 🧠 Basic Idea

If an algorithm takes more steps as input size increases, it has higher time complexity.

Example:

- Input size: `n`
- Steps taken: `n * n` ⇒ **O(n²)** (Quadratic time)

---

## 🧮 Common Time Complexities (Big-O Notation)

| Big-O      | Name              | Example                          |
| ---------- | ----------------- | -------------------------------- |
| O(1)       | Constant time     | Accessing array element          |
| O(log n)   | Logarithmic time  | Binary Search                    |
| O(n)       | Linear time       | Traversing array                 |
| O(n log n) | Linearithmic time | Merge Sort, Quick Sort (avg)     |
| O(n²)      | Quadratic time    | Bubble Sort, Insertion Sort      |
| O(2ⁿ)      | Exponential time  | Recursive Fibonacci              |
| O(n!)      | Factorial time    | Solving Traveling Salesman Brute |

---

## 🔢 How to Calculate Time Complexity

Analyze the number of steps or iterations a program takes based on input size `n`.

### Steps:

1. **Count operations inside loops**
2. **Nested loops multiply time**
3. **Ignore constants and low-order terms**
4. **Use Big-O notation to generalize**

---

## 🧪 Examples in C

### ✅ O(1) - Constant Time

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("First element: %d\n", arr[0]); // Always takes 1 step
    return 0;
}
```

---

### ✅ O(n) - Linear Time

```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]); // Runs 5 times → O(n)
    }
    return 0;
}
```

---

### ✅ O(n²) - Quadratic Time

```c
#include <stdio.h>

int main() {
    int n = 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d,%d) ", i, j); // n * n times → O(n²)
        }
        printf("\n");
    }
    return 0;
}
```

---

### ✅ O(log n) - Logarithmic Time (Binary Search)

```c
#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int result = binarySearch(arr, 6, 10);
    printf("Found at index: %d\n", result);
    return 0;
}
```

---

## ⚙️ Tips for Analyzing Time Complexity

- **Single loop** → O(n)
- **Nested loop** → Multiply the time → O(n²)
- **Divide & Conquer** (Binary Search, Merge Sort) → O(log n) or O(n log n)
- **Recursive** → Use **recurrence relations** to analyze
- **Ignore constants** → O(3n) = O(n)

---

## 📚 Resources

- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- CLRS: _Introduction to Algorithms_
- GeeksforGeeks: Time Complexity Tutorials

---

## ✅ Summary

| Notation   | Behavior Example          |
| ---------- | ------------------------- |
| O(1)       | Accessing an element      |
| O(n)       | Loop through `n` elements |
| O(n²)      | Nested loops              |
| O(log n)   | Binary search             |
| O(n log n) | Efficient sorts           |
| O(2ⁿ)      | Recursive brute-force     |

Understanding time complexity is key to writing scalable and optimized code!

---
