#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], count[30], size;

int get_max(){
    int max = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int get_min(){
    int min = arr[0];
    for(int i = 1; i < size; i++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

void counting_sort(){
    int max = get_max(), min = get_min();
    int range = max - min + 1;
    if(range > 30){
        puts("Counting Sort is inefficient");
        return;
    }
    int i, j, idx = 0;
    for(i = 0; i < size; i++)
        count[arr[i] - min]++;
    for(i = 0; i < range; i++){
        for(j = 0; j < count[i]; j++)
            arr[idx++] = min + i;
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
        puts("1. Insert 2. Counting Sort 3. Display 99. Exit");
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
                counting_sort();
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