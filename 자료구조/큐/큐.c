#include <stdio.h>
#define MAX_SIZE 10

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
        return 1 << 31;
    }
    return queue[front++];
}

int main(){
    int menu, item;

    while(menu != 99){
        puts("1. Enqueue 2. Dequeue 99. Exit");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if(item == 1 << 31)
                    continue;
                printf("%d\n", item);
                if(front == MAX_SIZE){
                    front = rear = 0;
                    puts("Queue is initialized");
                }
            case 99:
                break;
            default:
                puts("Menu Selection Error");
        }
    }

    return 0;
}