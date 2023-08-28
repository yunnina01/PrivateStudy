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

void bubble_sort(){
    int i, j, temp;
    for(i = 0; i < MAX_SIZE - 1; i++){
        for(j = 1; j < MAX_SIZE - i; j++){
            if(arr[j - 1] > arr[j]){
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
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
    bubble_sort();
    display();

    return 0;
}