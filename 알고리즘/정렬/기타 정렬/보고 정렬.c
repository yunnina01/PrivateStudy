#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 5

int arr[MAX_SIZE], size;

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int is_sorted(){
    for(int i = 1; i < size; i++){
        if(arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

void shuffle(){
    int i, idx;
    for(i = 0; i < size; i++){
        srand(time(NULL));
        idx = rand() % size;
        swap(i, idx);
    }
}

void bogo_sort(){
    while(!is_sorted())
        shuffle();
}

void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int menu, item;

    while(menu != 99){
        puts("1. Insert 2. Bogo Sort 3. Display 99. Exit");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                if(size == MAX_SIZE)
                    puts("Array is full");
                else{
                    printf("Enter the number : ");
                    scanf("%d", &item);
                    arr[size++] = item;
                }
                break;
            case 2:
                bogo_sort();
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