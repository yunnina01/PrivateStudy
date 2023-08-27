#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

int asc(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int sequential_search(int left, int right, int key){
    for(int i = left; i <= right; i++){
        if(key == arr[i])
            return i;
    }
    return -1;
}

void exponential_search(int key){
    if(key < arr[0]){
        printf("No data about %d\n", key);
        return;
    }
    int pos, start, end;
    start = pow(2, (int)log2(MAX_SIZE));
    end = MAX_SIZE - 1;
    for(int i = 1; i < MAX_SIZE; i *= 2){
        if(key <= arr[i]){
            start = i / 2;
            end = i;
            break;
        }
    }
    pos = sequential_search(start, end, key);
    if(pos != -1)
        printf("%d's position is %d\n", key, pos);
    else
        printf("No data about %d\n", key);
}

void shuffle(){
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
    qsort(arr, MAX_SIZE, sizeof(int), asc);
}

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int menu, key;
    shuffle();

    while(menu != 99){
        puts("1. Exponential Search 2. Shuffle 3. Display 99. Exit");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                exponential_search(key);
                break;
            case 2:
                shuffle();
                break;
            case 3:
                display();
            case 99:
                break;
            default:
                puts("Menu Selection Error");
        }
    }

    return 0;
}