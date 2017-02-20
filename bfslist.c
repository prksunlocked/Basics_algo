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

NODEPTR inssort(NODEPTR head, int ele)
{
    NODEPTR p,t,q;
    p=getnode(ele);
    if(head==NULL)
        return p;
    q=head;
    t=NULL;
    while((q->data)<=(p->data) && q->next!=NULL){
        t=q;
        q=q->next;
    }
    
    if(q->data>p->data){
        if(t==NULL){
            p->next=head;
            return p;
        }
        p->next=q;
        t->next=p;
        return head;
    }
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

void BFS(int v, NODEPTR* list, int* statmat, struct que* que1)
{
    int vx;
    NODEPTR q;
    while(que1->front!=NULL)
    {
        vx=dequeue(que1);
        q=list[vx];
        while(q!=NULL)
        {
            if(statmat[q->data]!=0){
                enqueue(que1,q->data);
                statmat[q->data]=0;
                printf("%d\n",q->data);
            }
            q=q->next;
        }
        
    }
}

int main()
{
    int v,e,i,j,a,b;
    printf("Enter the number of vertices: ");
    scanf("%d",&v);
    NODEPTR *list;
    list=(NODEPTR*)calloc(v,sizeof(NODEPTR));
    for(i=0;i<v;i++)
        list[i]=NULL;
    int statmat[v];
    for(i=0;i<v;i++)
        statmat[i]=1;
    printf("Enter the number of Edges: ");
    scanf("%d",&e);
    for(i=0;i<e;i++)
    {
        printf("Enter the starting of edge %d: ",i);
        scanf("%d",&a);
        printf("Enter the ending of edge %d: ",i);
        scanf("%d",&b);
        list[a]=inssort(list[a],b);
        printf("\n");
    }
    struct que que1;
    que1.front=NULL;
    que1.back=NULL;
    i=0;
    while(statmat[i]!=0 && i<v)
    {
        printf("Tree is:-\n");
        enqueue(&que1,i);//once queued, you are as good as visited
        statmat[i]=0;
        printf("%d\n",i);
        BFS(v,list,statmat,&que1);
        printf("\n");
        i++;
    }
    return 0;
}
