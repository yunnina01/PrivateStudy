// 정렬된 배열에서 일정한 간격으로 떨어져 있는 요소를 가진 인덱스 테이블을 이용해 탐색의 효율을 높이는 방법
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define INTERVAL 3
#define INDEX_SIZE (MAX_SIZE - 1) / INTERVAL + 1

int arr[MAX_SIZE], indice[INDEX_SIZE], cnt;

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

// 인덱싱
void indexing() {
    int i;
    for(i = cnt = 0; i < MAX_SIZE; i += INTERVAL, cnt++)
        indice[cnt] = arr[i];
}

// 정렬된 테스트 배열 생성 및 인덱싱, 출력
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
    qsort(arr, MAX_SIZE, sizeof(int), asc);
    indexing();
    display();
}

// 순차 탐색
int sequential_search(int left, int right, int key) {
    for(int i = left; i < right; i++){
        if(key == arr[i])
            return i;
    }
    return -1;
}

// 색인 순차 탐색
void index_search(int key) {
    int i, start, end, pos;
    start = (cnt - 1) * INTERVAL;
    end = MAX_SIZE;
    for(i = 1; i < cnt; i++) {
        if(key < indice[i]) {
            start = (i - 1) * INTERVAL;
            end = i * INTERVAL;
            break;
        }
    }
    pos = sequential_search(start, end, key);
    if(pos != -1)
        printf("%d's position is %d\n", key, i);
    else
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
            index_search(key);
        }
    }
    return 0;
}