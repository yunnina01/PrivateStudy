#include <stdio.h>
#define MAX_SIZE 11

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
        return 1 << 31;
    }
    return queue[front++ % MAX_SIZE];
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
            case 99:
                break;
            default:
                puts("Menu Selection Error");
        }
    }
    
    return 0;
}