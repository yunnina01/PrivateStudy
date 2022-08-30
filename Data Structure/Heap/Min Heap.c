#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int heap[MAX_SIZE+1];
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
    while(i != 1 && item < H->heap[i/2]){
        H->heap[i] = H->heap[i/2];
        i /= 2;
    }
    H->heap[i] = item;
}

void delete(HeapType *H){
    if(H->size <= 0){
        printf("Heap is empty\n");
        return;
    }
    int parent = 1, child = 2;
    int min = H->heap[1], temp = H->heap[H->size--];
    while(child <= H->size){
        if(child < H->size && H->heap[child] > H->heap[child+1])
            child++;
        if(temp <= H->heap[child])
            break;
        H->heap[parent] = H->heap[child];
        parent = child;
        child *= 2;
    }
    H->heap[parent] = temp;
    printf("%d\n", min);
}

int main(){
    HeapType heap;
    int menu, item;
    init(&heap);

    while(menu != 99){
        printf("1. Insert 2. Delete 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                insert(&heap, item);
                break;
            case 2:
                delete(&heap);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}