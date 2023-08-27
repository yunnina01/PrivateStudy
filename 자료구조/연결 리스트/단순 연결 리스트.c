#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head;
int length;

void init(){
    head = NULL;
}

Node* get_node(int item){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(!new_node)
        puts("Memory Allocation Error");
    else{
        new_node->data = item;
        new_node->next = NULL;
    }
    return new_node;
}

void insert(int item){
    Node *new_node = get_node(item);
    if(new_node == NULL)
        return;
    new_node->next = head;
    head = new_node;
    length++;
}

void delete(int pos){
    if(pos <= 0 || pos > length)
        puts("Position Input Error");
    else{
        Node *temp = head, *removed = head;
        if(pos == 1)
            head = removed->next;
        else{
            for(int i = 0; i < pos - 2; i++)
                temp = temp->next;
            removed = temp->next;
            temp->next = removed->next;
        }
        free(removed);
        length--;
    }
}

void display(){
    if(!length){
        puts("List is empty");
        return;
    }
    for(Node *temp = head; temp; temp = temp->next)
        printf("%d -> ", temp->data);
    puts("");
}

int main(){
    int N, op, pos, item;
    scanf("%d", &N);
    init();
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d", &item);
            insert(item);
        }
        else if(op == 1){
            scanf("%d", &pos);
            delete(pos);
        }
        else
            display();
    }

    return 0;
}