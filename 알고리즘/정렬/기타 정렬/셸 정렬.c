/*
가장 오래된 정렬 알고리즘의 하나
삽입 정렬이 어느 정도 정렬된 배열에서는 성능이 뛰어나다는 사실에서 착안한 방법
이웃 위치뿐만 아니라 멀리 떨어진 위치로도 이동할 수 있는 정렬
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

// 삽입 정렬
void insertion_sort(int left, int right, int gap) {
    int i, j, key;
    for(i = left + gap; i <= right; i += gap) {
        key = arr[i];
        for(j = i - gap; j >= left && key < arr[j]; j -= gap)
            arr[j + gap] = arr[j];
        arr[j + gap] = key;
    }
}

// 셸 정렬
void shell_sort() {
    int i, gap;
    for(gap = MAX_SIZE / 2; gap; gap /= 2) {
        for(i = 0; i < gap; i++)
            insertion_sort(i, MAX_SIZE - 1, gap);
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
    shell_sort();
    display();

    return 0;
}