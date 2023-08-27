#include <stdio.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], queue[MAX_SIZE];
int front, rear, size;

void enqueue(int item){
    queue[rear++] = item;
}

int dequeue(){
    return queue[front++];
}

void radix_sort(){
    int i, j, k, digit = 0, factor = 1, max = arr[0];
    for(i = 1; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    for(i = max; i > 0; i /= 10)
        digit++;
    for(i = 0; i < digit; i++){
        for(j = 0; j < 10; j++){
            for(k = 0; k < size; k++){
                if((arr[k] / factor) % 10 == j)
                    enqueue(arr[k]);
            }
        }
        for(j = 0; j < size; j++)
            arr[j] = dequeue();
        factor *= 10;
        front = rear = 0;
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
        puts("1. Insert 2. Radix Sort 3. Display 99. Exit");
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
                radix_sort();
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