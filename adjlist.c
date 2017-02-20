#include <stdio.h>
#include <stdlib.h>

struct node
{
    int nv;
    struct node* next;
};

typedef struct node* NODEPTR;
NODEPTR getnode(int ele)
{
    NODEPTR p;
    p=(NODEPTR)malloc(sizeof(struct node));
    p->nv=ele;
    p->next=NULL;
    return p;
}

NODEPTR insbeg(NODEPTR head,int ele)
{
    NODEPTR p;
    if(head==NULL)
        return(getnode(ele));
    p=getnode(ele);
    p->next=head;
    return p;
}

void printls(NODEPTR head)
{
    if(head==NULL)
        {printf("\n");return;}
    while(head->next!=NULL){
        printf("%d-->",head->nv);head=head->next;}
    printf("%d\n",head->nv);
}

int main()
{
    int v,e,i,j,a,b;
    printf("No of vertices: ");
    scanf("%d",&v);
    NODEPTR *list=(NODEPTR*)calloc(v,sizeof(NODEPTR));
    for(i=0;i<v;i++){
        list[i]=NULL;
    }
    scanf("%d",&e);
    for(i=0;i<e;i++){
        printf("\nEdge from :-");
        scanf("%d",&a);
        printf("Edge To :-");
        scanf("%d",&b);
        list[a]=insbeg(list[a],b);
    }
    for(i=0;i<v;i++){
        printf("[%d]-->",i);
        printls(list[i]);
    }
    return 0;
}
