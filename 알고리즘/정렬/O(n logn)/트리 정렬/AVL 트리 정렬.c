#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node *root;
int arr[MAX_SIZE], size;

void init(){
    int i, j, key;
    srand(time(NULL));
    for(i = 0; i < MAX_SIZE; i++){
        key = rand() % 100;
        for(j = 0; j < i; j++){
            if(key == arr[j]){
                key = rand() % 100;
                j = -1;
            }
        }
        root = insert(root, key);
        arr[i] = key;
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

int get_height(Node *node){
    if(!node)
        return 0;
    return 1 + max(get_height(node->left), get_height(node->right));
}

int get_balancefactor(Node *node){
    if(!node)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

Node* LL_rotate(Node *node){
    Node *child = node->left;
    node->left = child->right;
    child->right = node;
    return child;
}

Node* RR_rotate(Node *node){
    Node *child = node->right;
    node->right = child->left;
    child->left = node;
    return child;
}

Node* LR_rotate(Node *node){
    node->left = RR_rotate(node->left);
    return LL_rotate(node);
}

Node* RL_rotate(Node *node){
    node->right = LL_rotate(node->right);
    return RR_rotate(node);
}

Node* AVLset(Node *node){
    if(get_balancefactor(node) >= 2){
        if(get_balancefactor(node->left) >= 1)
            node = LL_rotate(node);
        else
            node = LR_rotate(node);
    }
    else if(get_balancefactor(node) <= -2){
        if(get_balancefactor(node->right) <= -1)
            node = RR_rotate(node);
        else
            node = RL_rotate(node);
    }
    return node;
}

Node* insert(Node *node, int key){
    if(!node){
        Node *new_node = (Node*)malloc(sizeof(Node));
        if(!new_node)
            puts("Memory Allocation Error");
        else{
            new_node->data = key;
            new_node->left = new_node->right = NULL;
        }
        node = new_node;
    }
    else if(key < node->data){
        node->left = insert(node->left, key);
        node = AVLset(node);
    }
    else{
        node->right = insert(node->right, key);
        node = AVLset(node);
    }
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
    for(int i = 0; i < MAX_SIZE; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main(){
    init();
    display();
    tree_sort(root);
    display();

    return 0;
}