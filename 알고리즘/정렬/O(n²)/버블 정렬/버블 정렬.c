// 정렬의 가장 기본 형태인 버블 정렬 구현
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

// 버블 정렬
void bubble_sort() {
    int i, j, temp;
    for(i = 0; i < MAX_SIZE - 1; i++) {
        for(j = 1; j < MAX_SIZE - i; j++) {
            if(arr[j - 1] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
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
    bubble_sort();
    display();

    return 0;
}