//    prims
#include <stdio.h>
#include <stdlib.h>
int n;
int adj[20][20];

int prims() {
    int cost = 0, edges = 0, count = 0;
    int selected[n];
    for(int i = 0; i < n; i++)
       selected[i] = 0;
    selected[0] = 1;
    while (edges < n - 1) {
        int row = 0;
        int col = 0;
        int mini = 9999;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                  count++;
                    if(!selected[j] && adj[i][j]) {
                        if(mini > adj[i][j]) {
                            mini=adj[i][j];
                            row=i;
                            col=j;
                        }
                    }
                }
            }
        }
        printf("V%d<-----%d----->V%d\n",row+1, adj[row][col], col+1);
        cost+=adj[row][col];
        edges++;
        selected[col]=1;
    }
    printf("Cost :- %d\n", cost);
    return count;
}
int main() {
    printf("Enter no. of vertices\n");
    scanf("%d", &n);
    printf("Enter the matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Count = %d\n",prims());

    return 0;
}
