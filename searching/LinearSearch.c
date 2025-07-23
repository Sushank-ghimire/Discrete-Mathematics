#include <stdio.h>

// Recursive power: a^n
long long power(int a, int n) {
    if (n == 0) return 1;
    return a * power(a, n - 1);
}

// Recursive modular exponentiation: b^n mod m
long long modPower(long long b, long long n, long long m) {
    if (n == 0) return 1;
    long long half = modPower(b, n / 2, m);
    long long res = (half * half) % m;
    if (n % 2 == 1)
        res = (res * b) % m;
    return res;
}

// Recursive linear search
int linearSearch(int arr[], int size, int key, int index) {
    if (index >= size) return -1;
    if (arr[index] == key) return index;
    return linearSearch(arr, size, key, index + 1);
}

int main() {
    int choice;

    do {
        printf("\n===== Recursive Operations Menu =====\n");
        printf("1. Compute a^n\n");
        printf("2. Compute b^n mod m\n");
        printf("3. Recursive Linear Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int a, n;
            printf("Enter base (a): ");
            scanf("%d", &a);
            printf("Enter exponent (n): ");
            scanf("%d", &n);
            printf("Result: %lld\n", power(a, n));
        }

        else if (choice == 2) {
            long long b, n, m;
            printf("Enter base (b): ");
            scanf("%lld", &b);
            printf("Enter exponent (n): ");
            scanf("%lld", &n);
            printf("Enter modulus (m): ");
            scanf("%lld", &m);
            printf("Result: %lld\n", modPower(b, n, m));
        }

        else if (choice == 3) {
            int arr[100], n, key, i;
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter %d elements:\n", n);
            for (i = 0; i < n; i++)
                scanf("%d", &arr[i]);
            printf("Enter key to search: ");
            scanf("%d", &key);

            int index = linearSearch(arr, n, key, 0);
            if (index == -1)
                printf("Key not found.\n");
            else
                printf("Key found at index: %d\n", index);
        }

        else if (choice == 4) {
            printf("Exiting program.\n");
        }

        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

