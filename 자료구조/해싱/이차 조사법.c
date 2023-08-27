#include <stdio.h>
#define BUCKET_SIZE 7

int ht[BUCKET_SIZE];

void init(){
    for(int i = 0; i < BUCKET_SIZE; i++)
        ht[i] = -1;
}

int hash_function(int key){
    return key % BUCKET_SIZE;
}

void insert(int key){
    if(key < 0){
        puts("Key Input Error");
        return;
    }
    int i, hash;
    for(i = 0; i < BUCKET_SIZE; i++){
        hash = hash_function(key + i * i);
        if(ht[hash] == key){
            puts("Duplicate Key Error");
            return;
        }
        if(ht[hash] == -1){
            ht[hash] = key;
            return;
        }
    }
    puts("This key can't be inserted");
}

void delete(int key){
    int hash = search(key);
    if(hash != -1)
        ht[hash] = -1;
}

int search(int key){
    if(key < 0){
        puts("Key Input Error");
        return -1;
    }
    int i, hash;
    for(i = 0; i < BUCKET_SIZE; i++){
        hash = hash_function(key + i * i);
        if(ht[hash] == key)
            return hash;
    }
    printf("No data about %d\n", key);
    return -1;
}

void display(){
    for(int i = 0; i < BUCKET_SIZE; i++){
        if(ht[i] == -1)
            printf("[%d] : empty\n", i);
        else
            printf("[%d] : %d\n", i, ht[i]);
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
            if(search(key) != -1)
                printf("%d's position is %d\n", key, search(key));
        }
        else
            display();
    }
    
    return 0;
}