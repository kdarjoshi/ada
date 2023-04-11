#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define X 4
#define Y 40

typedef struct items{
	int value;
	int num;
	int order;
}i;

i items[100];
int ind = 0;
int V[100];
int count = 0;
int connected = -1;
int bop = 0;
int cyclic = 0;

void sort(int n){
	int flag;
	i temp;

	for(int i=0;i<n-1;i++){
		flag = 0;
		for(int j=0;j<n-1-i;j++){
			if(items[j].order < items[j+1].order){
				flag = 1;
				temp = items[j];
				items[j] = items[j+1];
				items[j+1] = temp;
			}
		}
		if(flag==0)
			break;
	}
}


void dfs(int v,int G[100][100],int row,int col,FILE *f1){
	count++;
	V[v] = count;
	for(int i=0;i<row;i++){
		if(G[v][i] == 1 && V[i]!=0 && V[v]-V[i]!=0 && G[i][v] == 1){
			cyclic++;
			//fprintf(f1,"Backedge from %d to %d\n",v+1,i+1);
		}
	}
	//fprintf(f1,"%d - %d\n",v+1,V[v]);
	// items[ind].value = v+1;
	// items[ind].num = count;
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
	items[ind].value = v+1;
	items[ind].num = count;
	items[ind].order = ind+1;
	ind++;
}

void DFS(int G[100][100],int row,int col,FILE *f1){

	for(int i=0;i<row;i++)
		V[i] = 0;
	count = 0;
	bop = 0;
	connected = -1;
	ind = 0;
	for(int i=0;i<row;i++){
		if(V[i] == 0){
			//fprintf(f1,"DFS tree: %d\n",connected+2);
			//printf("DFS tree: %d\n",connected+2);
			dfs(i,G,row,col,f1);
			//connected++;
		}
	}
	sort(row);
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
					//AM[CI][RI] = 1;
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
		// if(connected > 0){
		// 	fprintf(f1,"The graph is not connected\n");
		// 	//printf("The graph is not connected %d\n",connected);
		// }else{
		// 	fprintf(f1,"The graph is connected\n");
		// 	//printf("The graph is connected\n");
		// }
		if(cyclic==0){
			fprintf(f1,"Topological sorting:\n");
			for(int j = 0;j<i;j++){
				fprintf(f1,"%d -> ",items[j].value);
			}
		}else{
			fprintf(f1,"The graph has cycles, hence no solution\n");
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