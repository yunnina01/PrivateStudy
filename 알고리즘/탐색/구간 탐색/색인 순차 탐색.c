#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define INDEX_SIZE (MAX_SIZE - 1) / 3 + 1

void sequential_search(int *arr, int key){
    int elements[INDEX_SIZE], indices[INDEX_SIZE];
    int cnt = 0, start, end;
    for(int i = 0; i < MAX_SIZE; i += 3){
        elements[cnt] = arr[i];
        indices[cnt++] = i;
    }
    if(key < elements[0]){
        printf("No data about %d\n", key);
        return;
    }
    else{
        start = indices[cnt - 1];
        end = MAX_SIZE - 1;
        for(int i = 1; i < cnt; i++){
            if(key <= elements[i]){
                start = indices[i - 1];
                end = indices[i];
                break;
            }
        }
    }
    for(int i = start; i <= end; i++){
        if(key == arr[i]){
            printf("%d's position is %d\n", key, i);
            return;
        }
    }
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
        printf("1. Index Sequential Search 2. Shuffle 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                sequential_search(arr, key);
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