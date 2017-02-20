#include <stdio.h>
#include <stdlib.h>

struct heap{
    int *vals;
    int max;
};

void propup(struct heap *heap1, int key)
{
    int temp;
    if((key/2)>=1)
    {
        if(heap1->vals[key/2]<heap1->vals[key]){
            temp=heap1->vals[key];
            heap1->vals[key]=heap1->vals[key/2];
            heap1->vals[key/2]=temp;
            if((key/2)>1)
                propup(heap1,key/2);
        }
        return;
    }
    return;
}

void enheap(struct heap *heap1, int key)
{
    heap1->max++;
    heap1->vals[heap1->max]=key;
    if(key>1)
        propup(heap1,heap1->max);
}

void propdown(struct heap *heap1, int key)
{   
    int temp,k;
    if(heap1->max>=2*key)
    {
        if(heap1->max>=(2*key+1))
        {
            k=heap1->vals[2*key]>heap1->vals[2*key+1]?2*key:2*key+1;
            if(heap1->vals[k]>heap1->vals[key]){
                temp=heap1->vals[key];
                heap1->vals[key]=heap1->vals[k];
                heap1->vals[k]=temp;
                propdown(heap1,k);
            }
            else{
                return;
           } 
        }
        else
        {   if(heap1->vals[2*key]>heap1->vals[key]){
                temp=heap1->vals[key];
                heap1->vals[key]=heap1->vals[2*key];
                heap1->vals[2*key]=temp;
                return;
            }
            return;
        }
    }
}

int deheap(struct heap *heap1)
{
    int temp;
    if(heap1->max>0){
        temp=heap1->vals[1];
        heap1->vals[1]=heap1->vals[heap1->max];
        heap1->max--;
        if(heap1->max>1)
            propdown(heap1,1);
    }
    return temp;
}

int main()
{
        int n,i,j;
        printf("Enter no. of number: ");
        scanf("%d",&n);
        struct heap heap1;
        heap1.vals=(int*)calloc(2*n+1,sizeof(int));
        int val[n];
        heap1.max=0;
        printf("Enter the numbers:-\n");
        for(i=0;i<n;i++){
            scanf("%d",&val[i]);
            enheap(&heap1,val[i]);
        }
        printf("The Heap level trav is:-\n");
        for(i=1;i<n+1;i++){
            printf("%d ",heap1.vals[i]);
        }
        printf("\nThe Ordered sequence is:- \n");
        for(i=1;i<n+1;i++){
            printf("%d ",deheap(&heap1));
        }
        printf("\n");
        return 0;     
}
