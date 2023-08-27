#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void comb_sort(){
    double shrink = 1.3;
    int i, temp, gap = size;
    while(gap > 1){
        gap /= shrink;
        for(i = 0; i < size - gap; i++){
            if(arr[i] > arr[i + gap]){
                temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
            }
        }
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
        puts("1. Insert 2. Comb Sort 3. Display 99. Exit");
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
                comb_sort();
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