#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int deque[MAX_SIZE];
    int front, rear;
}DequeType;

void init(DequeType *d){
    d->front = d->rear = 0;
}

int is_empty(DequeType *d){
    return d->front % MAX_SIZE == d->rear % MAX_SIZE;
}

int is_full(DequeType *d){
    return d->front % MAX_SIZE == (d->rear + 1) % MAX_SIZE;
}

void add_front(DequeType *d, int item){
    if(is_full(d))
        printf("Deque is full\n");
    else{
        d->deque[d->front % MAX_SIZE] = item;
        d->front = (--d->front + MAX_SIZE) % MAX_SIZE;
    }
}

void add_rear(DequeType *d, int item){
    if(is_full(d))
        printf("Deque is full\n");
    else
        d->deque[(++d->rear) % MAX_SIZE] = item;
}

int delete_front(DequeType *d){
    if(is_empty(d)){
        printf("Deque is empty\n");
        return -1;
    }
    return d->deque[(++d->front) % MAX_SIZE];
}

int delete_rear(DequeType *d){
    if(is_empty(d)){
        printf("Deque is empty\n");
        return -1;
    }
    int temp = d->rear % MAX_SIZE;
    d->rear = (--d->rear + MAX_SIZE) % MAX_SIZE;
    return d->deque[temp];
}

int main(){
    DequeType deque;
    int menu, item, data;
    init(&deque);

    while(menu != 99){
        printf("1. Add_Front 2. Add_Rear 3. Delete_Front 4. Delete_Rear 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_front(&deque, item);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_rear(&deque, item);
                break;
            case 3:
                data = delete_front(&deque);
                if(data != -1)
                    printf("%d\n", data);
                break;
            case 4:
                data = delete_rear(&deque);
                if(data != -1)
                    printf("%d\n", data);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}