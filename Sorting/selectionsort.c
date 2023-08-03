#include <stdio.h>

int arr[] = {15, 6, 7, 18, 29, 10, 11};
int n = sizeof(arr) / sizeof(arr[0]);

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


void selectionsort(int arr[]){

    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
    }

}

int main() {
    int i, j, temp;
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionsort(arr);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}


