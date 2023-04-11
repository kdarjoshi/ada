#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 4
#define Y 10

int V[100];
int count = 0;
int connected = -1;
int bop = 0;
int cyclic = 0;




void dfs(int v,int G[100][100],int row,int col,FILE *f1){
	count++;
	V[v] = count;
	for(int i=0;i<row;i++){
		if(G[v][i] == 1 && V[i]!=0 && V[v]-V[i]!=1){
			cyclic++;
			fprintf(f1,"Backedge from %d to %d\n",v+1,i+1);
		}
	}
	fprintf(f1,"%d - %d\n",v+1,V[v]);
	//printf("%d - %d\n",v+1,V[v]);
	for(int i=0;(i<row);i++){

		if(G[v][i] == 1){
			bop++;
			if(V[i] == 0){
				bop++;
				dfs(i,G,row,col,f1);
			}

		}

	}
}

void DFS(int G[100][100],int row,int col,FILE *f1){

	for(int i=0;i<row;i++)
		V[i] = 0;
	count = 0;
	bop = 0;
	connected = -1;
	cyclic = 0;
	for(int i=0;i<row;i++){
		if(V[i] == 0){
			fprintf(f1,"DFS tree: %d\n",connected+2);
			//printf("DFS tree: %d\n",connected+2);
			dfs(i,G,row,col,f1);
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
		f1 = fopen("DFS_data.txt","a");
		if(ch==2){
			for(row=0;row<i;row++){
				for(col=0;col<i;col++){
					if(row==col)
						AM[row][row] = 0;
					else
						AM[row][col] = 1;
				}
			}
			f = fopen("DFS_W.txt","a");
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
			f = fopen("DFS_B.txt","a");
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


		DFS(AM,i,i,f1);
		bop++;
		if(connected > 0){
			fprintf(f1,"The graph is not connected %d\n",connected);
			//printf("The graph is not connected %d\n",connected);
		}else{
			fprintf(f1,"The graph is connected\n");
			//printf("The graph is connected\n");
		}
		if(cyclic!=0){
			fprintf(f1,"The graph has cycles: %d\n",cyclic);
		}else{
			fprintf(f1,"The graph has no cycles\n");
		}
		fprintf(f1,"\n\n");
		fprintf(f,"%d %d\n",i,bop);
		fclose(f);
		fclose(f1);
	}
}
int main(){
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
	return 0;
}