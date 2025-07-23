#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node* adjList[], int a, int b) {
    Node* newNode1 = createNode(b);
    newNode1->next = adjList[a];
    adjList[a] = newNode1;
    Node* newNode2 = createNode(a);
    newNode2->next = adjList[b];
    adjList[b] = newNode2;
}
void printGraph(Node* adjList[], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        Node* temp = adjList[i];
        if (temp == NULL) {
            printf("NULL");
        } else {
            while (temp != NULL) {
                printf("%d->", temp->vertex);
                temp = temp->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}
int main() {
    Node* adjList[3];
    for (int i = 0; i < 3; i++) {
        adjList[i] = NULL;
    }
    printGraph(adjList, 3);
    printf("\n");
    addEdge(adjList, 1, 2);
    printGraph(adjList, 3);
    printf("\n");
    addEdge(adjList, 0, 1);
    printGraph(adjList, 3);

    return 0;
}
