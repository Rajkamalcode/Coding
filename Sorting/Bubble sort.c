#include <stdio.h>

int arr[] = {15, 6, 7, 18, 29, 10, 11};

int swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main() {
    int i, j, temp;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the values
               swap(&arr[j], &arr[j+1]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
