#include <stdio.h>
#define MAX_SIZE 10
#define MINF 1 << 31

int queue[MAX_SIZE], front, rear;

void enqueue(int item){
    if(rear == MAX_SIZE)
        puts("Queue is full");
    else
        queue[rear++] = item;
}

int dequeue(){
    if(front == rear){
        puts("Queue is empty");
        return MINF;
    }
    return queue[front++];
}

int main(){
    int N, op, item;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d", &item);
            enqueue(item);
        }
        else{
            item = dequeue();
            if(item == MINF)
                continue;
            printf("%d\n", item);
            if(front == MAX_SIZE){
                front = rear = 0;
                puts("Queue is initialized");
            }
        }
    }

    return 0;
}