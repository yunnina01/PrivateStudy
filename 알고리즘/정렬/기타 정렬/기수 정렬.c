// 일의 자릿수부터 자릿수별로 순차적으로 정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], queue[MAX_SIZE];
int front, rear;

// 테스트 배열 생성
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
}

// 요소 삽입
void enqueue(int item) {
    queue[rear++] = item;
}

// 요소 추출
int dequeue() {
    return queue[front++];
}

// 기수 정렬
void radix_sort() {
    int i, j, k, digit = 0, factor = 1, max = arr[0];
    for(i = 1; i < MAX_SIZE; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    for(i = max; i > 0; i /= 10)
        digit++;
    for(i = 0; i < digit; i++) {
        for(j = 0; j < 10; j++) {
            for(k = 0; k < MAX_SIZE; k++) {
                if((arr[k] / factor) % 10 == j)
                    enqueue(arr[k]);
            }
        }
        for(j = 0; j < MAX_SIZE; j++)
            arr[j] = dequeue();
        factor *= 10;
        front = rear = 0;
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
    radix_sort();
    display();

    return 0;
}