#include <stdio.h>
#define MAX_SIZE 10

void bubble_sort(int *arr, int cnt){
    for(int i=0; i<cnt-1; i++){
        for(int j=0; j<cnt-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
        printf("1. Insert 2. Bubble_Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[cnt++] = item;
                break;
            case 2:
                bubble_sort(arr, cnt);
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