#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjLists = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->visited = (bool*)malloc(numVertices * sizeof(bool));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void BFS(struct Graph* graph, int startVertex) {
    int queue[graph->numVertices];
    int front = 0, rear = 0;

    graph->visited[startVertex] = true;
    queue[rear] = startVertex;
    rear++;

    while (front < rear) {
        int currentVertex = queue[front];
        printf("%d -> ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[rear] = adjVertex;
                rear++;
            }
            temp = temp->next;
        }
        front++;
    }
}

void DFS(struct Graph* graph, int vertex) {
    if (!graph->visited[vertex]) {
        printf("%d -> ", vertex);
        graph->visited[vertex] = true;

        struct Node* temp = graph->adjLists[vertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!graph->visited[adjVertex]) {
                DFS(graph, adjVertex);
            }
            temp = temp->next;
        }
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);

    printf("\nBreadth First Search Starting From Vertex 0:\n");
    BFS(graph, 0);
    printf("NULL\n");

    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = false;
    }

    printf("\nDepth First Search Starting From Vertex 0:\n");
    DFS(graph, 0);
    printf("NULL\n\n");

    freeGraph(graph);

    return 0;
}
