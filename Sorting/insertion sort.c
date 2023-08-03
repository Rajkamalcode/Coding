#include <stdio.h>
int arr[] = {15, 6, 7, 18, 29, 10, 11};

int main(){
    int i,j,key;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(i=0;i<n;i++){
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


}
