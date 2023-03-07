#include <stdio.h>
#include <math.h>
#define MAX_SIZE 10

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void insertion_sort(int *arr, int size){
    for(int i = 1; i < size; i++){
        int j, key = arr[i];
        for(j = i - 1; j >= 0 && key < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void maxheapify(int *arr, int idx, int heap_size) {
	int left = (idx + 1) * 2 - 1;
	int right = (idx + 1) * 2;
	int max = idx;
    if(left < heap_size && arr[left] > arr[max])
		max = left;
	if(right < heap_size && arr[right] > arr[max])
		max = right;
	if(max != idx){
        swap(arr, idx, max);
		maxheapify(arr, max, heap_size);
	}
}

void heap_sort(int *arr, int size){
	int heap_size = size;
	for(int i = (heap_size - 1) / 2; i >= 0; i--)
		maxheapify(arr, i, heap_size);
	for(int i = size - 1; i > 0; i--){
	    swap(arr, 0, i);
		maxheapify(arr, 0, --heap_size);
	}
}

int partition(int *arr, int left, int right){
    int i = left - 1;
    int pivot = arr[right];
    for(int j = left; j < right; j++){
        if(arr[j] < pivot)
            swap(arr, ++i, j);
    }
    swap(arr, ++i, right);
    return i;
}

void quick_sort(int *arr, int left, int right){
    if(left < right){
        int p = partition(arr, left, right);
        quick_sort(arr, left, p - 1);
        quick_sort(arr, p + 1, right);
    }
}

void intro_sort(int *arr, int size){
    int partition_size = partition(arr, 0, size - 1);
    if(partition_size < 16)
        insertion_sort(arr, size);
    else if(partition_size > log(size) * 2)
        heap_sort(arr, size);
    else
        quick_sort(arr, 0, size - 1);
}

void display(int *arr, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int arr[MAX_SIZE];
    int menu, item, size = 0;

    while(menu != 99){
        printf("1. Insert 2. Intro Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                intro_sort(arr, size);
                break;
            case 3:
                display(arr, size);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}