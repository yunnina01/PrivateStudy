#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *llink, *rlink;
}ListNode;

void init(ListNode **last){
    *last = NULL;
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

int get_length(ListNode *last){
    int cnt = 0;
    if(last != NULL){
        ListNode *temp = last->rlink;
        while(temp != last){
            cnt++;
            temp = temp->rlink;
        }
        cnt++;
    }
    return cnt;
}

void add_last(ListNode **last, int item){
    ListNode *new_node = get_node(item);
    if(new_node == NULL)
        return;
    if(get_length(*last) != 0){
        new_node->llink = *last;
        new_node->rlink = (*last)->rlink;
        (*last)->rlink->llink = new_node;
        (*last)->rlink = new_node;
    }
    *last = new_node;
}

void add_first(ListNode **last, int item){
    add_last(last, item);
    *last = (*last)->llink;
}

void add(ListNode **last, int pos, int item){
    if(pos <= 0 || pos > get_length(*last) + 1)
        printf("Position Input Error\n");
    else if(pos == 1)
        add_first(last, item);
    else if(pos == get_length(*last) + 1)
        add_last(last, item);
    else{
        ListNode *new_node = get_node(item);
        if(new_node == NULL)
            return;
        ListNode *temp = *last;
        for(int i=0; i<pos-1; i++){
            temp = temp->rlink;
        }
        new_node->llink = temp;
        new_node->rlink = temp->rlink;
        temp->rlink->llink = new_node;
        temp->rlink = new_node;
    }
}

void delete(ListNode **last, int pos){
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > get_length(*last))
        printf("This position is empty\n");
    else{
        ListNode *removed = *last;
        for(int i=0; i<pos; i++){
            removed = removed->rlink;
        }
        if(get_length(*last) == 1)
            *last = NULL;
        else{
            if(removed == *last)
                *last = removed->llink;
            removed->llink->rlink = removed->rlink;
            removed->rlink->llink = removed->llink;
        }
        free(removed);
    }
}

void replace(ListNode *last, int pos, int item){
    if(pos <= 0)
        printf("Position Input Error\n");
    else if(pos > get_length(last))
        printf("This position is empty\n");
    else{
        delete(&last, pos);
        add(&last, pos, item);
    }
}

void search(ListNode *last, int item){
    ListNode *temp = last;
    for(int i=1; i<=get_length(last); i++){
        temp = temp->rlink;
        if(temp->data == item){
            printf("%d's position is %d\n", item, i);
            return;
        }
    }
    printf("No data about %d\n", item);
}

void display(ListNode *last){
    if(get_length(last) == 0){
        printf("List is empty\n");
        return;
    }
    ListNode *temp = last;
    for(int i=1; i<=get_length(last); i++){
        temp = temp->rlink;
        printf("[%d] : %d\n", i, temp->data);
    }
}

int main(){
    ListNode *last;
    int menu, item, pos;
    init(&last);
    
    while(menu != 99){
        printf("1. Add_First 2. Add_Last 3. Add 4. Delete 5. Clear 6. Replace 7. Search 8. Length 9. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_first(&last, item);
                break;
            case 2:
                printf("Enter the number : ");
                scanf("%d", &item);
                add_last(&last, item);
                break;
            case 3:
                printf("Enter the position : ");
                scanf("%d", &pos);
                printf("Enter the number : ");
                scanf("%d", &item);
                add(&last, pos, item);
                break;
            case 4:
                printf("Enter the position : ");
                scanf("%d", &pos);
                delete(&last, pos);
                break;
            case 5:
                init(&last);
                break;
            case 6:
                printf("Enter the position : ");
                scanf("%d", &pos);
                printf("Enter the number : ");
                scanf("%d", &item);
                replace(last, pos, item);
                break;
            case 7:
                printf("Enter the number : ");
                scanf("%d", &item);
                search(last, item);
                break;
            case 8:
                printf("List's length is %d\n", get_length(last));
                break;
            case 9:
                display(last);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }
    
    return 0;
}