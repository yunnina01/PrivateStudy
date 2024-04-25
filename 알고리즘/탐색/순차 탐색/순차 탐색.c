// 배열을 순차적으로 탐색하는 방법
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

// 출력
void display() {
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

// 테스트 배열 생성 및 출력
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
    display();
}

// 순차 탐색
void sequential_search(int key) {
    for(int i = 0; i < MAX_SIZE; i++) {
        if(key == arr[i]) {
            printf("%d's position is %d\n", key, i);
            return;
        }
    }
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
            sequential_search(key);
        }
    }
    return 0;
}