#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], heap[MAX_SIZE + 1], size;

void push(int item){
    int i = ++size;
    while(i != 1 && item > heap[i / 2]){
        heap[i] = heap[i / 2];
        i /= 2;
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
        child *= 2;
    }
    heap[parent] = temp;
    return max;
}

void heap_sort(){
    int temp = size;
    for(int i = size - 1; i >= 0; i--)
        arr[i] = pop();
    size = temp;
}

void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int i, menu, item;

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
                    arr[size] = item;
                    push(item);
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