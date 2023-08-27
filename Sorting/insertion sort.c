#include <stdio.h>
void ins_sort(int n, int arr[]){
    int i, j,key;
    for(i=0;i<n;i++){
        j=i-1;
        key=arr[i];

        while(j>0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

}

int main(){
    int n;int i;
    scanf("%d", &n);
    int arr[n];
    printf("Enter array of N numbers\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    ins_sort(size, arr);
    printf("After Sorting\n");
    for(i=0;i<n;i++){
        printf("%d", arr[i]);
    }
    return 0;

}
