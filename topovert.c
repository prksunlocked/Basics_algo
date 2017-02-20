#include<stdio.h>
#include<stdlib.h>

struct stack
{
        int *val;
        int top;
        int max;
};

void push(struct stack *stack1, int ele)
{
        if(stack1->top==stack1->max-1)
        {
                printf("Can't Insert any more!\n");
                exit (0);
        }
        stack1->val[(++stack1->top)]=ele;
        return;
}

int pop(struct stack *stack1)
{
        if(stack1->top==-1)
        {
                printf("Can't Del any more!\n");
                exit (0);
        }
        return stack1->val[(stack1->top)--];
        
}

int vertinstack(struct stack *stack1, int ele)
{
        int i;
        for(i=0;i<=stack1->top;i++)
                if(ele==stack1->val[i])
                        return -1;
        return 0;
}

void DFS(int v, int(*list)[v], int *stat, int vx, struct stack* stack1)
{
        int i;
        stat[vx]=0;
        push(stack1,vx);
        for(i=0;i<v;i++)
        {
                if(list[vx][i]==1 && stat[i]==1)
                        DFS(v,list,stat,i,stack1);
                else if(list[vx][i]==1 && vertinstack(stack1,i)==-1){
                        printf("Cycle Detected!\n");
                        exit(0);
                }
        }
        pop(stack1);
}
int main()
{
        int v,e,a,b,i,j;
        printf("Enter the number of vertex:" );
        scanf("%d",&v);
        printf("Enter the number of edges:" );
        scanf("%d",&e);
        
        int stat[v],list[v][v],innode[v];
        for(i=0;i<v;i++)
        {
                stat[i]=1;
                innode[i]=0;
                for(j=0;j<v;j++)
                        list[i][j]=0;
        }
        for(i=0;i<e;i++){
                printf("Enter Vertex %d start: ",i+1);
                scanf("%d",&a);
                printf("Enter Vertex %d End: ",i+1);
                scanf("%d",&b);
                innode[b]++;
                list[a][b]=1;
        }
        
        struct stack stack1;
        stack1.max=v;
        stack1.val=(int*)calloc(v,sizeof(int));
        stack1.top=-1;
        
        for(i=0;i<v;i++){
                if(stat[i]!=0)
                        DFS(v,list,stat,i,&stack1);
        }
        
        for(i=0;i<v;i++)
                stat[i]=1;
        i=0;
        while(i<v){
                if(stat[i]!=-1 && innode[i]==0)
                {
                        for(j=0;j<v;j++)                        
                        {
                                if(list[i][j]==1){
                                        innode[j]--;
                                        list[i][j]=0;
                                }
                        }
                        printf("%d ",i);
                        stat[i]=-1;
                        i=0;
                }
                else
                        i++;
        }
        return 0;
}
