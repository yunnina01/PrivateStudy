// LIFO 스택 구현
#include <stdio.h>
#define MAX_SIZE 10                 // 스택 크기
#define MINF 1 << 31

int stack[MAX_SIZE], top;

// 요소 삽입
void push(int item) {
    if(top == MAX_SIZE)
        puts("Stack is full");
    else
        stack[top++] = item;
}

// 요소 추출
int pop() {
    if(!top) {
        puts("Stack is empty");
        return MINF;
    }
    return stack[--top];
}

int main() {
    int N, op, item;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 삽입, 0이 아니면 추출
        if(!op) {
            scanf("%d", &item);
            push(item);
        } else {
            item = pop();
            if(item == MINF)
                continue;
            printf("%d\n", item);
        }
    }
    return 0;
}