#include <stdio.h>
#define MAX_SIZE 11
#define MINF 1 << 31

int queue[MAX_SIZE], front, rear;

void enqueue(int item){
    if(front % MAX_SIZE == (rear + 1) % MAX_SIZE)
        puts("Queue is full");
    else
        queue[rear++ % MAX_SIZE] = item;
}

int dequeue(){
    if(front == rear){
        puts("Queue is empty");
        return MINF;
    }
    return queue[front++ % MAX_SIZE];
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
        }
    }
    
    return 0;
}