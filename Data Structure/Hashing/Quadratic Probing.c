#include <stdio.h>
#define BUCKET_SIZE 7

void init(int *ht){
    for(int i=0; i<BUCKET_SIZE; i++)
        ht[i] = -1;
}

int hash_function(int key){
    return key % BUCKET_SIZE;
}

void insert(int *ht, int key){
    if(key < 0){
        printf("Key Input Error\n");
        return;
    }
    int i = 0, value;
    for(int i=0; i<BUCKET_SIZE; i++){
        value = hash_function(key + i * i);
        if(ht[value] == key){
            printf("Duplicate Key Error\n");
            return;
        }
        if(ht[value] == -1){
            ht[value] = key;
            return;
        }
    }
    printf("This key can't be inserted\n");
}

int search(int *ht, int key){
    if(key < 0){
        printf("Key Input Error\n");
        return -1;
    }
    int i = 1, value;
    for(int i=0; i<BUCKET_SIZE; i++){
        value = hash_function(key + i * i);
        if(ht[value] == key)
            return value;
    }
    printf("No data about %d\n", key);
    return -1;
}

void delete(int *ht, int key){
    int value = search(ht, key);
    if(value != -1)
        ht[value] = -1;
}

void display(int *ht){
    for(int i=0; i<BUCKET_SIZE; i++){
        if(ht[i] == -1)
            printf("[%d] : empty\n", i);
        else
            printf("[%d] : %d\n", i, ht[i]);
    }
}

int main(){
    int hash_table[BUCKET_SIZE];
    int menu, key;
    init(hash_table);
    
    while(menu != 99){
        printf("1. Insert 2. Delete 3. Clear 4. Search 5. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
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
                if(search(hash_table, key) != -1)
                    printf("%d's position is %d\n", key, search(hash_table, key));
                break;
            case 5:
                display(hash_table);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }
    
    return 0;
}