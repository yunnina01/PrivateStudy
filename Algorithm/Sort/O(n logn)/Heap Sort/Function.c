#include <stdio.h>
#define MAX_SIZE 10

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void maxheapify(int *arr, int idx, int heap_size){
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

void display(int *arr, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int arr[MAX_SIZE];
    int menu, item, size = 0;

    while(menu != 99){
        printf("1. Insert 2. Heap Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                heap_sort(arr, size);
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