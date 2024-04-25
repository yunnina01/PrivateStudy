/*
평균적으로 빠른 성능을 내며 최악의 조건에도 점진적으로 최적화된 성능을 내는 정렬
퀵 정렬로 시작하며 재귀 깊이가 정렬 대상 요소 수의 레벨을 초과할 때는 힙 정렬로 전환하며,
요소들의 수가 특정 임계치 미만일 때는 삽입 정렬로 전환
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
	for(int i = (MAX_SIZE - 1) / 2; i >= 0; i--)
		heapify(i, heap_size);
	for(int i = MAX_SIZE - 1; i > 0; i--) {
	    swap(0, i);
		heapify(0, --heap_size);
	}
}

// 파티션 인덱스 반환
int partition(int left, int right) {
    int i = left, j = left, pivot = arr[right];
    for(; j < right; j++) {
        if(arr[j] < pivot)
            swap(i++, j);
    }
    swap(i, right);
    return i;
}

// 인트로 정렬
void intro_sort(int left, int right, int depth) {
    if(MAX_SIZE < 16)
        insertion_sort();
    else if(!depth)
        heap_sort();
    else{
        int p = partition(0, MAX_SIZE - 1);
        intro_sort(left, p - 1, depth - 1);
        intro_sort(p + 1, right, depth - 1);
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
    intro_sort(0, MAX_SIZE - 1, log2(MAX_SIZE) * 2);
    display();

    return 0;
}