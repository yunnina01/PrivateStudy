#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

void init(TreeNode **root){
    *root = NULL;
}

int get_height(TreeNode *node){
    if(!node)
        return 0;
    return 1 + max(get_height(node->left), get_height(node->right));
}

int get_balancefactor(TreeNode *node){
    if(!node)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

TreeNode* LL_rotate(TreeNode *node){
    TreeNode *child = node->left;
    node->left = child->right;
    child->right = node;
    return child;
}

TreeNode* RR_rotate(TreeNode *node){
    TreeNode *child = node->right;
    node->right = child->left;
    child->left = node;
    return child;
}

TreeNode* LR_rotate(TreeNode *node){
    node->left = RR_rotate(node->left);
    return LL_rotate(node);
}

TreeNode* RL_rotate(TreeNode *node){
    node->right = LL_rotate(node->right);
    return RR_rotate(node);
}

TreeNode* AVLset(TreeNode *node){
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

TreeNode* insert(TreeNode *root, int key){
    if(!root){
        TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));
        if(new_node == NULL)
            printf("Memory Allocation Error\n");
        new_node->data = key;
        new_node->left = new_node->right = NULL;
        root = new_node;
    }
    else if(key < root->data){
        root->left = insert(root->left, key);
        root = AVLset(root);
    }
    else if(key > root->data){
        root->right = insert(root->right, key);
        root = AVLset(root);
    }
    else
        printf("Duplicate Key Error\n");
    return root;
}

TreeNode* delete(TreeNode *root, int key){
    if(!root){
        printf("No data about %d\n", key);
        return root;
    }
    if(key < root->data){
        root->left = delete(root->left, key);
        root = AVLset(root);
    }
    else if(key > root->data){
        root->right = delete(root->right, key);
        root = AVLset(root);
    }
    else{
        if(root->left == NULL){
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        TreeNode *temp = root->right;
        while(temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

int main(){
    TreeNode *root;
    int menu, key;
    init(&root);

    while(menu != 99){
        printf("1. Insert 2. Delete 3. Clear 4. Inorder 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &key);
                root = delete(root, key);
                break;
            case 3:
                init(&root);
                break;
            case 4:
                if(root != NULL){
                    inorder(root);
                    puts("");
                    printf("Root Data : %d\n", root->data);
                }   
                else
                    printf("Tree is empty\n");
            case 99:
                break; 
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}