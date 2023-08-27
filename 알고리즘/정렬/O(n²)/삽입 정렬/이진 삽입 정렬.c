#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

int binary_search(int key, int low, int high){
    if(low > high)
        return key > arr[low] ? low + 1 : low;
    int mid = (low + high) / 2;
    if(key == arr[mid])
        return mid + 1;
    if(key > arr[mid])
        return binary_search(key, mid + 1, high);
    return binary_search(key, low, mid - 1);
}

void insertion_sort(){
    int i, j, key, pos;
    for(i = 1; i < size; i++){
        key = arr[i], pos = binary_search(key, 0, i - 1);
        for(j = i - 1; j >= pos; j--)
            arr[j + 1] = arr[j];
        arr[pos] = key;
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
        puts("1. Insert 2. Binary Insertion Sort 3. Display 99. Exit");
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
                insertion_sort();
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