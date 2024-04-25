// 힙(Bottom-Top)을 활용한 정렬
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

// 힙 조정
void heapify(int idx, int heap_size) {
    int left = idx * 2 + 1, right = (idx + 1) * 2, max = idx;
    if(left < heap_size && arr[left] > arr[max])
        max = left;
    if(right < heap_size && arr[right] > arr[max])
        max = right;
    if(max != idx) {
        swap(idx, max);
        heapify(max, heap_size);
    }
}

// 힙 정렬
void heap_sort() {
    int heap_size = MAX_SIZE;
    for(int i = (heap_size - 1) / 2; i >= 0; i--)
        heapify(i, heap_size);
    for(int i = MAX_SIZE - 1; i > 0; i--) {
        swap(0, i);
        heapify(0, --heap_size);
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
    heap_sort();
    display();

    return 0;
}