#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void cocktail_sort(){
    int i, j;
    for(i = 0; i < size / 2; i++){
        for(j = i + 1; j < size - i; j++){
            if(arr[j - 1] > arr[j])
                swap(j - 1, j);
        }
        for(j--; j > i; j--){
            if(arr[j] < arr[j - 1])
                swap(j, j - 1);
        }
    }
}

void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int menu, item;

    while(menu != 99){
        puts("1. Insert 2. Cocktail Sort 3. Display 99. Exit");
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
                cocktail_sort();
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