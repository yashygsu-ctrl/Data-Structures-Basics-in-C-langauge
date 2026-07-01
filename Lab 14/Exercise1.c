#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node {
    int vertex;
    struct node* next;
};

struct node* adj[MAX];
int visited[MAX], n;

struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    struct node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        struct node* temp = adj[node];
        while (temp != NULL) {
            if (visited[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void DFS(int node) {
    printf("%d ", node);
    visited[node] = 1;

    struct node* temp = adj[node];
    while (temp != NULL) {
        if (visited[temp->vertex] == 0) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

int main() {
    int edges, u, v, start, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nBFS Traversal: ");
    BFS(start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    return 0;
}