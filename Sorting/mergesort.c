#include <stdio.h>


void merge(int arr[],int left, int mid, int right){
    int i;
    int n1=mid-left+1;
    int n2=right-mid;

    int L[n1], R[n2];

    for(i=0;i<n1;i++){
        L[i]=arr[mid+i];
    }
    for(i=0;i<n2;i++){
        R[i]=arr[mid+i+1];
    }
    int j=0;int k=left;
    while(i<n1&&j<n2){
        if(arr[i]<=arr[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[i];
            i++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }


}
void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }

}
int main(){
    int i,j;
    int arr[] = {15, 6, 7, 18, 29, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int left = 0;
    printf("The low is %d\n", left);
    int right = n - 1;
    printf("The high is %d\n", right);

    mergesort(arr,left,right);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;

}
