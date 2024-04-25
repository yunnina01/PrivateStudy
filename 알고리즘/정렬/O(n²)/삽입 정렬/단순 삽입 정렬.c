// 배열의 요소를 앞에서부터 차례로 이미 정렬된 배열과 비교하며 자신의 위치에 삽입하는 정렬 방식
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

// 삽입 정렬
void insertion_sort() {
    int i, j, key;
    for(i = 1; i < MAX_SIZE; i++) {
        key = arr[i];
        for(j = i - 1; j >= 0 && key < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
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
    insertion_sort();
    display();

    return 0;
}