#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void insertion_sort(){
    int i, j, key;
    for(i = 1; i < MAX_SIZE; i++){
        key = arr[i];
        for(j = i - 1; j >= 0 && key < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void heapify(int idx, int heap_size) {
	int left = idx * 2 + 1, right = (idx + 1) * 2, max = idx;
    if(left < heap_size && arr[left] > arr[max])
		max = left;
	if(right < heap_size && arr[right] > arr[max])
		max = right;
	if(max != idx){
        swap(idx, max);
		heapify(max, heap_size);
	}
}

void heap_sort(){
	int heap_size = MAX_SIZE;
	for(int i = (MAX_SIZE - 1) / 2; i >= 0; i--)
		heapify(i, heap_size);
	for(int i = MAX_SIZE - 1; i > 0; i--){
	    swap(0, i);
		heapify(0, --heap_size);
	}
}

int partition(int left, int right){
    int i = left, j = left, pivot = arr[right];
    for(; j < right; j++){
        if(arr[j] < pivot)
            swap(i++, j);
    }
    swap(i, right);
    return i;
}

void intro_sort(int left, int right, int depth){
    if(MAX_SIZE < 16)
        insertion_sort();
    else if(!depth)
        heap_sort();
    else{
        int p = partition(0, MAX_SIZE - 1);
        intro_sort(left, p - 1, depth - 1);
        intro_sort(p + 1, right, depth - 1);
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
    intro_sort(0, MAX_SIZE - 1, log2(MAX_SIZE) * 2);
    display();

    return 0;
}