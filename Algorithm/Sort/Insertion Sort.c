#include <stdio.h>
#define MAX_SIZE 10

void insertion_sort(int *arr, int cnt){
    for(int i=1; i<cnt; i++){
        int j, key = arr[i];
        for(j=i-1; j>=0 && key<arr[j]; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void display(int *arr, int cnt){
    for(int i=0; i<cnt; i++){
        printf("%d ", arr[i]);
    }
    puts("");
}

int main(){
    int arr[MAX_SIZE];
    int menu, item, cnt = 0;

    while(menu != 99){
        printf("1. Insert 2. Insertion_Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[cnt++] = item;
                break;
            case 2:
                insertion_sort(arr, cnt);
                break;
            case 3:
                display(arr, cnt);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}