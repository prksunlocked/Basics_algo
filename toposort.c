#include<stdio.h>
#include<stdlib.h>
/* Caution this DFS topo version doesn't contain cycle detection and is implemented as adjencey list way!*/
struct node
{
    int data;
    struct node* next;
};

struct stack
{
    int *val;
    int top;
    int max;
};

typedef struct node* NODEPTR;

NODEPTR getnode(int ele)
{
    NODEPTR newnode;
    newnode=(NODEPTR)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    return newnode;
}

NODEPTR inssorted(NODEPTR head, int ele)
{
    NODEPTR newnode;
    NODEPTR follow,itr;
    itr=head;
    newnode=getnode(ele);
    if(head==NULL)
        return newnode;
    while(itr->next!=NULL && itr->data<=ele)
    {
        follow=itr;
        itr=itr->next;
    }
    if(itr->data>ele)
    {
        newnode->next=follow->next;
        follow->next=newnode;
    }
    else if(itr->next==NULL)
    {
        itr->next=newnode;
    }
    return head;
}

void insstack(struct stack* stack1,int ele)
{
    if(stack1->top==((stack1->max)-1)){
        printf("Stack Overflow!\n");
        exit(0);
    }
    stack1->val[++stack1->top]=ele;
    return;
}
int popstack(struct stack* stack1)
{
    if(stack1->top==-1){
        printf("Stack Underflow!\n");
        exit(0);
    }
    return stack1->val[stack1->top--];
}

void DFS(int v, NODEPTR*list, int* stat, int vx, struct stack *stack1)
{
    stat[vx]=0;
    NODEPTR head=list[vx];
    while(head!=NULL)
    {
        if(stat[head->data]==1)
            DFS(v, list, stat, head->data, stack1);
        head=head->next;
    }
    insstack(stack1,vx);
}

int main()
{
    int v,e,i,j,a,b;
    printf("Enter the number of Vertices: ");
    scanf("%d",&v);
    printf("Enter the number of Edges: ");
    scanf("%d",&e);
    NODEPTR *list=(NODEPTR*)calloc(v,sizeof(NODEPTR));
    int stat[v];
    for (i=0;i<v;i++)
        stat[i]=1;
    struct stack stack1;
    stack1.val=(int*)calloc(v,sizeof(int));
    stack1.top=-1;
    stack1.max=v;
    for(i=0;i<e;i++)
    {
        printf("Enter Edge %d Starting point: ",i+1);
        scanf("%d",&a);
        printf("Enter Edge %d Ending point: ",i+1);
        scanf("%d",&b);
        list[a]=inssorted(list[a],b);
    }
    i=0;
    while(i<v)
    {
        if(stat[i]!=0)
            DFS(v,list,stat,i,&stack1);
        i++;
    }
    printf("\nTopological Ordering is:\n");
    while(stack1.top!=-1){
        printf("%d ",stack1.val[stack1.top]);
        popstack(&stack1);
    }
    printf("\n");
    return 0;
}
