#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 5

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

int is_sorted(){
    for(int i = 1; i < MAX_SIZE; i++){
        if(arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

void shuffle(){
    int i, idx;
    for(i = 0; i < MAX_SIZE; i++){
        srand(time(NULL));
        idx = rand() % MAX_SIZE;
        swap(i, idx);
    }
}

void bogo_sort(){
    while(!is_sorted())
        shuffle();
}

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    init();
    display();
    bogo_sort();
    display();

    return 0;
}