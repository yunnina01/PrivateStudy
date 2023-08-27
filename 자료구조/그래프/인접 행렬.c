#include <stdio.h>
#define MAX_SIZE 5

int graph[MAX_SIZE + 1][MAX_SIZE + 1];

void insert(int start, int end){
    if(start > MAX_SIZE || end > MAX_SIZE || start == end){
        puts("Edge Input Error");
        return;
    }
    graph[start][end] = 1;
}

void delete(int start, int end){
    if(start > MAX_SIZE || end > MAX_SIZE){
        puts("Edge Input Error");
        return;
    }
    graph[start][end] = 0;
}

void display(){
    int i, j;
    for(i = 1; i <= MAX_SIZE; i++){
        for(j = 1; j <= MAX_SIZE; j++)
            printf("%d ", graph[i][j]);
        puts("");
    }
}

int main(){
    int N, op, start, end;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d %d", &start, &end);
            insert(start, end);
        }
        else if(op == 1){
            scanf("%d %d", &end);
            delete(start, end);
        }
        else
            display();
    }

    return 0;
}