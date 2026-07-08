#include <stdio.h>

void findMeanAndMedian(float arr[], int n) {
    // 1. Calculate Mean using a for loop
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    float mean = sum / n;

    // 2. Sort the array using loops (Bubble Sort)
    // This is required to find the median
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 3. Calculate Median
    float median;
    if (n % 2 != 0) {
        // Odd number of elements: take the middle element
        median = arr[n / 2];
    } else {
        // Even number of elements: average of the two middle elements
        median = (arr[(n / 2) - 1] + arr[n / 2]) / 2.0;
    }

    // Print the results
    printf("Mean   = %.2f\n", mean);
    printf("Median = %.2f\n", median);
}

int main() {
    // Test Case 1: Odd number of elements
    float dataset1[] = {12.0, 3.0, 5.0, 7.0, 19.0};
    int n1 = sizeof(dataset1) / sizeof(dataset1[0]);
    
    printf("Dataset 1:\n");
    findMeanAndMedian(dataset1, n1);
    
    printf("\n");

    // Test Case 2: Even number of elements
    float dataset2[] = {12.0, 3.0, 5.0, 7.0, 19.0, 1.0};
    int n2 = sizeof(dataset2) / sizeof(dataset2[0]);
    
    printf("Dataset 2:\n");
    findMeanAndMedian(dataset2, n2);

    return 0;
}