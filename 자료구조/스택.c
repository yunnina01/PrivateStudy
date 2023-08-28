#include <stdio.h>
#define MAX_SIZE 10
#define MINF 1 << 31

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
        return MINF;
    }
    return stack[--top];
}

int main(){
    int N, op, item;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d", &item);
            push(item);
        }
        else{
            item = pop();
            if(item == MINF)
                continue;
            printf("%d\n", item);
        }
    }

    return 0;
}