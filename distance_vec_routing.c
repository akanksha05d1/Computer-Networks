/* Simple Distance Vector Routing (synchronous rounds) */
#include <stdio.h>
#include <string.h>
#define MAXV 50
#define INF 100000000

int main(){
    int V;
    printf("Enter number of nodes: ");
    scanf("%d",&V);
    int cost[MAXV][MAXV];
    printf("Enter cost matrix (-1 for no link):\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==-1) cost[i][j]=INF;
            if(i==j) cost[i][j]=0;
        }
    }

    int dist[MAXV][MAXV];
    int nextHop[MAXV][MAXV];

    // initialize distance vectors
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dist[i][j] = cost[i][j];
            if(cost[i][j] < INF && i!=j) nextHop[i][j] = j;
            else nextHop[i][j] = -1;
        }
    }

    // iterative update until convergence
    int changed = 1;
    while(changed){
        changed = 0;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                for(int k=0;k<V;k++){
                    if(dist[i][k] < INF && dist[k][j] < INF){
                        if(dist[i][j] > dist[i][k] + dist[k][j]){
                            dist[i][j] = dist[i][k] + dist[k][j];
                            nextHop[i][j] = (k==j? j : nextHop[i][k]); // update next hop
                            changed = 1;
                        }
                    }
                }
            }
        }
    }

    // print routing tables
    for(int i=0;i<V;i++){
        printf("\nRouting table for node %d:\n", i);
        printf("Dest\tCost\tNextHop\n");
        for(int j=0;j<V;j++){
            if(dist[i][j] >= INF) printf("%d\tINF\t-\n", j);
            else {
                int nh = nextHop[i][j];
                if(nh==-1) printf("%d\t%d\t-\n", j, dist[i][j]);
                else printf("%d\t%d\t%d\n", j, dist[i][j], nh);
            }
        }
    }
    return 0;
}

