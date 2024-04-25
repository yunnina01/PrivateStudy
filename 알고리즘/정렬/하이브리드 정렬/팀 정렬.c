// 병합 정렬을 기반으로 삽입 정렬을 추가한 하이브리드 정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

const int RUN = 32;
int arr[MAX_SIZE];

// 테스트 배열 생성
void init() {
    srand(time(NULL));
    for(int i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % 100;
}

// 작은 값 반환
int min(int a, int b) {
    return a < b ? a : b;
}

// 삽입 정렬
void insertion_sort(int left, int right){  
    int i, j, key;
    for(i = left + 1; i <= right; i++){ 
        key = arr[i];
        for(j = i - 1; j >= left && key < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

// 병합
void merge(int left, int mid, int right) {
    int len_left = mid - left + 1, len_right = right - mid;
    int arr_left[len_left], arr_right[len_right];
    for(int i = 0; i < len_left; i++)
        arr_left[i] = arr[left + i];
    for(int i = 0; i < len_right; i++)
        arr_right[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while(i < len_left && j < len_right) {
        if(arr_left[i] <= arr_right[j])
            arr[k++] = arr_left[i++];
        else
            arr[k++] = arr_right[j++];
    }
    while(i < len_left)
        arr[k++] = arr_left[i++];
    while(j < len_right)
        arr[k++] = arr_right[j++];
}

// 팀 정렬
void tim_sort() {
    int i, len, left, mid, right;
    for(i = 0; i < MAX_SIZE; i += RUN)
        insertion_sort(i, min((i + 31), (MAX_SIZE - 1)));
    for(len = RUN; len < MAX_SIZE; len *= 2) {
        for(left = 0; left < MAX_SIZE; left += len * 2) {
            mid = left + len - 1;
            right = min((left + len * 2 - 1), (MAX_SIZE - 1));
            merge(left, mid, right);
        }
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
    tim_sort();
    display();
    
    return 0;
}