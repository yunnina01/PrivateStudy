#include <stdio.h>
#define MAX_SIZE 10

typedef struct {
    int stack[MAX_SIZE];
    int top;
}StackType;

void init(StackType *s){
    s->top = -1;
}

void push(StackType *s, int item){
    if(s->top == MAX_SIZE - 1)
        printf("Stack is full\n");
    else
        s->stack[++s->top] = item;
}

int pop(StackType *s){
    if(s->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return s->stack[s->top--];
}

int main(){
    StackType s;
    int menu, item;
    init(&s);
    
    while(menu != 99){
        printf("1. Push 2. Pop 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                if(item < 0)
                    printf("Number Input Error\n");
                else
                    push(&s, item);
                break;
            case 2:
                item = pop(&s);
                if(item == -1)
                    continue;
                printf("%d\n", item);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}