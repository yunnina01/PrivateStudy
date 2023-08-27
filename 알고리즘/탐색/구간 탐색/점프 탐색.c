#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define JUMP 3

int sequential_search(int *arr, int left, int right, int key){
    for(int i = left; i <= right; i++){
        if(key == arr[i])
            return i;
    }
    return -1;
}

void jump_search(int *arr, int key){
    if(key < arr[0]){
        printf("No data about %d\n", key);
        return;
    }
    int pos, start, end;
    start = MAX_SIZE - (MAX_SIZE % JUMP);
    end = MAX_SIZE - 1;
    for(int i = JUMP; i < MAX_SIZE; i += JUMP){
        if(key <= arr[i]){
            start = i - JUMP;
            end = i;
            break;
        }
    }
    pos = sequential_search(arr, start, end, key);
    if(pos != -1)
        printf("%d's position is %d\n", key, pos);
    else
        printf("No data about %d\n", key);
}

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void quick_sort(int *arr, int left, int right){
    int i = left - 1;
    int pivot = arr[right];
    for(int j = left; j < right; j++){
        if(arr[j] < pivot)
            swap(arr, ++i, j);
    }
    swap(arr, ++i, right);

    if(left < i)
        quick_sort(arr, left, i - 1);
    if(i < right)
        quick_sort(arr, i + 1, right);
}

void shuffle(int *arr){
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
    quick_sort(arr, 0, MAX_SIZE - 1);
}

void display(int *arr){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int arr[MAX_SIZE];
    shuffle(arr);
    int menu, key;
    
    while(menu != 99){
        printf("1. Jump Search 2. Shuffle 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                jump_search(arr, key);
                break;
            case 2:
                shuffle(arr);
                break;
            case 3:
                display(arr);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}