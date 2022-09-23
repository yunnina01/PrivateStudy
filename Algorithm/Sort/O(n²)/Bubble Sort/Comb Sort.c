#include <stdio.h>
#define MAX_SIZE 10

void comb_sort(int *arr, int size){
    double shrink = 1.3;
    int gap = size;
    while(gap != 1){
        gap /= shrink;
        for(int i = 0; i < size - gap; i++){
            if(arr[i] > arr[i + gap]){
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
            }
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
        printf("1. Insert 2. Comb Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                comb_sort(arr, size);
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