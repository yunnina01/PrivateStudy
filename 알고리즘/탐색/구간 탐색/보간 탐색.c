/*
정렬된 배열에서 범위를 줄여가며 탐색하는 알고리즘
전화번호부에서 이름을 찾는 방법과 유사
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

// 오름차순
int asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

// 출력
void display() {
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

// 정렬된 테스트 배열 생성 및 출력
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
    qsort(arr, MAX_SIZE, sizeof(int), asc);
    display();
}

// 보간 탐색
void interpolation_search(int key) {
    int low = 0, high = MAX_SIZE - 1, pos;
    while(low < high && key >= arr[low] && key <= arr[high]) {
        pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));
        if(key == arr[pos]) {
            printf("%d's position is %d\n", key, pos);
            return;
        } else if(key < arr[pos])
            high = pos - 1;
        else
            low = pos + 1;
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
            interpolation_search(key);
        }
    }
    return 0;
}