#include <stdio.h>
#define MAX_VERTICES 5

typedef struct {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

void init(GraphType *G){
    G->n = 0;
    for(int i=0; i<MAX_VERTICES; i++){
        for(int j=0; j<MAX_VERTICES; j++){
            G->adj_mat[i][j] = 0;
        }
    }
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
    G->adj_mat[start][end] = G->adj_mat[end][start] = 1;
}

void delete_vertex(GraphType *G, int v){
    if(v >= G->n){
        printf("Vertex Input Error\n");
        return;
    }
    for(int i=0; i<G->n; i++){
        for(int j=v; j<G->n; j++){
            G->adj_mat[i][j] = G->adj_mat[i][j+1];
        }
    }
    for(int i=v; i<G->n; i++){
        for(int j=0; j<G->n; j++){
            G->adj_mat[i][j] = G->adj_mat[i+1][j];
        }
    }
    G->n--;
}

void delete_edge(GraphType *G, int start, int end){
    if(start >= G->n || end >= G->n){
        printf("Edge Input Error\n");
        return;
    }
    G->adj_mat[start][end] = G->adj_mat[end][start] = 0;
}

void display(GraphType *G){
    for(int i=0; i<G->n; i++){
        for(int j=0; j<G->n; j++){
            printf("%d ", G->adj_mat[i][j]);
        }
        puts("");
    }
}

int main(){
    GraphType graph;
    int menu, start, end, vertex;
    init(&graph);

    while(menu != 99){
        printf("1. Insert_Vertex 2. Insert_Edge 3. Delete_Vertex 4. Delete_Edge 5. Display 99. Exit\n");
        printf(">> ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                insert_vertex(&graph);
                break;
            case 2:
                printf("Enter the starting position : ");
                scanf("%d", &start);
                printf("Enter the ending position : ");
                scanf("%d", &end);
                insert_edge(&graph, start, end);
                break;
            case 3:
                printf("Enter the vertex : ");
                scanf("%d", &vertex);
                delete_vertex(&graph, vertex);
                break;
            case 4:
                printf("Enter the starting position : ");
                scanf("%d", &start);
                printf("Enter the ending position : ");
                scanf("%d", &end);
                delete_edge(&graph, start, end);
                break;
            case 5:
                display(&graph);
                break;
            case 99:
                break;
            default:
                printf("Menu Selection Error\n");
        }
    }

    return 0;
}