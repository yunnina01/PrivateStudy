#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

int asc(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void binary_search(int low, int high, int key){
    if(low > high){
        printf("No data about %d\n", key);
        return;
    }
    int mid = (low + high) / 2;
    if(key == arr[mid])
        printf("%d's position is %d\n", key, mid);
    else if(key < arr[mid])
        binary_search(low, mid - 1, key);
    else
        binary_search(mid + 1, high, key);
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
    shuffle(arr);

    while(menu != 99){
        puts("1. Binary Search 2. Shuffle 3. Display 99. Exit");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                binary_search(0, MAX_SIZE - 1, key);
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