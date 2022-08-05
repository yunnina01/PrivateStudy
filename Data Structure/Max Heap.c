#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int heap[MAX_SIZE+1];
    int size;
}HeapType;

void init(HeapType *h){
    h->size = 0;
}

void insert(HeapType *h, int item){
    if(h->size >= MAX_SIZE){
        printf("Heap is full\n");
        return;
    }
    int i = ++(h->size);
    while((i != 1) && item > (h->heap[i/2])){
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

void delete(HeapType *h){
    if(h->size <= 0){
        printf("Heap is empty\n");
        return;
    }
    int parent = 1, child = 2;
    int max = h->heap[1], temp = h->heap[(h->size)--];
    while(child <= h->size){
        if(child < h->size && h->heap[child] < h->heap[child+1])
            child++;
        if(temp >= h->heap[child])
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    printf("%d\n", max);
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
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}