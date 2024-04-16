// 스택과 큐의 특성을 합친 덱을 배열을 이용하여 구현
#include <stdio.h>
#define MAX_SIZE 11                                 // 덱 크기

int deque[MAX_SIZE], front, rear;

// 덱 full 여부
int full() {
    if(front == (rear + 1) % MAX_SIZE) {
        puts("Deque is full");
        return 1;
    }
    return 0;
}

// 덱 empty 여부
int empty() {
    if(front == rear) {
        puts("Deque is empty");
        return 1;
    }
    return 0;
}

// 덱의 처음에 삽입
void push_front(int item) {
    if(!full()) {
        front = (--front + MAX_SIZE) % MAX_SIZE;
        deque[front] = item;
    }
}

// 덱의 마지막에 삽입
void push_rear(int item) {
    if(!full()) {
        deque[rear++] = item;
        rear %= MAX_SIZE;
    }
}

// 덱의 첫 요소 추출
void pop_front() {
    if(!empty()) {
        printf("%d\n", deque[front++]);
        front %= MAX_SIZE;
    }
}

// 댁의 마지막 요소 추출
void pop_rear() {
    if(!empty()) {
        rear = (--rear + MAX_SIZE) % MAX_SIZE;
        printf("%d\n", deque[rear]);
    }
}

int main() {
    int N, op, item, data;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 처음에, 1이면 마지막에 삽입 / 2이면 첫 요소, 3이면 마지막 요소 추출
        if(!op) {
            scanf("%d", &item);
            push_front(item);
        } else if(op == 1) {
            scanf("%d", &item);
            push_rear(item);
        } else if(op == 2)
            pop_front();
        else
            pop_rear();
    }
    return 0;
}