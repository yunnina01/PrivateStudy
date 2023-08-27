#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void insertion_sort(){
    int i, j, key;
    for(i = 1; i < size; i++){
        key = arr[i];
        for(j = i - 1; j >= 0 && key < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
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
        puts("1. Insert 2. Insertion Sort 3. Display 99. Exit");
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
                insertion_sort();
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