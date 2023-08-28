#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

void init(){
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
}

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quick_sort(int left, int right){
    int i = left + 1, j = right;
    int pivot = arr[left];
    do{
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j)
            swap(i, j);
    }while(i < j);
    swap(left, j);
    
    if(left < j)
        quick_sort(left, j - 1);
    if(i < right)
        quick_sort(i, right);
}

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    init();
    display();
    quick_sort(0, MAX_SIZE - 1);
    display();

    return 0;
}