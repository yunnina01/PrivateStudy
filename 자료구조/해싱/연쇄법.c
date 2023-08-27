#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 7

typedef struct Node{
    int data;
    struct Node *link;
}Node;

Node *ht[BUCKET_SIZE];

int hash_function(int key){
    return key % BUCKET_SIZE;
}

Node* get_node(int key){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(!new_node)
        puts("Memory Allocation Error");
    else{
        new_node->data = key;
        new_node->link = NULL;
    }
    return new_node;
}

void insert(int key){
    Node *new_node = get_node(key);
    if(new_node == NULL)
        return;
    int hash = hash_function(key);
    if(ht[hash] == NULL)
        ht[hash] = new_node;
    else{
        Node *temp = ht[hash];
        while(temp->link){
            if(temp->data == key)
                break;
            temp = temp->link;
        }
        if(temp->data == key){
            puts("Duplicate Key Error");
            return;
        }
        temp->link = new_node;
    }
}

void delete(int key){
    int hash = hash_function(key);
    Node *removed = ht[hash], *temp;
    while(removed){
        if(removed->data == key){
            if(removed == ht[hash])
                ht[hash] = removed->link;
            else
                temp->link = removed->link;
            free(removed);
            return;
        }
        temp = removed;
        removed = removed->link;
    }
    printf("No data about %d\n", key);
}

void search(int key){
    int hash = hash_function(key), cnt = 1;
    Node *temp = ht[hash];
    for(Node *temp = ht[hash]; temp; temp = temp->link){
        if(temp->data == key){
            printf("%d's position is %d-%d\n", key, hash, cnt);
            return;
        }
        cnt++;
    }
    printf("No data about %d\n", key);
}

void display(){
    for(int i = 0; i < BUCKET_SIZE; i++){
        if(!ht[i])
            printf("[%d] : empty\n", i);
        else{
            printf("[%d] : ", i);
            for(Node *temp = ht[i]; temp; temp = temp->link)
                printf("%d  ", temp->data);
            puts("");
        }
    }
}

int main(){
    int N, op, key;
    scanf("%d", &N);
    init(ht);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d", &key);
            insert(key);
        }
        else if(op == 1){
            scanf("%d", &key);
            delete(key);
        }
        else if(op == 2){
            scanf("%d", &key);
            search(key);
        }
        else
            display();
    }

    return 0;
}