// 삽입 정렬에 이진 탐색을 추가한 정렬 방식
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

// 이진 탐색
int binary_search(int key, int low, int high) {
    if(low > high)
        return key > arr[low] ? low + 1 : low;
    int mid = (low + high) >> 1;
    if(key == arr[mid])
        return mid + 1;
    if(key > arr[mid])
        return binary_search(key, mid + 1, high);
    return binary_search(key, low, mid - 1);
}

// 삽입 정렬
void insertion_sort() {
    int i, j, key, pos;
    for(i = 1; i < MAX_SIZE; i++) {
        key = arr[i], pos = binary_search(key, 0, i - 1);
        for(j = i - 1; j >= pos; j--)
            arr[j + 1] = arr[j];
        arr[pos] = key;
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