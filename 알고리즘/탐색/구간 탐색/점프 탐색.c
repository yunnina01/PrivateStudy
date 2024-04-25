// 블록 단위로 점프하면서 순차 탐색을 진행하는 알고리즘
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define JUMP 3

int arr[MAX_SIZE];

// 오름차순
int asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

// 출력
void display() {
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

// 정렬된 테스트 배열 생성 및 출력
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
    qsort(arr, MAX_SIZE, sizeof(int), asc);
    display();
}

// 순차 탐색
int sequential_search(int left, int right, int key) {
    for(int i = left; i < right; i++) {
        if(key == arr[i])
            return i;
    }
    return -1;
}

// 점프 탐색
void jump_search(int key) {
    int pos, start, end;
    start = MAX_SIZE - (MAX_SIZE % JUMP);
    end = MAX_SIZE;
    for(int i = JUMP; i < MAX_SIZE; i += JUMP){
        if(key < arr[i]) {
            start = i - JUMP;
            end = i;
            break;
        }
    }
    pos = sequential_search(start, end, key);
    if(pos != -1)
        printf("%d's position is %d\n", key, pos);
    else
        printf("No data about %d\n", key);
}

int main() {
    int N, op, key;
    scanf("%d", &N);
    init();
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 테스트 배열 생성, 아니면 탐색
        if(!op)
            init();
        else {
            scanf("%d", &key);
            jump_search(key);
        }
    }
    return 0;
}