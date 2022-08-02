#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
}ListNode;

typedef struct {
    ListNode *head;
    int length;
}ListType;

void init(ListType **L){
    (*L)->head = NULL;
    (*L)->length = 0;
}

ListNode* get_node(int item){
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    if(new_node == NULL)
        printf("Memory Allocation Error\n");
    else{
        new_node->data = item;
        new_node->link = NULL;
    }
    return new_node;
}

void add_first(ListType **L, int item){
    ListNode *new_node = get_node(item);
    if(new_node == NULL)
        return;
    new_node->link = (*L)->head;
    (*L)->head = new_node;
    (*L)->length++;
}

void add_last(ListType **L, int item){
    ListNode *new_node = get_node(item);
    if(new_node == NULL)
        return;
    ListNode* temp = (*L)->head;
    if(temp == NULL)
        (*L)->head = new_node;
    else{
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = new_node;
    }
    (*L)->length++;
}

void add(ListType **L, int pos, int item){
    if(pos <= 0 || pos > (*L)->length + 1)
        printf("Position Input Error\n");
    else if(pos == 1)
        add_first(L, item);
    else{
        ListNode *new_node = get_node(item);
        if(new_node == NULL)
            return;
        ListNode *temp = (*L)->head;
        for(int i=0; i<pos-2; i++){
            temp = temp->link;
        }
        new_node->link = temp->link;
        temp->link = new_node;
        (*L)->length++;
    }
}

void search(ListType *L, int item){
    ListNode *temp = L->head;
    for(int i=1; i<=L->length; i++){
        if(temp->data == item){
            printf("%d's position is %d\n", item, i);
            return;
        }
        temp = temp->link;
    }
    printf("No data about %d\n", item);
}

void delete(ListType **L, int pos){
    ListNode *temp = (*L)->head;
    ListNode *removed = temp;
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > (*L)->length)
        printf("This position is empty\n");
    else{
        if(pos == 1)
            (*L)->head = removed->link;
        else{
            for(int i=0; i<pos-2; i++){
                temp = temp->link;
            }
            removed = temp->link;
            temp->link = removed->link;
        }
        free(removed);
        (*L)->length--;
    }
}

void replace(ListType *L, int pos, int item){
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > L->length)
        printf("This position is empty\n");
    else{
        add(&L, pos, item);
        delete(&L, pos+1);
    }
}

void display(ListType *L){
    ListNode *temp = L->head;
    if(L->length == 0){
        printf("List is empty\n");
        return;
    }
    for(int i=1; i<=L->length; i++){
        printf("[%d] : %d\n", i, temp->data);
        temp = temp->link;
    }
}

int main(){
    ListType *list;
    int menu, item, pos;
    init(&list);
    
    while(menu != 99){
        printf("1. Add_First 2. Add_Last 3. Add 4. Delete 5. Clear 6. Replace 7. Search 8. Length 9. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_first(&list, item);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_last(&list, item);
                break;
            case 3:
                printf("Enter the position : ");
                scanf("%d", &pos);
                printf("Enter the number : ");
                scanf("%d", &item);
                add(&list, pos, item);
                break;
            case 4:
                printf("Enter the position : ");
                scanf("%d", &pos);
                delete(&list, pos);
                break;
            case 5:
                init(&list);
                break;
            case 6:
                printf("Enter the position : ");
                scanf("%d", &pos);
                printf("Enter the number : ");
                scanf("%d", &item);
                replace(list, pos, item);
                break;
            case 7:
                printf("Enter the number : ");
                scanf("%d", &item);
                search(list, item);
                break;
            case 8:
                printf("List's length is %d\n", list->length);
                break;
            case 9:
                display(list);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }
    
    return 0;
}