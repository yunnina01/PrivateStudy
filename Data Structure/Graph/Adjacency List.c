#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

typedef struct GraphNode{
    int vertex;
    struct GraphNode *link;
}GraphNode;

typedef struct {
    int n;
    GraphNode *adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType *G){
    G->n = 0;
    for(int i = 0; i < MAX_VERTICES; i++)
        G->adj_list[i] = NULL;
}

void insert_vertex(GraphType *G){
    if(G->n + 1 > MAX_VERTICES){
        printf("Graph is full\n");
        return;
    }
    G->n++;
}

void insert_edge(GraphType *G, int start, int end){
    if(start >= G->n || end >= G->n){
        printf("Edge Input Error\n");
        return;
    }
    if(start == end){
        printf("Edge Input Error\n");
        return;
    }
    GraphNode *new_node = (GraphNode*)malloc(sizeof(GraphNode));
    if(new_node == NULL){
        printf("Memory Allocation Error\n");
        return;
    }
    new_node->vertex = end;
    new_node->link = G->adj_list[start];
    G->adj_list[start] = new_node;
}

void delete_edge(GraphType *G, int start, int end){
    if(start >= G->n || end >= G->n){
        printf("Edge Input Error\n");
        return;
    }
    GraphNode *removed, *temp;
    removed = G->adj_list[start];
    while(removed != NULL){
        if(removed->vertex == end){
            if(removed == G->adj_list[start])
                G->adj_list[start] = removed->link;
            else
                temp->link = removed->link;
            free(removed);
            break;
        }
        temp = removed;
        removed = removed->link;
    }
}

void delete_vertex(GraphType *G, int v){
    if(v >= G->n){
        printf("Vertex Input Error\n");
        return;
    }
    for(int i = v; i < G->n - 1; i++)
        G->adj_list[i] = G->adj_list[i + 1];
    G->adj_list[--G->n] = NULL;
    for(int i = 0; i < G->n; i++){
        GraphNode *temp = G->adj_list[i];
        while(temp != NULL){
            if(temp->vertex == v){
                delete_edge(G, i, v);
                break;
            }
            temp = temp->link;
        }
        temp = G->adj_list[i];
        while(temp != NULL){
            if(temp->vertex > v)
                temp->vertex--;
            temp = temp->link;
        }
    }
}

void display(GraphType *G){
    for(int i = 0; i < G->n; i++){
        printf("Vertex %d : ", i);
        GraphNode *temp = G->adj_list[i];
        while(temp != NULL){
            printf("%d -> ", temp->vertex);
            temp = temp->link;
        }
        puts("");
    }
}

int main(){
    GraphType g;
    int menu, start, end, vertex;
    init(&g);

    while(menu != 99){
        printf("1. Insert_Vertex 2. Insert_Edge 3. Delete_Vertex 4. Delete_Edge 5. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                insert_vertex(&g);
                break;
            case 2:
                printf("Enter the start position : ");
                scanf("%d", &start);
                printf("Enter the end position : ");
                scanf("%d", &end);
                insert_edge(&g, start, end);
                insert_edge(&g, end, start);
                break;
            case 3:
                printf("Enter the number : ");
                scanf("%d", &vertex);
                delete_vertex(&g, vertex);
                break;
            case 4:
                printf("Enter the start position : ");
                scanf("%d", &start);
                printf("Enter the end position : ");
                scanf("%d", &end);
                delete_edge(&g, start, end);
                delete_edge(&g, end, start);
                break;
            case 5:
                display(&g);
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}