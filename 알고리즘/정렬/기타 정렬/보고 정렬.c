// 배열이 정렬될 때까지 무작위로 섞는 정렬 방식
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 5

int arr[MAX_SIZE];

// 테스트 배열 생성
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
}

// 배열 요소 swap
void swap(int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// 정렬 여부 확인
int is_sorted() {
    for(int i = 1; i < MAX_SIZE; i++) {
        if(arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

// 배열 요소 섞기
void shuffle() {
    int i, idx;
    for(i = 0; i < MAX_SIZE; i++) {
        srand(time(NULL));
        idx = rand() % MAX_SIZE;
        swap(i, idx);
    }
}

// 보고 정렬
void bogo_sort() {
    while(!is_sorted())
        shuffle();
}

// 출력
void display() {
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main() {
    init();
    display();
    bogo_sort();
    display();

    return 0;
}