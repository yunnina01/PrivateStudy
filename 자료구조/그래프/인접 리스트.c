#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct Node{
    int v;
    struct Node *next;
}Node;

Node *graph[MAX_SIZE + 1];

void insert(int start, int end){
    if(start > MAX_SIZE || end > MAX_SIZE || start == end){
        puts("Edge Input Error");
        return;
    }        
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(!new_node){
        puts("Memory Allocation Error");
        return;
    }
    new_node->v = end;
    new_node->next = graph[start];
    graph[start] = new_node;
}

void delete(int start, int end){
    if(start > MAX_SIZE || end > MAX_SIZE){
        puts("Edge Input Error");
        return;
    }
    Node *removed, *temp;
    removed = graph[start];
    while(removed){
        if(removed->v == end){
            if(removed == graph[start])
                graph[start] = removed->next;
            else
                temp->next = removed->next;
            free(removed);
            return;
        }
        temp = removed;
        removed = removed->next;
    }
    puts("No data about input edge");
}

void display(){
    for(int i = 1; i <= MAX_SIZE; i++){
        printf("[%d] : ", i);
        for(Node *temp = graph[i]; temp; temp = temp->next)
            printf("%d -> ", temp->v);
        puts("");
    }
}

int main(){
    int N, op, start, end;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d %d", &start, &end);
            insert(start, end);
        }
        else if(op == 1){
            scanf("%d %d", &end);
            delete(start, end);
        }
        else
            display();
    }

    return 0;
}