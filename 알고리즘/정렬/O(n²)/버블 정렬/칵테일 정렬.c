// 버블 정렬의 변형으로, 양방향으로 정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

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

// 칵테일 정렬
void cocktail_sort() {
    int i, j;
    for(i = 0; i < MAX_SIZE / 2; i++) {
        for(j = i + 1; j < MAX_SIZE - i; j++) {
            if(arr[j - 1] > arr[j])
                swap(j - 1, j);
        }
        for(j--; j > i; j--) {
            if(arr[j] < arr[j - 1])
                swap(j, j - 1);
        }
    }
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
    cocktail_sort();
    display();

    return 0;
}