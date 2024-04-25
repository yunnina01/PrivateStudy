/*
일반적으로 속도가 빠른 편에 속하는 정렬
최악의 경우에는 O(n²)
분할 정복 방식을 이용
정렬할 데이터 중 가장 오른쪽 값을 피벗으로 사용
*/
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

// 퀵 정렬
void quick_sort(int left, int right) {
    int i = left, j = left, pivot = arr[right];
    for(; j < right; j++) {
        if(arr[j] < pivot)
            swap(i++, j);
    }
    swap(i, right);

    if(left < i)
        quick_sort(left, i - 1);
    if(i < right)
        quick_sort(i + 1, right);
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
    quick_sort(0, MAX_SIZE - 1);
    display();

    return 0;
}