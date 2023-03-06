#include <stdio.h>
#define MAX_SIZE 10
#define min(a,b) (((a) < (b)) ? (a) : (b))
const int RUN = 32; 
    
void insertion_sort(int *arr, int left, int right){ 
    for(int i = left + 1; i <= right; i++){ 
        int j, key = arr[i];
        for(j = i - 1; j >= left && key < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

void merge(int *arr, int left, int mid, int right){
    int len_left = mid - left + 1, len_right = right - mid;
    int arr_left[len_left], arr_right[len_right];
    for(int i = 0; i < len_left; i++)
        arr_left[i] = arr[left + i];
    for(int i = 0; i < len_right; i++)
        arr_right[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while(i < len_left && j < len_right){
        if(arr_left[i] <= arr_right[j])
            arr[k++] = arr_left[i++];
        else
            arr[k++] = arr_right[j++];
    }
    while(i < len_left)
        arr[k++] = arr_left[i++];
    while(j < len_right)
        arr[k++] = arr_right[j++];
}

void tim_sort(int *arr, int size){
    for(int i = 0; i < size; i += RUN)
        insertion_sort(arr, i, min((i + 31), (size - 1)));
    for(int len = RUN; len < size; len *= 2){
        for(int left = 0; left < size; left += len * 2){
            int mid = left + len - 1;
            int right = min((left + len * 2 - 1), (size - 1));
            merge(arr, left, mid, right);
        }
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
        printf("1. Insert 2. Tim Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                tim_sort(arr, size);
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