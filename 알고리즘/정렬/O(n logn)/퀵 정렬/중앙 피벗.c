#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void swap(int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int quick_sort(int left, int right){
    int i = left, j = right;
    int pivot = arr[(i + j) / 2];
    do{
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j)
            swap(i++, j--);
    }while(i < j);

    if(left < j)
        quick_sort(left, j);
    if(i < right)
        quick_sort(i, right);
}

void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int menu, item;

    while(menu != 99){
        puts("1. Insert 2. Quick Sort 3. Display 99. Exit");
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
                quick_sort(0, size - 1);
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