#include <stdio.h>
#define MAX_SIZE 10

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void cocktail_sort(int *arr, int size){
    for(int i=0; i<size/2; i++){
        for(int j=i+1; j<size-i; j++){
            if(arr[j-1] > arr[j])
                swap(arr, j, j-1);
        }
        for(int j=size-i-2; j>i; j--){
            if(arr[j] < arr[j-1])
                swap(arr, j, j-1);
        }
    }
}

void display(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    puts("");
}

int main(){
    int arr[MAX_SIZE];
    int menu, item, size = 0;

    while(menu != 99){
        printf("1. Insert 2. Cocktail_Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                cocktail_sort(arr, size);
                break;
            case 3:
                display(arr, size);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}