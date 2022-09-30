#include <stdio.h>
#define MAX_SIZE 10

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int quick_sort(int *arr, int left, int right){
    int low = left;
    int high = right;
    int pivot = arr[(left + right) / 2];
    do{
        while(arr[low] < pivot)
            low++;
        while(arr[high] > pivot)
            high--;
        if(low <= high)
            swap(arr, low++, high--);
    }while(low < high);

    if(left < high)
        quick_sort(arr, left, high);
    if(low < right)
        quick_sort(arr, low, right);
}

void display(int *arr, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int arr[MAX_SIZE];
    int menu, item, size = 0;

    while(menu != 99){
        printf("1. Insert 2. Quick Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                quick_sort(arr, 0, size-1);
                break;
            case 3:
                display(arr, size);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}