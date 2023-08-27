#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void selection_sort(){
    int i, j, min, max;
    for(i = 0; i < size / 2; i++){
        min = i, max = size - i - 1;
        for(j = i; j < size - i; j++){
            if(arr[j] < arr[min])
                min = j;
            if(arr[j] > arr[max])
                max = j;
        }
        swap(i, min);
        if(max == i)
            max = min;
        swap(max, size - i - 1);
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
        puts("1. Insert 2. Double Selection Sort 3. Display 99. Exit");
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
                selection_sort();
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