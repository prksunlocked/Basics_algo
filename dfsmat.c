#include<stdio.h>
#include<stdlib.h>

void DFS (int v,int **list,int *statmat, int vx){
    int i,j,k;
    printf("%d\n",vx);
    statmat[vx]=0;
    for(i=0;i<v;i++){
        if(list[vx][i]!=0 && statmat[i]==1){
            DFS(v,list,statmat,i);
        }
    }
}

int main()
{
    int v,e,i,j,a,b;
    printf("Enter the number of vertices:-");
    scanf("%d",&v);
    int **list=(int**)calloc(v,sizeof(int*));
    for(i=0;i<v;i++)
        list[i]=(int*)calloc(v,sizeof(int));
    printf("Enter the number of edges:-");
    scanf("%d",&e);
    printf("Enter the edges:-");
    int statmat[v];
    for(j=0;j<v;j++){
       statmat[j]=1;
    }
    for(i=0;i<e;i++){
        printf("\nEnter start vertex:-");
        scanf("%d",&a);
        printf("Enter End vertex:-");
        scanf("%d",&b);
        list[a][b]=1;
    }
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%d ",list[i][j]);
        }
        printf("\n");
    }
    for(int k=0;k<v;k++){
        if(statmat[k]!=0){
        printf("\n");
        DFS(v,list,statmat,k);}
    }
    return 0;
}
