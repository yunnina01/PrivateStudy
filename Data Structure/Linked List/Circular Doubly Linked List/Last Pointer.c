#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *llink, *rlink;
}ListNode;

typedef struct {
    ListNode *last;
    int length;
}DCListType;

void init(DCListType **L){
    (*L)->last = NULL;
    (*L)->length = 0;
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

void add_last(DCListType **L, int item){
    ListNode *new_node = get_node(item);
    if(new_node == NULL)
        return;
    if((*L)->length != 0){
        new_node->llink = (*L)->last;
        new_node->rlink = (*L)->last->rlink;
        (*L)->last->rlink->llink = new_node;
        (*L)->last->rlink = new_node;
    }
    (*L)->last = new_node;
    (*L)->length++;
}

void add_first(DCListType **L, int item){
    ListNode *temp = (*L)->last;
    add_last(L, item);
    if((*L)->last != temp)
        (*L)->last = (*L)->last->llink;
}

void add(DCListType **L, int pos, int item){
    if(pos <= 0 || pos > (*L)->length + 1)
        printf("Position Input Error\n");
    else if(pos == 1)
        add_first(L, item);
    else if(pos == (*L)->length + 1)
        add_last(L, item);
    else{
        ListNode *new_node = get_node(item);
        if(new_node == NULL)
            return;
        ListNode *temp = (*L)->last;
        for(int i=0; i<pos-1; i++){
            temp = temp->rlink;
        }
        new_node->llink = temp;
        new_node->rlink = temp->rlink;
        temp->rlink->llink = new_node;
        temp->rlink = new_node;
        (*L)->length++;
    }
}

void delete(DCListType **L, int pos){
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > (*L)->length)
        printf("This position is empty\n");
    else{
        ListNode *removed = (*L)->last;
        for(int i=0; i<pos; i++){
            removed = removed->rlink;
        }
        if((*L)->length == 1)
            (*L)->last = NULL;
        else{
            if(removed == (*L)->last)
                (*L)->last = removed->llink;
            removed->llink->rlink = removed->rlink;
            removed->rlink->llink = removed->llink;
        }
        free(removed);
        (*L)->length--;
    }
}

void replace(DCListType *L, int pos, int item){
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > L->length)
        printf("This position is empty\n");
    else{
        delete(&L, pos);
        add(&L, pos, item);
    }
}

void search(DCListType *L, int item){
    ListNode *temp = L->last;
    for(int i=1; i<=L->length; i++){
        temp = temp->rlink;
        if(temp->data == item){
            printf("%d's position is %d\n", item, i);
            return;
        }
    }
    printf("No data about %d\n", item);
}

void display(DCListType *L){
    if(L->length == 0){
        printf("List is empty\n");
        return;
    }
    ListNode *temp = L->last;
    for(int i=1; i<=L->length; i++){
        temp = temp->rlink;
        printf("[%d] : %d\n", i, temp->data);
    }
}

int main(){
    DCListType *list;
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
