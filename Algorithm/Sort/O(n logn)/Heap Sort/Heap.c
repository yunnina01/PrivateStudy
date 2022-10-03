#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int heap[MAX_SIZE + 1];
    int size;
}HeapType;

void init(HeapType *H){
    H->size = 0;
}

void insert(HeapType *H, int item){
    if(H->size >= MAX_SIZE){
        printf("Heap is full\n");
        return;
    }
    int i = ++H->size;
    while(i != 1 && item > H->heap[i / 2]){
        H->heap[i] = H->heap[i / 2];
        i /= 2;
    }
    H->heap[i] = item;
}

int delete(HeapType *H){
    int parent = 1, child = 2;
    int min = H->heap[1], temp = H->heap[H->size--];
    while(child <= H->size){
        if(child < H->size && H->heap[child] < H->heap[child + 1])
            child++;
        if(temp >= H->heap[child])
            break;
        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }
    H->heap[parent] = temp;
    return min;
}

void heap_sort(HeapType *H){
    int temp = H->size;
    for(int i = H->size; i > 0; i--)
        H->heap[i] = delete(H);
    H->size = temp;
}

void display(HeapType *H){
    for(int i = 1; i <= H->size; i++)
        printf("%d ", H->heap[i]);
    puts("");
}

int main(){
    HeapType heap;
    int arr[MAX_SIZE];
    int menu, item, size = 0;
    init(&heap);

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
                for(int i=0; i<size; i++)
                    insert(&heap, arr[i]);
                heap_sort(&heap);
                break;
            case 3:
                display(&heap);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }
    
    return 0;
}