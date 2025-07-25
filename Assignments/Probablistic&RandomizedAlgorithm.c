#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 1. Pigeonhole Principle
void pigeonhole_demo(int items, int boxes) {
    int result = (items + boxes - 1) / boxes;
    printf("Minimum number of items in any one box is at least: %d\n", result);
}

// 2. Randomized Algorithm: Find approximate max using random comparisons
int randomized_max(int *arr, int n) {
    int trials = 10, i;
    int max = arr[rand() % n];
    for (i = 1; i < trials; i++) {
        int randIndex = rand() % n;
        if (arr[randIndex] > max)
            max = arr[randIndex];
    }
    return max;
}

// 3. Expected Value (of a fair dice)
double expected_value_dice() {
    return (1 + 2 + 3 + 4 + 5 + 6) / 6.0;
}

// 4. Variance (of a fair dice)
double variance_dice() {
    double mean = expected_value_dice();
    double sum = 0;
    int i;
    for (i = 1; i <= 6; i++) {
        sum += pow(i - mean, 2);
    }
    return sum / 6.0;
}

// 5. Discrete Probability: Coin flip simulation
void probability_coin_flip(int trials) {
    int heads = 0, i;
    for (i = 0; i < trials; i++) {
        if (rand() % 2 == 0)
            heads++;
    }
    printf("Heads: %d, Tails: %d\n", heads, trials - heads);
    printf("Estimated P(Heads) = %.2f\n", (double)heads / trials);
}

// Menu
void menu() {
    printf("\n===== Discrete Structures - Unit 5 Menu =====\n");
    printf("1. Pigeonhole Principle (min items in one box)\n");
    printf("2. Randomized Max Element Finder\n");
    printf("3. Expected Value of Dice Roll\n");
    printf("4. Variance of Dice Roll\n");
    printf("5. Coin Flip Simulation (Discrete Probability)\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, items, boxes, size, trials, i;
    int arr[100];

    srand(time(NULL)); // Seed random number generator

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of items and boxes: ");
                scanf("%d %d", &items, &boxes);
                pigeonhole_demo(items, boxes);
                break;

            case 2:
                printf("Enter array size: ");
                scanf("%d", &size);
                printf("Enter %d elements:\n", size);
                for (i = 0; i < size; i++)
                    scanf("%d", &arr[i]);
                printf("Randomized Max = %d\n", randomized_max(arr, size));
                break;

            case 3:
                printf("Expected value of a fair dice = %.2f\n", expected_value_dice());
                break;

            case 4:
                printf("Variance of a fair dice = %.2f\n", variance_dice());
                break;

            case 5:
                printf("Enter number of coin flip trials: ");
                scanf("%d", &trials);
                probability_coin_flip(trials);
                break;

            case 6:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

