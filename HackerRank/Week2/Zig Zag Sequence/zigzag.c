#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int t;
    scanf("%d", &t);  // number of test cases

    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];

        // Read array
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Step 1: Sort the array (simple bubble sort here)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    swap(&arr[i], &arr[j]);
                }
            }
        }

        // Step 2: Find the middle element
        int mid = (n - 1) / 2;

        // Step 3: Swap middle with last
        swap(&arr[mid], &arr[n - 1]);

        // Step 4: Reverse from mid+1 to n-2
        int start = mid + 1, end = n - 2;
        while (start <= end) {
            swap(&arr[start], &arr[end]);
            start++;
            end--;
        }

        // Print result
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
