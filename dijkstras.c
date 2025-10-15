/* Dijkstra - adjacency matrix version */
#include <stdio.h>
#include <limits.h>

#define MAXV 100
#define INF 1000000000

int minDistance(int dist[], int sptSet[], int V){
    int min = INF, min_index = -1;
    for(int v=0; v<V; v++)
        if(!sptSet[v] && dist[v] <= min){
            min = dist[v]; min_index = v;
        }
    return min_index;
}

void printPath(int parent[], int j){
    if(parent[j]==-1){ printf("%d", j); return; }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(int graph[MAXV][MAXV], int V, int src){
    int dist[MAXV], sptSet[MAXV], parent[MAXV];
    for(int i=0;i<V;i++){ dist[i]=INF; sptSet[i]=0; parent[i]=-1; }
    dist[src]=0;

    for(int count=0; count<V-1; count++){
        int u = minDistance(dist, sptSet, V);
        if(u==-1) break;
        sptSet[u]=1;
        for(int v=0; v<V; v++){
            if(!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                dist[v]=dist[u] + graph[u][v];
                parent[v]=u;
            }
        }
    }

    printf("Vertex\tDistance from Source\tPath\n");
    for(int i=0;i<V;i++){
        if(dist[i]==INF) printf("%d\tINF\t\t\tNo path\n", i);
        else {
            printf("%d\t%d\t\t\t", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main(){
    int V;
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    int graph[MAXV][MAXV];
    printf("Enter adjacency matrix (0 for no edge):\n");
    for(int i=0;i<V;i++) for(int j=0;j<V;j++) scanf("%d",&graph[i][j]);
    int src; printf("Enter source vertex (0 to %d): ", V-1); scanf("%d",&src);
    dijkstra(graph, V, src);
    return 0;
}

