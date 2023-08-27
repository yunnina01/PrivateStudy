#include <stdio.h>
#include <math.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insertion_sort(){
    int i, j, key;
    for(i = 1; i < size; i++){
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
	int heap_size = size;
	for(int i = (heap_size - 1) / 2; i >= 0; i--)
		heapify(i, heap_size);
	for(int i = size - 1; i > 0; i--){
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

void quick_sort(int left, int right){
    if(left < right){
        int p = partition(left, right);
        quick_sort(left, p - 1);
        quick_sort(p + 1, right);
    }
}

void intro_sort(){
    int partition_size = partition(0, size - 1);
    if(partition_size < 16)
        insertion_sort();
    else if(partition_size > log(size) * 2)
        heap_sort();
    else
        quick_sort(0, size - 1);
}

void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int menu, item;

    while(menu != 99){
        puts("1. Insert 2. Intro Sort 3. Display 99. Exit");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                if(size == MAX_SIZE)
                    puts("Array is full");
                else{
                    printf("Enter the number : ");
                    scanf("%d", &item);
                    arr[size++] = item;
                }
                break;
            case 2:
                intro_sort();
                break;
            case 3:
                display();
            case 99:
                break;
            default:
                puts("Menu Selection Error");
        }
    }

    return 0;
}