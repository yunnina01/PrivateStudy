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
    int menu, item, data;

    while(menu != 99){
        puts("1. Push_Front 2. Push_Rear 3. Pop_Front 4. Pop_Rear 99. Exit");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                push_front(item);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &item);
                push_rear(item);
                break;
            case 3:
                pop_front();
                break;
            case 4:
                pop_rear();
            case 99:
                break;
            default:
                puts("Menu Selection Error");
        }
    }

    return 0;
}