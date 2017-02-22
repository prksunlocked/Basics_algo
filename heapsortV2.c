#include<stdio.h>
#include<stdlib.h>

struct heap{
    int *vals;
    int max;
};

void heapify(struct heap* heap1, int i){
    int t,l,r,large=i;
    l=2*i;
    r=2*i+1;
    if(heap1->vals[large]<heap1->vals[l] && l<=heap1->max)
        large=l;
    if(heap1->vals[large]<heap1->vals[r] && r<=heap1->max)
        large=r;
    if(large!=i){
        t=heap1->vals[large];
        heap1->vals[large]=heap1->vals[i];
        heap1->vals[i]=t;
        heapify(heap1,large);
    }
    return;
}

void enheap(struct heap* heap1,int ele){
    heap1->vals[++(heap1->max)]=ele;
    return;
}

void deheap(struct heap* heap1){
    int t;
    if(heap1->max>1){
        t=heap1->vals[heap1->max];
        heap1->vals[heap1->max]=heap1->vals[1];
        heap1->vals[1]=t;
        heap1->max--;
    }
    return;
}

void heapsort(struct heap* heap1){
    int i,n;
    for(i=heap1->max/2;i>=1;i--){
        heapify(heap1,i);
    }
    n=heap1->max;//coz my max keeps on chaning! It's need to know how many times to run!
    for(i=1;i<=n;i++){
        deheap(heap1);
        heapify(heap1,1);
    }
}

int main(){

    int n,i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int val[n];
    struct heap heap1;
    heap1.max=0;
    heap1.vals=(int*)calloc(n+1,sizeof(int));
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        printf("ARR[%d]: ",i);
        scanf("%d",&val[i]);
        enheap(&heap1,val[i]);
    }
    heapsort(&heap1);
    for(i=1;i<=n;i++){
        printf("%d ",heap1.vals[i]);
    }
    return 0;
}
