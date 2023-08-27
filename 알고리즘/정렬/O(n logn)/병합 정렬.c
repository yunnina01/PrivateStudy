#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], temp[MAX_SIZE], size;

void merge(int left, int mid, int right){
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    if(i > mid){
        for(; j <= right; j++)
            temp[k++] = arr[j];
    }
    else{
        for(; i <= mid; i++)
            temp[k++] = arr[i];
    }
    for(i = left; i <= right; i++)
        arr[i] = temp[i];
}

void merge_sort(int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        merge(left, mid, right);
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
        puts("1. Insert 2. Merge Sort 3. Display 99. Exit");
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
                merge_sort(0, size - 1);
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