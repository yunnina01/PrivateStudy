// FIFO 큐 구현
#include <stdio.h>
#define MAX_SIZE 10                 // 큐 크기
#define MINF 1 << 31

int queue[MAX_SIZE], front, rear;

// 요소 삽입
void enqueue(int item) {
    if(rear == MAX_SIZE)
        puts("Queue is full");
    else
        queue[rear++] = item;
}

// 요소 추출
int dequeue() {
    if(front == rear) {
        puts("Queue is empty");
        return MINF;
    }
    return queue[front++];
}

int main() {
    int N, op, item;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 삽입, 0이 아니면 추출
        if(!op) {
            scanf("%d", &item);
            enqueue(item);
        } else {
            item = dequeue();
            if(item == MINF)
                continue;
            printf("%d\n", item);
            if(front == MAX_SIZE) {
                front = rear = 0;
                puts("Queue is initialized");
            }
        }
    }
    return 0;
}