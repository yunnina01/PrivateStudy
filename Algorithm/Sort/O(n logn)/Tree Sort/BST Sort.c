#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
int size = 0;

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

void init(TreeNode **root){
    *root = NULL;
}

TreeNode* insert(TreeNode *root, int key){
    if(!root){
        TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));
        if(new_node == NULL)
            printf("Memory Allocation Error\n");
        else{
            new_node->data = key;
            new_node->left = new_node->right = NULL;
        }
        root = new_node;
    }
    else if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);
    else
        printf("Duplicate Key Error\n");
    return root;
}

void tree_sort(int *arr, TreeNode *root){
    if(root){
        tree_sort(arr, root->left);
        arr[size++] = root->data;
        tree_sort(arr, root->right);
    }
}

void display(int *arr, int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    puts("");        
}

int main(){
    TreeNode *root;
    int arr[MAX_SIZE];
    int menu, key;
    init(&root);

    while(menu != 99){
        printf("1. Insert 2. BST Sort 3. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                tree_sort(arr, root);
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