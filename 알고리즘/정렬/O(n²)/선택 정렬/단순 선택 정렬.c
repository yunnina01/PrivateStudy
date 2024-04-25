// 정렬되지 않은 요소 중 최솟값을 찾아 앞의 요소와 교환하는 정렬 방식
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

// 선택 정렬
void selection_sort() {
    int i, j, min, temp;
    for(i = 0; i < MAX_SIZE - 1; i++) {
        min = i;
        for(j = i + 1; j < MAX_SIZE; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
    selection_sort();
    display();

    return 0;
}