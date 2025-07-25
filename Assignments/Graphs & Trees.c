#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF 9999

int graph[MAX][MAX];
int vertices;

int i, j;

// -------------------- Input & Display --------------------
void inputGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter adjacency matrix (%dx%d):\n", vertices, vertices);
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;  // Treat 0 (no edge) as INF, except diagonal
        }
    }
}

void displayGraph() {
    printf("\nGraph (Adjacency Matrix):\n");
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            if (graph[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
}

// -------------------- Dijkstra's Algorithm --------------------
void dijkstra(int src) {
    int dist[MAX], visited[MAX] = {0}, count, v;
    for (i = 0; i < vertices; i++) dist[i] = INF;
    dist[src] = 0;

    for (count = 0; count < vertices - 1; count++) {
        int min = INF, u;

        for (i = 0; i < vertices; i++)
            if (!visited[i] && dist[i] < min)
                min = dist[i], u = i;

        visited[u] = 1;

        for (v = 0; v < vertices; v++)
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nShortest distances from vertex %d:\n", src);
    for (i = 0; i < vertices; i++) {
        printf("To %d: ", i);
        if (dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
}

// -------------------- Kruskal's Algorithm --------------------
typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];

int find(int i) {
    while (parent[i]) i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    if (a != b) {
        parent[b] = a;
        return 1;
    }
    return 0;
}

void kruskal() {
    Edge edges[MAX * MAX];
    int edgeCount = 0;

    // Collect all edges
    for (i = 0; i < vertices; i++) {
        for (j = i + 1; j < vertices; j++) {
            if (graph[i][j] != INF) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Sort edges by weight (simple bubble sort)
    for (i = 0; i < edgeCount - 1; i++) {
        for (j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int mstWeight = 0;
    printf("\nMinimum Spanning Tree (Kruskal's Algorithm):\n");
    for (i = 0; i < edgeCount; i++) {
        if (unionSet(edges[i].u, edges[i].v)) {
            printf("Edge: %d - %d (Weight: %d)\n",
                   edges[i].u, edges[i].v, edges[i].weight);
            mstWeight += edges[i].weight;
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

// -------------------- Menu --------------------
void menu() {
    printf("\n===== Graph Menu =====\n");
    printf("1. Input Graph\n");
    printf("2. Display Graph\n");
    printf("3. Dijkstra's Shortest Path\n");
    printf("4. Kruskal's Minimum Spanning Tree\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, source;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputGraph();
                for (i = 0; i < MAX; i++) parent[i] = 0;
                break;
            case 2:
                displayGraph();
                break;
            case 3:
                printf("Enter source vertex (0 to %d): ", vertices - 1);
                scanf("%d", &source);
                dijkstra(source);
                break;
            case 4:
                kruskal();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

