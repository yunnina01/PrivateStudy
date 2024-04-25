// 삼분 탐색(반복)으로, 배열은 정렬되어 있어야 함
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

// 오름차순
int asc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

// 추렭
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

// 삼분 탐색
void ternary_search(int key) {
    int low = 0, high = MAX_SIZE - 1;
    while(low <= high) {
        int mid1 = low + (high - low) / 3, mid2 = high - (high - low) / 3;
        if(key == arr[mid1]) {
            printf("%d's position is %d\n", key, mid1);
            return;
        }
        if(key == arr[mid2]) {
            printf("%d's position is %d\n", key, mid2);
            return;
        }
        if(key < arr[mid1])
            high = mid1 - 1;
        else if(key > arr[mid2])
            low = mid2 + 1;
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
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
            ternary_search(key);
        }
    }
    return 0;
}