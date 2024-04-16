// 절댓값이 작은 수부터 우선 추출하는 절댓값 힙 구현
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int heap[MAX_SIZE], cnt;

// 요소 값 swap
void swap(int a, int b) {
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}

// 삽입이나 추출 후 힙 정렬
void heapify(int idx, int size) {
    int left = idx * 2 + 1, right = (idx + 1) * 2, min = idx;
    if(left < size){
        if(abs(heap[left]) < abs(heap[min]))
            min = left;
        else if(abs(heap[left]) == abs(heap[min]) && heap[left] < heap[min])
            min = left;
    }
    if(right < size) {
        if(abs(heap[right]) < abs(heap[min]))
            min = right;
        else if(abs(heap[right]) == abs(heap[min]) && heap[right] < heap[min])
            min = right;
    }
    if(min != idx) {
        swap(idx, min);
        heapify(min, size);
    }
}

// 요소 삽입
void push(int item) {
    if(cnt == MAX_SIZE) {
        puts("Heap is full");
        return;
    }
    int i = cnt;
    heap[cnt++] = item;
    do {
        i = (i - 1) / 2;
        heapify(i, cnt);
    }while(i);
}

// 요소 추출
void pop() {
    if(!cnt) {
        puts("Heap is empty");
        return;
    }
    printf("%d\n", heap[0]);
    swap(0, --cnt);
    heapify(0, cnt);
}

int main() {
    int N, op, item;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 삽입, 그 외에는 추출
        if(!op) {
            scanf("%d", &item);
            push(item);
        } else
            pop();
    }
    return 0;
}