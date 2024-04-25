// 각 요소의 크기만큼 1로 채운 2차원 배열을 아래로 밀어 정렬하는 방식
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];
char *bead;

// 테스트 배열 생성
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 20;
}

// 주판 정렬
void bead_sort() {
	int i, j, max, sum, rows;
	for(i = 1, max = arr[0]; i < MAX_SIZE; i++) {
		if(arr[i] > max)
			max = arr[i];
	}

	bead = (char*)calloc(max * MAX_SIZE, sizeof(char));
	for(i = 0; i < MAX_SIZE; i++) {
		rows = i * max;
		for(j = 0; j < arr[i]; j++)
			bead[rows + j] = 1;
	}
	for(j = 0; j < max; j++) {
		for(i = sum = 0; i < MAX_SIZE; i++) {
			rows = i * max;
			sum += bead[rows + j];
			bead[rows + j] = 0;
		}
		for(i = MAX_SIZE - sum; i < MAX_SIZE; i++)
			bead[i * max + j] = 1;
	}

	for(i = 0; i < MAX_SIZE; i++) {
		rows = i * max;
		for(j = 0; j < max && bead[rows + j]; j++);
		arr[i] = j;
	}
}

// 출력
void display() {
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main() {
	init();
	display();
	bead_sort();
	display();

    return 0;
}