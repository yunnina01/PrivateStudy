// 해시 함수를 2개 사용하는 해싱
#include <stdio.h>
#define BUCKET_SIZE 7                                           // 버킷 크기, 소수
#define REHASH_NUM 5                                            // 추가 해시 함수에 사용

int ht[BUCKET_SIZE];

// 해시 테이블 초기화
void init() {
    for(int i = 0; i < BUCKET_SIZE; i++)
        ht[i] = -1;
}

// 기존 해시 함수
int hash_function(int key) {
    return key % BUCKET_SIZE;
}

// 추가 해시 함수
int rehash_function(int key) {
    return REHASH_NUM - (hash_function(key) % REHASH_NUM);
}

// 요소 삽입
void insert(int key) {
    if(key < 0) {
        puts("Key Input Error");
        return;
    }
    int i = 0, hash, value, step;
    hash = value = hash_function(key);
    step = rehash_function(key);
    do {
        if(ht[hash] == key) {
            puts("Duplicate Key Error");
            return;
        }
        if(ht[hash] == -1) {
            ht[hash] = key;
            return;
        }
        hash = hash_function(value + (++i) * step);
    }while(hash != value);
    puts("Hash Table is full");
}

// 요소 삭제
void delete(int key) {
    int hash = search(key);
    if(hash != -1)
        ht[hash] = -1;
}

// 요소 탐색
int search(int key) {
    if(key < 0) {
        puts("Key Input Error");
        return -1;
    }
    int i = 0, hash, value, step;
    hash = value = hash_function(key);
    step = rehash_function(key);
    do {
        if(ht[hash] == key)
            return hash;
        hash = hash_function(value + (++i) * step);
    }while(hash != value);
    printf("No data about %d\n", key);
    return -1;
}

// 해시 테이블 춫력
void display() {
    for(int i = 0; i < BUCKET_SIZE; i++) {
        if(ht[i] == -1)
            printf("[%d] : empty\n", i);
        else
            printf("[%d] : %d\n", i, ht[i]);
    }
}

int main() {
    int N, op, key;
    scanf("%d", &N);
    init(ht);
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 삽입, 1이면 삭제, 2이면 검색, 그 외에는 해시 테이블 출력
        if(!op) {
            scanf("%d", &key);
            insert(key);
        } else if(op == 1) {
            scanf("%d", &key);
            delete(key);
        } else if(op == 2) {
            scanf("%d", &key);
            if(search(key) != -1)
                printf("%d's position is %d\n", key, search(key));
        } else
            display();
    }
    return 0;
}