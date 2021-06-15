//
// Created by lenovo on 2021-06-07.
//

#include "demo1_fun.h"
void bubleSort(int *arr,int n){

    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
};

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i]<<endl;
    }
}
