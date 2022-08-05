#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int queue[MAX_SIZE];
    int front, rear;
}QueueType;

void init(QueueType *q){
    q->front = q->rear = 0;
}

int is_empty(QueueType *q){
    return q->front % MAX_SIZE == q->rear % MAX_SIZE;
}

int is_full(QueueType *q){
    return q->front % MAX_SIZE == (q->rear + 1) % MAX_SIZE;
}

void enqueue(QueueType *q, int item){
    if(is_full(q))
        printf("Queue is full\n");
    else
        q->queue[(++q->rear) % MAX_SIZE] = item;
}

int dequeue(QueueType *q){
    if(is_empty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->queue[(++q->front) % MAX_SIZE];
}

int main(){
    QueueType q;
    int menu, item, data;
    init(&q);
    
    while(menu != 99){
        printf("1. Enqueue 2. Dequeue 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                if(item < 0){
                    printf("Number Input Error\n");
                    continue;
                }
                enqueue(&q, item);
                break;
            case 2:
                data = dequeue(&q);
                if(data == -1)
                    continue;
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