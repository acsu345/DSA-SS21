#include <stdio.h>
#include <stdlib.h>
// xay dung cau truc do thi
typedef struct Graph {
    int V;
    int** Adj;
}Graph;
//xay dung ham khoi tao do thi
Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->Adj = (int**)malloc(V*sizeof(int*));
    //cap pphat bo nho cho mang 2 chieu
    for (int i = 0; i < V; i++) {
        graph->Adj[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->Adj[i][j] = 0;
        }
    }
    return graph;
}
//xay dung ham thiet lap canh
void addEdge(Graph *graph, int src, int des) {
    graph->Adj[src][des] = 1;
}
//xay dung ham in ma tran
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->Adj[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    Graph *graph = createGraph(3);
    addEdge(graph, 1, 0);
    addEdge(graph, 2,0);
    addEdge(graph, 1, 2);
    printGraph(graph);
    return 0;
}
