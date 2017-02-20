#include<stdio.h>
#include<stdlib.h>
int ops=0;

void bubblesort(int* val,int n)
{
        int i,j,temp;
        for(i=0;i<n-1;i++)
        {
                for(j=0;j<n-i-1;j++)
                {
                        ops++;
                        if(val[j]>val[j+1])
                        {
                                temp=val[j+1];
                                val[j+1]=val[j];
                                val[j]=temp;
                        }
                }
        }
}

int main()
{       int i,n;
        printf("Enter n: ");
        scanf("%d",&n);
        int *val=(int*)calloc(n,sizeof(int));
        for(i=0;i<n;i++)
                val[i]=(rand()%10000);
        bubblesort(val,n);
        for(i=0;i<n;i++)
                printf("%d ",val[i]);
        printf("\nOps are: %d\n",ops);
        return 0;
}
