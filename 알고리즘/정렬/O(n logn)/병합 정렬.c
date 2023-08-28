#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], temp[MAX_SIZE];

void init(){
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
}

void merge(int left, int mid, int right){
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    if(i > mid){
        for(; j <= right; j++)
            temp[k++] = arr[j];
    }
    else{
        for(; i <= mid; i++)
            temp[k++] = arr[i];
    }
    for(i = left; i <= right; i++)
        arr[i] = temp[i];
}

void merge_sort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
    }
}

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    init();
    display();
    merge_sort(0, MAX_SIZE - 1);
    display();

    return 0;
}