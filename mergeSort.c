#include <stdio.h>




void mergeSort(int arr[], int length){
    if(length <= 1)  return;

    int midd = length /2;
    int leftArr[midd];
    int rightArr[length - midd];

    for(int i = 0; i<length; i++){
        if(i < midd) leftArr[i] = arr[i];
        else  rightArr[i] = arr[i];   
    }
    mergeSort(leftArr,midd);
    mergeSort(rightArr,length - midd);
    merge(arr,leftArr,rightArr,midd,length - midd);

}

void merge(int arr[], int leftArr[],int rightArr[],int leftSize, int rightSize){
    int r = 0;
    int l = 0;
    int tracker = 0;
    while( l < leftSize && r < leftSize ){
        if(leftArr[l] <= rightArr[r]){
            arr[tracker] = leftArr[l];
            l++;
        }else{
            arr[tracker] = rightArr[r];
            r++;
        }
        tracker++;
    }

    while( l < leftSize){
        arr[tracker] = leftArr[l];
        l++;
    }
    while( r< rightSize){
        arr[tracker] = rightArr[l];
        r++;
    }
}

int main() {
    int arr[] = {3,1,9,232,242};
 

    return 0;
}