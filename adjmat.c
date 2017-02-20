#include<stdio.h>
#include<stdlib.h>

int main()
{
    int v,e,i,j,a,b;
    printf("Enter number of vertices:-");
    scanf("%d",&v);
    printf("Vertex 0-%d created!\n",v-1);
    int edgel[v][v];
    for(i=0;i<v;i++){
        for(j=0;j<v;j++)
            edgel[i][j]=0;
    }
    printf("Enter the number of edge:- ");
    scanf("%d",&e);
    for(i=0;i<e;i++){
        printf("\nEnter start vertex:-");
        scanf("%d",&a);
        printf("Enter End vertex:-");
        scanf("%d",&b);
        edgel[a][b]=1;
    }
    printf("\nThe Adjencey Matrix is:-\n\n");
    for(i=0;i<v;i++){
        for(j=0;j<v;j++)
            printf("%d ",edgel[i][j]);
        printf("\n");
    }
    return 0;
}
