#include <stdio.h>
#define MAX_SIZE 11
int queue[MAX_SIZE];
int front = 0, rear = 0;

void enqueue(int item){
    if(front % MAX_SIZE == (rear + 1) % MAX_SIZE)
        printf("Queue is full\n");
    else
        queue[++rear % MAX_SIZE] = item;
}

int dequeue(){
    if(front % MAX_SIZE == rear % MAX_SIZE){
        printf("Queue is empty\n");
        return -1;
    }
    return queue[++front % MAX_SIZE];
}

void radix_sort(int *arr, int size){
    int max = arr[0];
    int digit = 0, factor = 1;
    for(int i = 1; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    for(int i = max; i > 0; i /= 10)
        digit++;
    for(int i = 0; i < digit; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < size; k++){
                if((arr[k] / factor) % 10 == j)
                    enqueue(arr[k]);
            }
        }
        for(int i = 0; i < size; i++)
            arr[i] = dequeue();
        factor *= 10;
        front = rear = 0;
    }
}

void display(int *arr, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int arr[MAX_SIZE - 1];
    int menu, item, size = 0;

    while(menu != 99){
        printf("1. Insert 2. Radix Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                arr[size++] = item;
                break;
            case 2:
                radix_sort(arr, size);
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