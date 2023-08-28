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

void selection_sort(){
    int i, j, min, max;
    for(i = 0; i < MAX_SIZE / 2; i++){
        min = i, max = MAX_SIZE - i - 1;
        for(j = i; j < MAX_SIZE - i; j++){
            if(arr[j] < arr[min])
                min = j;
            if(arr[j] > arr[max])
                max = j;
        }
        swap(i, min);
        if(max == i)
            max = min;
        swap(max, MAX_SIZE - i - 1);
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
    selection_sort();
    display();

    return 0;
}