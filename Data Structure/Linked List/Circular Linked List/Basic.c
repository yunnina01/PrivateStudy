#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
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
        new_node->link = new_node;
    }
    return new_node;
}

int get_length(ListNode *head){
    int cnt = 0;
    ListNode *temp = head;
    if(temp != NULL){
        while(temp->link != head){
            temp = temp->link;
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
    if(*head != NULL){
        ListNode *temp = *head;
        while(temp->link != *head){
            temp = temp->link;
        }
        new_node->link = temp->link;
        temp->link = new_node;
    }
    *head = new_node;
}

void add_last(ListNode **head, int item){
    add_first(head, item);
    *head = (*head)->link;
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
            temp = temp->link;
        }
        new_node->link = temp->link;
        temp->link = new_node;
    }
}

void delete(ListNode **head, int pos){
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > get_length(*head))
        printf("This position is empty\n");
    else{
        ListNode *temp = *head;
        ListNode *removed = temp;
        if(get_length(*head) == 1)
            *head = NULL;
        else{
            if(pos == 1){
                while(temp->link != removed){
                    temp = temp->link;
                }
                *head = (*head)->link;
            }
            else{
                for(int i=0; i<pos-2; i++){
                    temp = temp->link;
                }
                removed = temp->link;
            }
            temp->link = removed->link;
        }
        free(removed);
    }
}

void replace(ListNode *head, int pos, int item){
    ListNode *temp = head;
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
        temp = temp->link;
    }
    printf("No data about %d\n", item);
}

void display(ListNode *head){
    ListNode *temp = head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    for(int i=1; i<=get_length(head); i++){
        printf("[%d] : %d\n", i, temp->data);
        temp = temp->link;
    }
}

int main(){
    ListNode *head;
    int menu, item, pos;
    init(&head);
    
    while(menu != 99){
        printf("1. Add_First 2. Add_Last 3. Add 4. Delete 5. Clear\n6. Replace 7. Search 8. Length 9. Display 99. Exit\n");
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