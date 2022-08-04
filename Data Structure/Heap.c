#include <stdio.h>
#define MAX_SIZE 7

typedef struct {
    int heap[MAX_SIZE];
    int length;
}HeapType;

void init(HeapType *h){
    h->length = 0;
}

void insert(HeapType *h, int item){
    if(h->length >= MAX_SIZE){
        printf("Heap is full\n");
        return;
    }
    int i = ++(h->length);
    while((i != 1) && item > (h->heap[i/2])){
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

int delete(HeapType *h){
    int parent = 1, child = 2;
    int item = h->heap[1], temp = h->heap[(h->length)--];
    while(child <= h->length){
        if(child < h->length && h->heap[child] < h->heap[child+1])
            child++;
        if(temp >= h->heap[child])
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(){
    HeapType *heap;
    int menu, item;
    init(heap);

    while(menu != 99){
        printf("1. Insert 2. Delete 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                insert(heap, item);
                break;
            case 2:
                printf("%d\n", delete(heap));
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}