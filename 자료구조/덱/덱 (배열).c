#include <stdio.h>
#define MAX_SIZE 11

int deque[MAX_SIZE], front, rear;

int full(){
    if(front == (rear + 1) % MAX_SIZE){
        puts("Deque is full");
        return 1;
    }
    return 0;
}

int empty(){
    if(front == rear){
        puts("Deque is empty");
        return 1;
    }
    return 0;
}

void push_front(int item){
    if(!full()){
        front = (--front + MAX_SIZE) % MAX_SIZE;
        deque[front] = item;
    }
}

void push_rear(int item){
    if(!full()){
        deque[rear++] = item;
        rear %= MAX_SIZE;
    }
}

void pop_front(){
    if(!empty()){
        printf("%d\n", deque[front++]);
        front %= MAX_SIZE;
    }
}

void pop_rear(){
    if(!empty()){
        rear = (--rear + MAX_SIZE) % MAX_SIZE;
        printf("%d\n", deque[rear]);
    }
}

int main(){
    int N, op, item, data;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d", &item);
            push_front(item);
        }
        else if(op == 1){
            scanf("%d", &item);
            push_rear(item);
        }
        else if(op == 2)
            pop_front();
        else
            pop_rear();
    }
    
    return 0;
}