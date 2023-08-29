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

void interpolation_search(int key){
    int low = 0, high = MAX_SIZE - 1, pos;
    while(low < high && key >= arr[low] && key <= arr[high]){
        pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));
        if(key == arr[pos]){
            printf("%d's position is %d\n", key, pos);
            return;
        }
        else if(key < arr[pos])
            high = pos - 1;
        else
            low = pos + 1;
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
            interpolation_search(key);
        }
    }

    return 0;
}