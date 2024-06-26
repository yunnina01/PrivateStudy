// 현재 노드보다 값이 작으면 왼쪽 자식에, 크면 오른쪽 자식에 위치하는 BST 구현
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
}Node;

// 트리 초기화
void init(Node **root) {
    *root = NULL;
}

// 노드 삽입
void insert(Node **root, int key) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(!new_node) {
        puts("Memory Allocation Error");
        return;
    }
    new_node->data = key;
    new_node->left = new_node->right = NULL;
    
    Node *p = NULL, *c = *root;
    while(c) {
        if(key == c->data) {
            puts("Duplicate Key Error");
            free(new_node);
            return;
        }
        p = c;
        c = key < c->data ? c->left : c->right;
    }
    if(p) {
        if(key < p->data)
            p->left = new_node;
        else
            p->right = new_node;
    } else
        *root = new_node;
}

// 노드 삭제
void delete(Node **root, int key) {
    Node *p = NULL, *temp = *root;
    while(temp && temp->data != key) {
        p = temp;
        temp = key < temp->data ? temp->left : temp->right;
    }
    if(!temp)
        printf("No data about %d\n", key);
    else if(!temp->left || !temp->right) {
        Node *child = temp->left ? temp->left : temp->right;
        if(p) {
            if(p->left == temp)
                p->left = child;
            else
                p->right = child;
        } else
            *root = child;
        free(temp);
    } else {
        Node *succ = temp->right, *succ_p = temp;
        while(succ->left) {
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

// 노드 탐색
void search(Node *root, int key) {
    int cnt = 1;
    while(root) {
        if(key == root->data) {
            printf("%d's position is level %d\n", key, cnt);
            return;
        } else if(key < root->data)
            root = root->left;
        else
            root = root->right;
        cnt++;
    }
    printf("No data about %d\n", key);
}

int main() {
    Node *root;
    int N, op, key;
    scanf("%d", &N);
    init(&root);
    while(N--) {
        scanf("%d %d", &op, &key);
        // op가 0이면 삽입, 1이면 삭제, 그 외에는 탐색
        if(!op)
            insert(&root, key);
        else if(op == 1)
            delete(&root, key);
        else
            search(root, key);
    }
    return 0;
}