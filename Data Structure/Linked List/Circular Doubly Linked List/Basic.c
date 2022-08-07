#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *llink, *rlink;
}ListNode;

void init(ListNode **head){
    *head = NULL;
}

ListNode* get_node(int item){
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    if(new_node == NULL)
        printf("Memory Allocation Error\n");
    else{
        new_node->data = item;
        new_node->llink = new_node->rlink = new_node;
    }
    return new_node;
}

int get_length(ListNode *head){
    ListNode *temp = head;
    int cnt = 0;
    if(temp != NULL){
        while(temp->rlink != head){
            temp = temp->rlink;
            cnt++;
        }
        cnt++;
    }
    return cnt;
}

void add_first(ListNode **head, int item){
    ListNode *new_node = get_node(item);
    if(new_node == NULL)
        return;
    if((*head) != NULL){
        new_node->llink = (*head)->llink;
        new_node->rlink = (*head);
        (*head)->llink->rlink = new_node;
        (*head)->llink = new_node;
    }
    *head = new_node;
}

void add_last(ListNode **head, int item){
    add_first(head, item);
    *head = (*head)->rlink;
}

void add(ListNode **head, int pos, int item){
    if(pos <= 0 || pos > get_length(*head) + 1)
        printf("Position Input Error\n");
    else if(pos == 1)
        add_first(head, item);
    else{
        ListNode *new_node = get_node(item);
        if(new_node == NULL)
            return;
        ListNode *temp = *head;
        for(int i=0; i<pos-2; i++){
            temp = temp->rlink;
        }
        new_node->llink = temp;
        new_node->rlink = temp->rlink;
        temp->rlink->llink = new_node;
        temp->rlink = new_node;
    }
}

void delete(ListNode **head, int pos){
    ListNode *removed = *head;
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > get_length(*head))
        printf("This position is empty\n");
    else{
        if(get_length(*head) == 1)
            *head = NULL;
        else{
            for(int i=0; i<pos-1; i++){
                removed = removed->rlink;
            }
            if(pos == 1)
                *head = (*head)->rlink;
            removed->llink->rlink = removed->rlink;
            removed->rlink->llink = removed->llink;
        }
        free(removed);
    }
}

void replace(ListNode *head, int pos, int item){
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > get_length(head))
        printf("This position is empty\n");
    else{
        delete(&head, pos);
        add(&head, pos, item);
    }
}

void search(ListNode *head, int item){
    ListNode *temp = head;
    for(int i=1; i<=get_length(head); i++){
        if(temp->data == item){
            printf("%d's position is %d\n", item, i);
            return;
        }
        temp = temp->rlink;
    }
    printf("No data about %d\n", item);
}

void display(ListNode *head){
    if(get_length(head) == 0){
        printf("List is empty\n");
        return;
    }
    ListNode *temp = head;
    for(int i=1; i<=get_length(head); i++){
        printf("[%d] : %d\n", i, temp->data);
        temp = temp->rlink;
    }
}

int main(){
    ListNode *head;
    int menu, item, pos;
    init(&head);
    
    while(menu != 99){
        printf("1. Add_First 2. Add_Last 3. Add 4. Delete 5. Clear 6. Replace 7. Search 8. Length 9. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_first(&head, item);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_last(&head, item);
                break;
            case 3:
                printf("Enter the position : ");
                scanf("%d", &pos);
                printf("Enter the number : ");
                scanf("%d", &item);
                add(&head, pos, item);
                break;
            case 4:
                printf("Enter the position : ");
                scanf("%d", &pos);
                delete(&head, pos);
                break;
            case 5:
                init(&head);
                break;
            case 6:
                printf("Enter the position : ");
                scanf("%d", &pos);
                printf("Enter the number : ");
                scanf("%d", &item);
                replace(head, pos, item);
                break;
            case 7:
                printf("Enter the number : ");
                scanf("%d", &item);
                search(head, item);
                break;
            case 8:
                printf("List's length is %d\n", get_length(head));
                break;
            case 9:
                display(head);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }
    
    return 0;
}