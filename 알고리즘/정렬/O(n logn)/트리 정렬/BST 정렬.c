// 이진 탐색 트리(BST)를 활용한 트리 정렬
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

// 노드 구조체
typedef struct Node {
    int data;
    struct Node *left, *right;
}Node;

Node *root;
int arr[MAX_SIZE], size;

// 테스트 배열 생성
void init() {
    int i, j, key;
    srand(time(NULL));
    for(i = 0; i < MAX_SIZE; i++) {
        key = rand() % 100;
        for(j = 0; j < i; j++) {
            if(key == arr[j]) {
                key = rand() % 100;
                j = -1;
            }
        }
        root = insert(root, key);
        arr[i] = key;
    }
}

// 노드 삽입
Node* insert(Node *node, int key) {
    if(!node) {
        Node *new_node = (Node*)malloc(sizeof(Node));
        if(!new_node)
            puts("Memory Allocation Error");
        else {
            new_node->data = key;
            new_node->left = new_node->right = NULL;
        }
        node = new_node;
    } else if(key < node->data)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

// 트리 정렬
void tree_sort(Node *root) {
    if(root) {
        tree_sort(root->left);
        arr[size++] = root->data;
        tree_sort(root->right);
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
    tree_sort(root);
    display();
    
    return 0;
}