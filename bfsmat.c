#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

typedef struct node* NODEPTR;

struct que
{
    NODEPTR back;
    NODEPTR front;
};

NODEPTR getnode(int ele)
{
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    p->data=ele;
    p->next=NULL;
    return p;
}

NODEPTR insend(NODEPTR head, int ele)
{
    NODEPTR p,q;
    p=getnode(ele);
    if(head==NULL)
        return p;
    q=head;
    while(q->next!=NULL)
        q=q->next;
    q->next=p;
    return head;
}

void enqueue(struct que* que1,int ele)
{
    NODEPTR p=getnode(ele);
    if(que1->front==NULL||que1->back==NULL){
        que1->back=p;
        que1->front=p;
        return;
    }
    (que1->back)->next=p;
    return;
}

int dequeue(struct que* que1)
{
    if(que1->front==NULL)
        return -1;
    int k;
    k=(que1->front)->data;
    que1->front=(que1->front)->next;
    return k;
}

void BFS(int v, int(*vals)[v], int* stat, struct que* que1)
{
    int vx,i;
    NODEPTR q;
    while(que1->front!=NULL)
    {
        vx=dequeue(que1);
        for(i=0;i<v;i++)
        {
            if(vals[vx][i]!=0 && stat[i]!=0)
            {
                enqueue(que1,i);
                stat[i]=0;
                printf("%d\n",i);
            }
        }
    }
}


int main()
{   int i,j,e,v,a,b;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    printf("Enter the number of Edges: ");
    scanf("%d",&e);
    int vals[v][v];
    int stat[v];
    for(i=0;i<v;i++){
        stat[i]=1;
        for(j=0;j<v;j++){
            vals[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        printf("Enter strating of Edge %d:  ",i+1);
        scanf("%d",&a);
        printf("Enter ending of Edge %d:  ",i+1);
        scanf("%d",&b);
        vals[a][b]=1;
        printf("\n");
    }
    struct que que1;
    que1.front=NULL;
    que1.back=NULL;
    i=0;
    while(stat[i]!=0&&i<v)
    {
        printf("Tree is:-\n");
        enqueue(&que1,i);//once queued, you are as good as visited
        stat[i]=0;
        printf("%d\n",i);
        BFS(v,vals,stat,&que1);
        printf("\n");
        i++;
    }
    return 0;
}
