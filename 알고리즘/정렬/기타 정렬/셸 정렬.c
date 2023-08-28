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

void insertion_sort(int left, int right, int gap){
    int i, j, key;
    for(i = left + gap; i <= right; i += gap){
        key = arr[i];
        for(j = i - gap; j >= left && key < arr[j]; j -= gap)
            arr[j + gap] = arr[j];
        arr[j + gap] = key;
    }
}

void shell_sort(){
    int i, gap;
    for(gap = MAX_SIZE / 2; gap; gap /= 2){
        for(i = 0; i < gap; i++)
            insertion_sort(i, MAX_SIZE - 1, gap);
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
    shell_sort();
    display();

    return 0;
}