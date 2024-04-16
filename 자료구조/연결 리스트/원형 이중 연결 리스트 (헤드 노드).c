/*
가장 많이 사용되는 형태인 헤드 노드를 포함한 원형 이중 연결 리스트 구현
헤드 노드를 포함해 구현이 간단
<-> head_node <-> node <-> node <-> node <-> 형태
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
}Node;

Node *head_node;
int length;

// 리스트 초기화
void init() {
    head_node = (Node*)malloc(sizeof(Node));
    head_node->prev = head_node->next = head_node;
}

// 노드 생성
Node* get_node(int item) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(!new_node)
        puts("Memory Allocation Error");
    else
        new_node->data = item;
    return new_node;
}

// 요소 삽입
void insert(int item) {
    Node *new_node = get_node(item);
    if(new_node == NULL)
        return;
    new_node->prev = head_node;
    new_node->next = head_node->next;
    head_node->next->prev = new_node;
    head_node->next = new_node;
    length++;
}

// 요소 삭제
void delete(int pos) {
    if(pos <= 0 || pos > length)
        puts("Position Input Error");
    else {
        Node *removed = head_node;
        for(int i = 0; i < pos; i++)
            removed = removed->next;
        removed->prev->next = removed->next;
        removed->next->prev = removed->prev;
        free(removed);
        length--;
    }
}

// 리스트 출력
void display() {
    if(!length) {
        puts("List is empty");
        return;
    }
    for(Node *temp = head_node->next; temp != head_node; temp = temp->next)
        printf("%d -> ", temp->data);
    puts("");
}

int main() {
    int N, op, pos, item;
    scanf("%d", &N);
    init();
    while(N--) {
        scanf("%d", &op);
        // op가 0이면 삽입, 1이면 삭제, 그 외에는 리스트 출력
        if(!op) {
            scanf("%d", &item);
            insert(item);
        } else if(op == 1) {
            scanf("%d", &pos);
            delete(pos);
        } else
            display();
    }
    return 0;
}