#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

void init(){
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
    display();
}

void sequential_search(int key){
    for(int i = 0; i < MAX_SIZE; i++){
        if(key == arr[i]){
            printf("%d's position is %d\n", key, i);
            return;
        }
    }
    printf("No data about %d\n", key);
}

int main(){
    int N, op, key;
    scanf("%d", &N);
    init();
    while(N--){
        scanf("%d", &op);
        if(!op)
            init();
        else{
            scanf("%d", &key);
            sequential_search(key);
        }
    }
    
    return 0;
}