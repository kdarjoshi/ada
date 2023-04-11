#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 4
#define Y 10

typedef struct queue{
	int items[100];
	int f,r;
}q;

q Q;

int V[100];
int count = 0;
int connected = -1;
int bop = 0;
int cyclic = 0;

void enqueue(int v){
	Q.r++;
	Q.items[Q.r] = v;
}

void dequeue(){
	Q.f++;
	if(Q.f>Q.r){
		Q.f = 0;
		Q.r = -1;
	}
}


void bfs(int v,int G[100][100],int row,int col,FILE *f1){
	count++;
	V[v] = count;
	enqueue(v);
	fprintf(f1,"%d - %d\n",v+1,V[v]);
	while(Q.f <= Q.r){
		for(int i=0;i<row;i++){
			//bop++;
			if(G[Q.f][i] == 1){
				bop++;
				if(V[i] == 0){
					bop++;
					count++;
					V[i] = count;
					enqueue(i);
					fprintf(f1,"%d - %d\n",i+1,V[i]);
				}
			}
		}
		dequeue();
	}

}

void BFS(int G[100][100],int row,int col,FILE *f1){

	for(int i=0;i<row;i++)
		V[i] = 0;
	count = 0;
	bop = 0;
	connected = -1;
	Q.f = 0;
	Q.r = -1;
	for(int i=0;i<row;i++){
		if(V[i] == 0){
			fprintf(f1,"BFS traversal: %d\n",connected+2);
			//printf("DFS tree: %d\n",connected+2);
			bfs(i,G,row,col,f1);
			connected++;
		}
	}
}

void analysis(int ch){
	FILE *f1;
	FILE *f;
	int AM[100][100];
	srand(time(NULL));
	for(int i=X;i<=Y;i+=1){
		int row;
		int col;
		f1 = fopen("BFS_data.txt","a");
		if(ch==2){
			for(row=0;row<i;row++){
				for(col=0;col<i;col++){
					if(row==col)
						AM[row][row] = 0;
					else
						AM[row][col] = 1;
				}
			}
			f = fopen("BFS_W.txt","a");
		}
		else{
			for(row=0;row<i;row++){
				int RI = rand()%(i);
				int CI = rand()%(i);

				if(RI==CI)
					AM[RI][CI] = 0;
				else{
					AM[RI][CI] = 1;
					AM[CI][RI] = 1;
				}
			}
			f = fopen("BFS_B.txt","a");
		}
		fprintf(f1,"Number of vertices: %d\n",i);
		//printf("Number of vertices: %d\n",i);
		fprintf(f1,"The adjacency matrix:\n");
		//printf("The adjacency matrix:\n");
		for(int j=0;j<i;j++){
			for(int k=0;k<i;k++){
				fprintf(f1,"%d ",AM[j][k]);
				//printf("%d ",AM[j][k]);
			}
			fprintf(f1,"\n");
			//printf("\n");
		}


		BFS(AM,i,i,f1);
		bop++;
		if(connected > 0){
			fprintf(f1,"The graph is not connected %d\n",connected);
			//printf("The graph is not connected %d\n",connected);
		}else{
			fprintf(f1,"The graph is connected\n");
			//printf("The graph is connected\n");
		}
		fprintf(f1,"\n\n");
		fprintf(f,"%d %d\n",i,bop);
		fclose(f);
		fclose(f1);
	}
}
void main(){
	system("rm *.txt");
	int ch;
	while(1){
		printf("1.Best case\n2.Worst case\nEnter your choice\n");
			scanf("%d",&ch);
		switch(ch){
			case 1:
			case 2:
				analysis(ch);break;
			default: exit(1);
		}
	}
}