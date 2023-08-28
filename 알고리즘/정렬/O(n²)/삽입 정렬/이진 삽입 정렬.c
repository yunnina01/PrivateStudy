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

int binary_search(int key, int low, int high){
    if(low > high)
        return key > arr[low] ? low + 1 : low;
    int mid = (low + high) / 2;
    if(key == arr[mid])
        return mid + 1;
    if(key > arr[mid])
        return binary_search(key, mid + 1, high);
    return binary_search(key, low, mid - 1);
}

void insertion_sort(){
    int i, j, key, pos;
    for(i = 1; i < MAX_SIZE; i++){
        key = arr[i], pos = binary_search(key, 0, i - 1);
        for(j = i - 1; j >= pos; j--)
            arr[j + 1] = arr[j];
        arr[pos] = key;
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
    insertion_sort();
    display();

    return 0;
}