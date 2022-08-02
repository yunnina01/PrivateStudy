#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *llink, *rlink;
}ListNode;

void init(ListNode *head){
    head->llink = head->rlink = head;
}

ListNode* get_node(int item){
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    if(new_node == NULL)
        printf("Memory Allocation Error\n");
    else
        new_node->data = item;
    return new_node;
}

int get_length(ListNode *head){
    int cnt = 0;
    ListNode *temp = head->rlink;
    while(temp != head){
        cnt++;
        temp = temp->rlink;
    }
    return cnt;
}

void add(ListNode *head, int pos, int item){
    int length = get_length(head);
    if(pos <= 0 || pos > length + 1)
        printf("Position Input Error\n");
    else{
        ListNode *new_node = get_node(item);
        if(new_node == NULL)
            return;
        ListNode* temp = head;
        for(int i=1; i<pos; i++){
            temp = temp->rlink;
        }
        new_node->llink = temp;
        new_node->rlink = temp->rlink;
        temp->rlink->llink = new_node;
        temp->rlink = new_node;
    }
}

void add_first(ListNode *head, int item){
    add(head, 1, item);
}

void add_last(ListNode *head, int item){
    int length = get_length(head);
    add(head, length + 1, item);
}

void delete(ListNode *head, int pos){
    int length = get_length(head);
    ListNode *removed = head;
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > length)
        printf("This position is empty\n");
    else{
        for(int i=0; i<pos; i++){
            removed = removed->rlink;
        }
        removed->llink->rlink = removed->rlink;
        removed->rlink->llink = removed->llink;
    }
}

void replace(ListNode *head, int pos, int item){
    int length = get_length(head);
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > length)
        printf("This position is empty\n");
    else{
        delete(head, pos);
        add(head, pos, item);
    }
}

void search(ListNode *head, int item){
    int length = get_length(head);
    ListNode *temp = head;
    for(int i=1; i<=length; i++){
        temp = temp->rlink;
        if(temp->data == item){
            printf("%d's position is %d\n", item, i);
            return;
        }
    }
    printf("No data about %d\n", item);
}

void display(ListNode *head){
    int length = get_length(head);
    if(length == 0){
        printf("List is empty\n");
        return;
    }
    ListNode *temp = head;
    for(int i=1; i<=length; i++){
        temp = temp->rlink;
        printf("[%d] : %d\n", i, temp->data);
    }
}

int main(){
    ListNode head_node;
    int menu, item, pos;
    init(&head_node);
    
    while(menu != 99){
        printf("1. Add_First 2. Add_Last 3. Add 4. Delete 5. Clear 6. Replace 7. Search 8. Length 9. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_first(&head_node, item);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_last(&head_node, item);
                break;
            case 3:
                printf("Enter the position : ");
                scanf("%d", &pos);
                printf("Enter the number : ");
                scanf("%d", &item);
                add(&head_node, pos, item);
                break;
            case 4:
                printf("Enter the position : ");
                scanf("%d", &pos);
                delete(&head_node, pos);
                break;
            case 5:
                init(&head_node);
                break;
            case 6:
                printf("Enter the position : ");
                scanf("%d", &pos);
                printf("Enter the number : ");
                scanf("%d", &item);
                replace(&head_node, pos, item);
                break;
            case 7:
                printf("Enter the number : ");
                scanf("%d", &item);
                search(&head_node, item);
                break;
            case 8:
                printf("List's length is %d\n", get_length(&head_node));
                break;
            case 9:
                display(&head_node);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }
    
    return 0;
}