#include <stdio.h>
#define MAX_SIZE 10
int temp[MAX_SIZE];

void merge(int *arr, int left, int mid, int right){
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    if(i > mid){
        for(int l = j; l <= right; l++)
            temp[k++] = arr[l];
    }
    else{
        for(int l = i; l <= mid; l++)
            temp[k++] = arr[l];
    }
    for(int l = left; l <= right; l++)
        arr[l] = temp[l];
}

void merge_sort(int *arr, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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
        printf("1. Insert 2. Merge Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                merge_sort(arr, 0, size-1);
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