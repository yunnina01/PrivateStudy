// 블록의 범위를 지수 단위로 늘려가면서 탐색하는 알고리즘
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_SIZE 10

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

// 지수 탐색
void exponential_search(int key) {
    int pos, start, end;
    start = pow(2, (int)log2(MAX_SIZE));
    end = MAX_SIZE;
    for(int i = 1; i < MAX_SIZE; i <<= 1) {
        if(key < arr[i]) {
            start = i >> 1;
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
            exponential_search(key);
        }
    }
    return 0;
}