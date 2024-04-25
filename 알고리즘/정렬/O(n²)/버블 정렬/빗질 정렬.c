/*
버블 정렬을 개선한 정렬 알고리즘
gap 값을 줄여나가면서 정렬
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

// 빗질 정렬
void comb_sort() {
    double shrink = 1.3;
    int i, temp, gap = MAX_SIZE;
    while(gap > 1) {
        gap /= shrink;
        for(i = 0; i < MAX_SIZE - gap; i++) {
            if(arr[i] > arr[i + gap]) {
                temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
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
    comb_sort();
    display();

    return 0;
}