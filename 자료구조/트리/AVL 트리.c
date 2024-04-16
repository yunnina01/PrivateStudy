// 자가 균형 BST인 AVL 트리 구현
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node;

// 큰 값 찾기
int max(int a, int b) {
    return a > b ? a : b;
}

// 트리 초기화
void init(Node **root) {
    *root = NULL;
}

// 노드의 높이
int get_height(Node *node) {
    if(!node)
        return 0;
    return 1 + max(get_height(node->left), get_height(node->right));
}

// 노드의 밸런스 체크
int get_balancefactor(Node *node) {
    if(!node)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

// LL 회전
Node* LL_rotate(Node *node) {
    Node *child = node->left;
    node->left = child->right;
    child->right = node;
    return child;
}

// RR 회전
Node* RR_rotate(Node *node) {
    Node *child = node->right;
    node->right = child->left;
    child->left = node;
    return child;
}

// LR 회전
Node* LR_rotate(Node *node) {
    node->left = RR_rotate(node->left);
    return LL_rotate(node);
}

// RL 회전
Node* RL_rotate(Node *node) {
    node->right = LL_rotate(node->right);
    return RR_rotate(node);
}

// 균형 조절
Node* AVLset(Node *node) {
    if(get_balancefactor(node) >= 2) {
        if(get_balancefactor(node->left) >= 1)
            node = LL_rotate(node);
        else
            node = LR_rotate(node);
    } else if(get_balancefactor(node) <= -2) {
        if(get_balancefactor(node->right) <= -1)
            node = RR_rotate(node);
        else
            node = RL_rotate(node);
    }
    return node;
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
    } else if(key < node->data) {
        node->left = insert(node->left, key);
        node = AVLset(node);
    } else if(key > node->data) {
        node->right = insert(node->right, key);
        node = AVLset(node);
    } else
        puts("Duplicate Key Error");
    return node;
}

// 노드 삭제
Node* delete(Node *node, int key) {
    if(!node) {
        printf("No data about %d\n", key);
        return node;
    }
    if(key < node->data) {
        node->left = delete(node->left, key);
        node = AVLset(node);
    } else if(key > node->data) {
        node->right = delete(node->right, key);
        node = AVLset(node);
    } else {
        if(node->left == NULL || node->right == NULL) {
            Node *temp = node->left ? node->left : node->right;
            free(node);
            return temp;
        }
        Node *temp = node->right;
        while(temp->left)
            temp = temp->left;
        node->data = temp->data;
        node->right = delete(node->right, temp->data);
    }
    return node;
}

// 중위 순회
void inorder(Node *root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    Node *root;
    int N, op, key;
    scanf("%d", &N);
    init(&root);
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 삽입, 1이면 삭제, 그 외에는 중위 순회
        if(!op) {
            scanf("%d", &key);
            root = insert(root, key);
        } else if(op == 1) {
            scanf("%d", &key);
            root = delete(root, key);
        } else {
            if(root) {
                inorder(root);
                puts("");
                printf("Root Data : %d\n", root->data);
            } else
                puts("Tree is empty");
        }
    }
    return 0;
}