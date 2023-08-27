#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node *root;
int arr[MAX_SIZE], size;

Node* insert(Node *node, int key){
    if(!node){
        Node *new_node = (Node*)malloc(sizeof(Node));
        if(new_node == NULL)
            puts("Memory Allocation Error");
        else{
            new_node->data = key;
            new_node->left = new_node->right = NULL;
        }
        node = new_node;
    }
    else if(key < node->data)
        node->left = insert(node->left, key);
    else if(key > node->data)
        node->right = insert(node->right, key);
    else
        puts("Duplicate Key Error");
    return node;
}

void tree_sort(Node *root){
    if(root){
        tree_sort(root->left);
        arr[size++] = root->data;
        tree_sort(root->right);
    }
}

void display(){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");        
}

int main(){
    int menu, key;

    while(menu != 99){
        puts("1. Insert 2. BST Sort 3. Display 99. Exit");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                tree_sort(root);
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