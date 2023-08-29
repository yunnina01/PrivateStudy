#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE + 1];

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
    int i;
    arr[MAX_SIZE] = key;
    for(i = 0; key != arr[i]; i++);
    if(i == MAX_SIZE)
        printf("No data about %d\n", key);
    else
        printf("%d's position is %d\n", key, i);
}

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
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