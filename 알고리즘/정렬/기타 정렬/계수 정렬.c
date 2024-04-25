/*
배열의 범위가 적은 경우 빠른 속도를 갖는 정렬
배열의 범위 내에서 각 숫자가 몇 개 있는지 세어 정렬
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], count[30];

// 테스트 배열 생성
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 30;
}

// 최댓값 반환
int get_max() {
    int max = arr[0];
    for(int i = 1; i < MAX_SIZE; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// 최솟값 반환
int get_min() {
    int min = arr[0];
    for(int i = 1; i < MAX_SIZE; i++) {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

// 계수 정렬
void counting_sort() {
    int max = get_max(), min = get_min();
    int range = max - min + 1;
    if(range > 30) {
        puts("Counting Sort is inefficient");
        return;
    }
    int i, j, idx;
    for(i = 0; i < MAX_SIZE; i++)
        count[arr[i] - min]++;
    for(i = 0, idx = 0; i < range; i++) {
        for(j = 0; j < count[i]; j++)
            arr[idx++] = min + i;
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
    counting_sort();
    display();

    return 0;
}