#include <stdio.h>
#include <stdlib.h>

typedef struct DequeNode{
    int data;
    struct DequeNode *llink, *rlink;
}DequeNode;

typedef struct {
    DequeNode *head, *tail;
}DequeType;

void init(DequeType *D){
    D->head = D->tail = NULL;
}

DequeNode* get_node(int item){
    DequeNode *new_node = (DequeNode*)malloc(sizeof(DequeNode));
    if(new_node == NULL)
        printf("Memory Allocation Error\n");
    new_node->data = item;
    new_node->llink = new_node->rlink = NULL;
    return new_node;
}

void add_front(DequeType *D, int item){
    DequeNode *new_node = get_node(item);
    if(new_node == NULL)
        return;
    if(D->head == NULL)
        D->head = D->tail = new_node;
    else{
        D->head->llink = new_node;
        new_node->rlink = D->head;
        D->head = new_node;
    }
}

void add_rear(DequeType *D, int item){
    DequeNode *new_node = get_node(item);
    if(new_node == NULL)
        return;
    if(D->tail == NULL)
        D->head = D->tail = new_node;
    else{
        D->tail->rlink = new_node;
        new_node->llink = D->tail;
        D->tail = new_node;
    }
}

void delete_front(DequeType *D){
    DequeNode *removed = D->head;
    if(removed == NULL)
        printf("Deque is empty\n");
    else{
        if(D->head == D->tail)
            D->head = D->tail = NULL;
        else{
            D->head = D->head->rlink;
            D->head->llink = NULL;
        }
        printf("%d\n", removed->data);
        free(removed);
    }
}

void delete_rear(DequeType *D){
    DequeNode *removed = D->tail;
    if(removed == NULL)
        printf("Deque is empty\n");
    else{
        if(D->head == D->tail)
            D->head = D->tail = NULL;
        else{
            D->tail = D->tail->llink;
            D->tail->rlink = NULL;
        }
        printf("%d\n", removed->data);
        free(removed);
    }
}

int main(){
    DequeType deque;
    int menu, item;
    init(&deque);

    while(menu != 99){
        printf("1. Add_Front 2. Add_Rear 3. Delete_Front 4. Delete_Rear 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_front(&deque, item);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_rear(&deque, item);
                break;
            case 3:
                delete_front(&deque);
                break;
            case 4:
                delete_rear(&deque);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}