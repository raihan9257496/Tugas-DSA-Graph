#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

// Struktur node untuk adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Struktur list
typedef struct List {
    Node* head;
} List;

// Fungsi untuk membuat node baru
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan edge (graf tak berarah)
void addEdge(List* adjList, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;
}

// Fungsi BFS
void bfs(List* adjList, int V) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    // Mulai dari vertex 0
    visited[0] = 1;
    queue[rear++] = 0;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        Node* temp = adjList[current].head;
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }

    printf("\n~\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    getchar(); // consume newline

    while (tc--) {
        int V;
        scanf("%d", &V);
        getchar(); // consume newline

        List adjList[MAX];
        for (int i = 0; i < V; i++) {
            adjList[i].head = NULL;
        }

        for (int i = 0; i < V; i++) {
            char line[10000];
            fgets(line, sizeof(line), stdin);

            char* token = strtok(line, " ");
            while (token != NULL) {
                int dest = atoi(token);
                addEdge(adjList, i, dest);
                token = strtok(NULL, " ");
            }
        }

        bfs(adjList, V);
    }

    return 0;
}
