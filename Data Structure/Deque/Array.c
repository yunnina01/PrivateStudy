#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int deque[MAX_SIZE];
    int front, rear;
}DequeType;

void init(DequeType *D){
    D->front = D->rear = 0;
}

int is_empty(DequeType *D){
    return D->front % MAX_SIZE == D->rear % MAX_SIZE;
}

int is_full(DequeType *D){
    return D->front % MAX_SIZE == (D->rear + 1) % MAX_SIZE;
}

void add_front(DequeType *D, int item){
    if(is_full(D))
        printf("Deque is full\n");
    else{
        D->deque[D->front % MAX_SIZE] = item;
        D->front = (--D->front + MAX_SIZE) % MAX_SIZE;
    }
}

void add_rear(DequeType *D, int item){
    if(is_full(D))
        printf("Deque is full\n");
    else
        D->deque[(++D->rear) % MAX_SIZE] = item;
}

int delete_front(DequeType *D){
    if(is_empty(D)){
        printf("Deque is empty\n");
        return -1;
    }
    return D->deque[(++D->front) % MAX_SIZE];
}

int delete_rear(DequeType *D){
    if(is_empty(D)){
        printf("Deque is empty\n");
        return -1;
    }
    int temp = D->rear % MAX_SIZE;
    D->rear = (--D->rear + MAX_SIZE) % MAX_SIZE;
    return D->deque[temp];
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