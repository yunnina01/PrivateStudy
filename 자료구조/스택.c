#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE], top;

void push(int item){
    if(top == MAX_SIZE)
        puts("Stack is full");
    else
        stack[top++] = item;
}

int pop(){
    if(!top){
        puts("Stack is empty");
        return 1 << 31;
    }
    return stack[--top];
}

int main(){
    int menu, item;
    
    while(menu != 99){
        puts("1. Push 2. Pop 99. Exit");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
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