#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE + 1];

void sequential_search(int key){
    int i;
    arr[MAX_SIZE] = key;
    for(i = 0; key != arr[i]; i++);
    if(i == MAX_SIZE)
        printf("No data about %d\n", key);
    else
        printf("%d's position is %d\n", key, i);
}

void shuffle(){
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
}

void display(){
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    int menu, key;
    shuffle();

    while(menu != 99){
        puts("1. Sequential Search 2. Shuffle 3. Display 99. Exit");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                sequential_search(key);
                break;
            case 2:
                shuffle();
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