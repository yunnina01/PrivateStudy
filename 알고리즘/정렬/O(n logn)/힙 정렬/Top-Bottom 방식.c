#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], heap[MAX_SIZE + 1], size;

void init(){
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
}

void push(int item){
    int i = ++size;
    while(i != 1 && item > heap[i / 2]){
        heap[i] = heap[i / 2];
        i >>= 1;
    }
    heap[i] = item;
}

int pop(){
    int parent = 1, child = 2;
    int max = heap[1], temp = heap[size--];
    while(child <= size){
        if(child < size && heap[child] < heap[child + 1])
            child++;
        if(temp >= heap[child])
            break;
        heap[parent] = heap[child];
        parent = child;
        child <<= 1;
    }
    heap[parent] = temp;
    return max;
}

void heap_sort(){
    for(int i = MAX_SIZE - 1; i >= 0; i--)
        arr[i] = pop();
}

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    init();
    display();
    heap_sort();
    display();
    
    return 0;
}