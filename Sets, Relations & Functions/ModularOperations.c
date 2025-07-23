// Programs to perform operations with large integers by breaking down them into set of small integers.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

// Helper to remove leading zeros
void removeZeros(char *str) {
    int i = 0;
    while (str[i] == '0' && str[i + 1] != '\0') i++;
    if (i > 0) memmove(str, str + i, strlen(str) - i + 1);
}

// Reverse a string
void reverse(char *str) {
    int len = strlen(str), i;
    for (i = 0; i < len / 2; i++) {
        char t = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = t;
    }
}

// Add large numbers
void add(char num1[], char num2[], char result[]) {
    char temp[MAX] = "";
    int carry = 0, i = 0;

    reverse(num1);
    reverse(num2);

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxlen = (len1 > len2) ? len1 : len2;

    for (i = 0; i < maxlen || carry; i++) {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (i < len2) ? num2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        temp[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    temp[i] = '\0';

    reverse(temp);
    strcpy(result, temp);
}

// Subtract large numbers (assume num1 >= num2)
void subtract(char num1[], char num2[], char result[]) {
    char temp[MAX] = "";
    int borrow = 0, i = 0;

    reverse(num1);
    reverse(num2);

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    for (i = 0; i < len1; i++) {
        int digit1 = num1[i] - '0';
        int digit2 = (i < len2) ? num2[i] - '0' : 0;

        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else
            borrow = 0;

        temp[i] = (digit1 - digit2) + '0';
    }
    temp[i] = '\0';

    reverse(temp);
    removeZeros(temp);
    strcpy(result, temp);
}

// Multiply large numbers
void multiply(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1), i, j;
    int len2 = strlen(num2);
    int *res = calloc(len1 + len2, sizeof(int));
    char temp[MAX] = "";

    for (i = len1 - 1; i >= 0; i--) {
        for (j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + res[p2];

            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }

    int k = 0, started = 0;
    for (i = 0; i < len1 + len2; i++) {
        if (!started && res[i] == 0) continue;
        started = 1;
        temp[k++] = res[i] + '0';
    }

    if (k == 0)
        temp[k++] = '0';
    temp[k] = '\0';

    strcpy(result, temp);
    free(res);
}

// Check if num1 < num2
int isSmaller(char *num1, char *num2) {
    removeZeros(num1);
    removeZeros(num2);
    int len1 = strlen(num1), len2 = strlen(num2);
    if (len1 != len2)
        return len1 < len2;
    return strcmp(num1, num2) < 0;
}

int main() {
    int choice;
    char num1[MAX], num2[MAX], result[MAX];

    do {
        printf("\n====== Large Integer Operations Menu ======\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear buffer

        if (choice >= 1 && choice <= 3) {
            printf("Enter first large number: ");
            fgets(num1, MAX, stdin);
            num1[strcspn(num1, "\n")] = 0;

            printf("Enter second large number: ");
            fgets(num2, MAX, stdin);
            num2[strcspn(num2, "\n")] = 0;

            removeZeros(num1);
            removeZeros(num2);
        }

        switch (choice) {
            case 1:
                add(num1, num2, result);
                printf("Result: %s\n", result);
                break;
            case 2:
                if (isSmaller(num1, num2)) {
                    subtract(num2, num1, result);
                    printf("Result: -%s\n", result);
                } else {
                    subtract(num1, num2, result);
                    printf("Result: %s\n", result);
                }
                break;
            case 3:
                multiply(num1, num2, result);
                printf("Result: %s\n", result);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

