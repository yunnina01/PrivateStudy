#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapify(int idx, int heap_size){
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

void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int menu, item;

    while(menu != 99){
        puts("1. Insert 2. Heap Sort 3. Display 99. Exit");
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
                heap_sort();
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