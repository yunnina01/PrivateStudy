#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 7

typedef struct HTNode{
    int data;
    struct HTNode *link;
}HTNode;

void init(HTNode **ht){
    for(int i=0; i<BUCKET_SIZE; i++){
        ht[i] = NULL;
    }
}

int hash_function(int key){
    return key % BUCKET_SIZE;
}

HTNode* get_node(int key){
    HTNode *new_node = (HTNode*)malloc(sizeof(HTNode));
    if(new_node == NULL)
        printf("Memory Allocation Error\n");
    new_node->data = key;
    new_node->link = NULL;
    return new_node;
}

void insert(HTNode **ht, int key){
    HTNode *new_node = get_node(key);
    if(new_node == NULL)
        return;
    int value = hash_function(key);
    HTNode *temp = ht[value];
    if(temp == NULL)
        ht[value] = new_node;
    else{
        while(temp->link != NULL){
            if(temp->data == key)
                break;
            temp = temp->link;
        }
        if(temp->data == key){
            printf("Duplicate Key Error\n");
            return;
        }
        temp->link = new_node;
    }
}

void search(HTNode **ht, int key){
    int value = hash_function(key), cnt = 1;
    HTNode *temp = ht[value];
    while(temp != NULL){
        if(temp->data == key){
            printf("%d's position is %d-%d\n", key, value, cnt);
            return;
        }
        temp = temp->link;
        cnt++;
    }
    printf("No data about %d\n", key);
}

void delete(HTNode **ht, int key){
    int value = hash_function(key);
    HTNode *removed = ht[value], *temp;
    while(removed != NULL){
        if(removed->data == key){
            if(removed == ht[value])
                ht[value] = removed->link;
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

void display(HTNode **ht){
    for(int i=0; i<BUCKET_SIZE; i++){
        HTNode *temp = ht[i];
        if(temp == NULL)
            printf("[%d] : empty\n", i);
        else{
            printf("[%d] : ", i);
            while(temp != NULL){
                printf("%d - ", temp->data);
                temp = temp->link;
            }
            puts("");
        }
    }
}

int main(){
    HTNode *hash_table[BUCKET_SIZE];
    int menu, key;
    init(hash_table);

    while(menu != 99){
        printf("1. Insert 2. Delete 3. Clear 4. Search 5. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                insert(hash_table, key);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &key);
                delete(hash_table, key);
                break;
            case 3:
                init(hash_table);
                break;
            case 4:
                printf("Enter the number : ");
                scanf("%d", &key);
                search(hash_table, key);
                break;
            case 5:
                display(hash_table);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}