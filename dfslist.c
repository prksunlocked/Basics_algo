#include<stdio.h>
#include<stdlib.h>

struct node{
    int nv;
    struct node *next;
};

typedef struct node* NODEPTR;

NODEPTR getnode(int ele)
{
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    p->nv=ele;
    p->next=NULL;
}

NODEPTR inssort(NODEPTR head,int ele)
{
    NODEPTR p,q,t;
    p=getnode(ele);
    if(head==NULL)
        return p;
    q=head;
    t=NULL;
    while((q->nv)<=(p->nv) && q->next!=NULL){
        t=q;
        q=q->next;
    }
    if(q->nv>p->nv)
    {
        if(t==NULL){
            p->next=q;
            return p;
        }
        p->next=q;
        t->next=p;
        return head;
    }
    q->next=p;
    return head;
}



void DFS(int v, NODEPTR *list, int *statmat, int vx)
{
    printf("%d\n",vx);
    statmat[vx]=0;
    NODEPTR p=list[vx];
    while(p!=NULL)
    {
        if(statmat[p->nv]!=0)
            DFS(v,list,statmat,p->nv); 
        p=p->next;
    }
}

int main()
{
    int v,i,e,a,b;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    NODEPTR *list;
    list=(NODEPTR*)calloc(v,sizeof(NODEPTR));
    printf("Enter the number of edge: ");
    int statmat[v];
    for(i=0;i<v;i++)
        statmat[i]=1;
    scanf("%d",&e);
    for(i=0;i<e;i++)
    {
        printf("Enter the starting vertex: ");
        scanf("%d",&a);
        printf("Enter the Dest. vertex: ");
        scanf("%d",&b);
        list[a]=inssort(list[a],b);
    }
    i=0;
    while(statmat[i]!=0 && i<v){
        printf("The Tree no. %d :\n",i);
        DFS(v,list,statmat,i);
        i++;
        printf("\n");
    }
}
