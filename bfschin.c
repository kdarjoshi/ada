#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int v;
	int flag;
}n;

typedef struct queue{
	n items[100];
	int f;
	int r;
}Q;

Q q;
int count,V[100],connected,cyclic;

void dequeue(int n)
{
	q.f++;
}

void enqueue(int v,int n){
	q.r = (q.r+1)%n;
	q.items[q.r].v = v;
	q.items[q.r].flag = 0;
}

void bfs(int *a[100],int v,int n){
	count++;
	V[v] = count;
	enqueue(v,n);
	printf("%d - %d\n",v,count);
	while(q.f<=q.r){
		q.items[q.f].flag = 1;
		for(int i = 0;i<n;i++){
			if(a[q.items[q.f].v][i] == 1){
				if(V[i] == 0){
					count++;
					V[i] = count;
					printf("%d - %d\n",i,count);
					enqueue(i,n);
				}
				else if(q.items[q.items[i].v].flag == 0){
					cyclic++;
				}
			}
		}
		dequeue(n);
	}
}

void BFS(int *a[100],int n){
	count = 0;
	connected = -1;
	for(int i = 0;i<n;i++)
		V[i] = 0;
	for(int i = 0;i<n;i++)
		if(V[i] == 0){
			printf("BFS tree %d\n",connected+2);
			bfs(a,i,n);
			connected++;
		}
	if(cyclic>0)
		printf("Graph contains cycle\n");
	if(connected>0)
		printf("Disconnected\n");
}

int main(){
	int v;
	q.f = 0;
	q.r = -1;
	printf("Enter the number of vertices\n");
		scanf("%d",&v);
	int *a[v];
	for(int i = 0;i<v;i++)
	{
		a[i] = (int *)malloc(sizeof(int)*v);
		q.items[i].flag = -1;
	}
	printf("Enter the adjacency matrix\n");
	for(int i = 0;i<v;i++)
		for(int j = 0;j<v;j++)
			scanf("%d",&a[i][j]);
	BFS(a,v);

}