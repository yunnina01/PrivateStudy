#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

void init(TreeNode **root){
    *root = NULL;
}

void insert(TreeNode **root, int key){
    TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));
    if(new_node == NULL){
        printf("Memory Allocation Error\n");
        return;
    }
    new_node->data = key;
    new_node->left = new_node->right = NULL;
    
    TreeNode *p = NULL;
    TreeNode *temp = *root;
    while(temp != NULL){
        if(key == temp->data){
            printf("Duplicate Key Error\n");
            return;
        }
        p = temp;
        if(key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if(p != NULL){
        if(key < p->data)
            p->left = new_node;
        else
            p->right = new_node;
    }
    else
        *root = new_node;
}

void delete(TreeNode **root, int key){
    TreeNode *p = NULL;
    TreeNode *temp = *root;
    TreeNode *child, *succ, *succ_p;
    while(temp != NULL && temp->data != key){
        p = temp;
        temp = key < temp->data ? temp->left : temp->right;
    }
    if(temp == NULL){
        printf("%d is not in the tree\n", key);
        return;
    }
    if(temp->left == NULL || temp->right == NULL){
        child = temp->left != NULL ? temp->left : temp->right;
        if(p != NULL){
            if(p->left == temp)
                p->left = child;
            else
                p->right = child;
        }
        else
            *root = child;
    }
    else{
        succ = temp->right;
        while(succ->left != NULL){
            succ_p = succ;
            succ = succ->left;
        }
        if(succ_p->left == succ)
            succ_p->left = succ->right;
        else
            succ_p->right = succ->right;
        temp->data = succ->data;
        free(succ);
    }
}

int get_node_count(TreeNode *root){
    int cnt = 0;
    if(root)
        cnt = 1 + get_node_count(root->left) + get_node_count(root->right);
    return cnt;
}

int get_height(TreeNode *root){
    int cnt = 0;
    if(root)
        cnt = 1 + max(get_height(root->left), get_height(root->right));
    return cnt;
}

void search(TreeNode *root, int key){
    int cnt = 1;
    while(root != NULL){
        if(key == root->data){
            printf("%d's position is level %d\n", key, cnt);
            return;
        }
        else if(key < root->data)
            root = root->left;
        else
            root = root->right;
        cnt++;
    }
    printf("No data about %d\n", key);
}

void preorder(TreeNode *root){
    if(root){
        printf("%d  ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d  ", root->data);
    }
}

int main(){
    TreeNode *root;
    int menu, key;
    init(&root);
    
    while(menu != 99){
        printf("1. Insert 2. Delete 3. Clear 4. Node_Count 5. Height 6. Search 7. Preorder 8. Inorder 9. Postorder 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &key);
                insert(&root, key);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &key);
                delete(&root, key);
                break;
            case 3:
                init(&root);
                break;
            case 4:
                printf("The number of nodes in the tree is %d\n", get_node_count(root));
                break;
            case 5:
                printf("Tree's height is %d\n", get_height(root));
                break;
            case 6:
                printf("Enter the number : ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 7:
                if(get_node_count(root) == 0)
                    printf("Tree is empty");
                else
                    preorder(root);
                puts("");
                break;
            case 8:
                if(get_node_count(root) == 0)
                    printf("Tree is empty");
                else
                    inorder(root);
                puts("");
                break;
            case 9:
                if(get_node_count(root) == 0)
                    printf("Tree is empty");
                else
                    postorder(root);
                puts("");
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }
    
    return 0;
}
