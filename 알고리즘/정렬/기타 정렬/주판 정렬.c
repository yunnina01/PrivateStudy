#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int arr[MAX_SIZE], size;

void bead_sort(){
	int i, j, max, sum;
	for(i = 1, max = arr[0]; i < size; i++){
		if(arr[i] > max)
			max = arr[i];
	}
	char *bead = (char*)calloc(sizeof(char), max * size);
	for(i = 0; i < size; i++){
		for(j = 0; j < arr[i]; j++)
			bead[i * max + j] = 1;
	}
	for(j = 0; j < max; j++){
		for(i = sum = 0; i < size; i++){
			sum += bead[i * max + j];
			bead[i * max + j] = 0;
		}
		for(i = size - sum; i < size; i++)
			bead[i * max + j] = 1;
	}
	for(i = 0; i < size; i++){
		for(j = 0; j < max && bead[i * max + j]; j++);
		arr[i] = j;
	}
	free(bead);
}

void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
	int menu, item;

	while(menu != 99){
		puts("1. Insert 2. Bead Sort 3. Display 99. Exit");
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
				bead_sort();
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