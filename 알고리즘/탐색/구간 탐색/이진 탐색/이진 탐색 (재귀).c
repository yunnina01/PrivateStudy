#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

int asc(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

void init(){
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
    qsort(arr, MAX_SIZE, sizeof(int), asc);
    display();
}

void binary_search(int low, int high, int key){
    if(low > high){
        printf("No data about %d\n", key);
        return;
    }
    int mid = (low + high) >> 1;
    if(key == arr[mid])
        printf("%d's position is %d\n", key, mid);
    else if(key < arr[mid])
        binary_search(low, mid - 1, key);
    else
        binary_search(mid + 1, high, key);
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
            binary_search(0, MAX_SIZE - 1, key);
        }
    }

    return 0;
}