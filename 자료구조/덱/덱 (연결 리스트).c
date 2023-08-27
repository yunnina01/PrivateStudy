#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *prev, *next;
}Node;

Node *head, *tail;

Node* get_node(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(!new_node)
        puts("Memory Allocation Error");
    else{
        new_node->data = item;
        new_node->prev = new_node->next = NULL;
    }
    return new_node;
}

void push_front(int item){
    Node *new_node = get_node(item);
    if(!new_node)
        return;
    if(!head)
        head = tail = new_node;
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void push_rear(int item){
    Node *new_node = get_node(item);
    if(!new_node)
        return;
    if(!tail)
        head = tail = new_node;
    else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

void pop_front(){
    if(!head)
        puts("Deque is empty");
    else{
        Node *removed = head;
        if(head == tail)
            head = tail = NULL;
        else{
            head = head->next;
            head->prev = NULL;
        }
        printf("%d\n", removed->data);
        free(removed);
    }
}

void pop_rear(){
    if(!tail)
        puts("Deque is empty");
    else{
        Node *removed = tail;
        if(head == tail)
            head = tail = NULL;
        else{
            tail = tail->prev;
            tail->next = NULL;
        }
        printf("%d\n", removed->data);
        free(removed);
    }
}

int main(){
    int N, op, item;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d", &item);
            push_front(item);
        }
        else if(op == 1){
            scanf("%d", &item);
            push_front(item);
        }
        else if(op == 2)
            pop_front();
        else
            pop_rear();
    }

    return 0;
}