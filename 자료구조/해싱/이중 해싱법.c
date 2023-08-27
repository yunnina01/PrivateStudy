#include <stdio.h>
#define BUCKET_SIZE 7
#define REHASH_NUM 5

int ht[BUCKET_SIZE];

void init(){
    for(int i = 0; i < BUCKET_SIZE; i++)
        ht[i] = -1;
}

int hash_function(int key){
    return key % BUCKET_SIZE;
}

int rehash_function(int key){
    return REHASH_NUM - (hash_function(key) % REHASH_NUM);
}

void insert(int key){
    if(key < 0){
        puts("Key Input Error");
        return;
    }
    int i = 0, hash, value, step;
    hash = value = hash_function(key);
    step = rehash_function(key);
    do{
        if(ht[hash] == key){
            puts("Duplicate Key Error");
            return;
        }
        if(ht[hash] == -1){
            ht[hash] = key;
            return;
        }
        hash = hash_function(value + (++i) * step);
    }while(hash != value);
    puts("Hash Table is full");
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
    int i = 0, hash, value, step;
    hash = value = hash_function(key);
    step = rehash_function(key);
    do{
        if(ht[hash] == key)
            return hash;
        hash = hash_function(value + (++i) * step);
    }while(hash != value);
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