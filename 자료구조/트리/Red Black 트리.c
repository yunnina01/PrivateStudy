// 노드 삽입만 구현
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node{
    int data, color;
    struct Node *parent, *left, *right;
}Node;
 
Node *root;

Node* get_node(int key){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(!new_node)
        puts("Memory Allocation Error");
    else{
        new_node->data = key;
        new_node->color = 1;
        new_node->parent = new_node->left = new_node->right = NULL;
    }
    return new_node;
}

Node* insert(Node *node, Node *new_node){
    if(!node)
        node = new_node;
    if(new_node->data < node->data){
        node->left = insert(node->left, new_node);
        node->left->parent = node;
    }
    else if(new_node->data > node->data){
        node->right = insert(node->right, new_node);
        node->right->parent = node;
    }
    return node;
}

void left_rotate(Node *node){
    Node *child = node->right;
    node->right = child->left;
    if(!node->right)
        node->right->parent = node;
    child->parent = node->parent;
    if(!node->parent)
        root = child;
    else if(node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;
    child->left = node;
    node->parent = child;
}

void right_rotate(Node *node){
    Node *child = node->left;
    node->left = child->right;
    if(!node->left)
        node->left->parent = node;
    child->parent = node->parent;
    if(!node->parent)
        root = child;
    else if(node == node->parent->left)
        node->parent->left = child;
    else
        node->parent->right = child;
    child->right = node;
    node->parent = child;
}

void RBTset(Node **root, Node *node){
    while((node != *root) && (node->color == 1) && (node->parent->color == 1)){
        Node *parent = node->parent;
        Node *grand_parent = node->parent->parent;
        if(parent == grand_parent->left){
            Node *uncle = grand_parent->right;
            if(uncle && uncle->color == 1){
                grand_parent->color = 1;
                parent->color = uncle->color = 0;
                node = grand_parent;
            }
            else{
                if(node == parent->right){
                    left_rotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                right_rotate(grand_parent);
                parent->color = 0;
                grand_parent->color = 1;
                node = parent;
            }
        }
        else{
            Node *uncle = grand_parent->left;
            if(uncle && uncle->color == 1){
                grand_parent->color = 1;
                parent->color = uncle->color = 0;
                node = grand_parent;
            }
            else{
                if(node == parent->left){
                    right_rotate(parent);
                    node = parent;
                    parent = node->parent;
                }
                left_rotate(grand_parent);
                parent->color = 0;
                grand_parent->color = 1;
                node = parent;
            }
        }
    }
    (*root)->color = 0;
}

void inorder(Node *node){
    if(node){
        inorder(node->left);
        if(node->color == 0)
            printf("%d[B] ", node->data);
        else
            printf("%d{R] ", node->data);
        inorder(node->right);
    }
}
 
int main(){
    int N, op, key;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &op);
        if(!op){
            scanf("%d", &key);
            Node *new_node = get_node(key);
            root = insert(root, new_node);
            RBTset(&root, new_node);
        }
        else{
            if(root){
                inorder(root);
                printf("Root Data : %d\n", root->data);
            }
            else
                puts("Tree is empty");
        }
    }

    return 0;
}