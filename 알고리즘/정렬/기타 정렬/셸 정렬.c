#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void insertion_sort(int left, int right, int gap){
    int i, j, key;
    for(i = left + gap; i <= right; i += gap){
        key = arr[i];
        for(j = i - gap; j >= left && key < arr[j]; j -= gap)
            arr[j + gap] = arr[j];
        arr[j + gap] = key;
    }
}

void shell_sort(){
    int i, gap;
    for(gap = size / 2; gap > 0; gap /= 2){
        for(i = 0; i < gap; i++)
            insertion_sort(i, size - 1, gap);
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
        puts("1. Insert 2. Shell Sort 3. Display 99. Exit");
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
                shell_sort();
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