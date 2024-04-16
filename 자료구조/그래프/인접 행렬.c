// 인접 행렬을 이용하여 구현
#include <stdio.h>
#define MAX_SIZE 5                                              // 그래프 정점 개수

int graph[MAX_SIZE + 1][MAX_SIZE + 1];

// 간선 삽입
void insert(int start, int end) {
    if(start > MAX_SIZE || end > MAX_SIZE || start == end) {
        puts("Edge Input Error");
        return;
    }
    graph[start][end] = 1;
}

// 간선 삭제
void delete(int start, int end) {
    if(start > MAX_SIZE || end > MAX_SIZE) {
        puts("Edge Input Error");
        return;
    }
    graph[start][end] = 0;
}

// 그래프 출력
void display() {
    for(int i = 1; i <= MAX_SIZE; i++) {
        for(int j = 1; j <= MAX_SIZE; j++)
            printf("%d ", graph[i][j]);
        puts("");
    }
}

int main() {
    int N, op, start, end;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 삽입, 1이면 삭제, 그 외에는 출력
        if(!op) {
            scanf("%d %d", &start, &end);
            insert(start, end);
        } else if(op == 1) {
            scanf("%d %d", &end);
            delete(start, end);
        } else
            display();
    }
    return 0;
}