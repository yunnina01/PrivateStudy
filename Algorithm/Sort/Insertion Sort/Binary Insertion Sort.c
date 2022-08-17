#include <stdio.h>
#define MAX_SIZE 10

int binary_search(int *arr, int item, int low, int high){
    if(low > high)
        return item > arr[low] ? low + 1 : low;
    int mid = (low + high) / 2;
    if(item == arr[mid])
        return mid + 1;
    if(item > arr[mid])
        return binary_search(arr, item, mid+1, high);
    return binary_search(arr, item, low, mid-1);
}

void binary_insertion_sort(int *arr, int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int pos = binary_search(arr, key, 0, i-1);
        for(int j=i-1; j>=pos; j--){
            arr[j+1] = arr[j];
        }
        arr[pos] = key;
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
        printf("1. Insert 2. Binary_Insertion_Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                binary_insertion_sort(arr, size);
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