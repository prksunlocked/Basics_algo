#include <stdio.h>
#include <stdlib.h>

int rearr(int *a,int low, int high,int *count)
{
        int i,j,piv,temp;
        piv=low;
        i=low+1;
        j=high;
        while(i<=j)//here was the problem in the given algorithm!
        {       (*count)++;
                while(a[i]<=a[piv] && i<=high){
                        i++;(*count)++;}
                (*count)++;
                while(a[j]>a[piv] && j>=low){
                        j--;(*count)++;}
                if(i<j)
                {
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                }
        }
        temp=a[piv];
        a[piv]=a[j];
        a[j]=temp;
        return j;
}

void quicksort(int* val, int low, int high, int *count)
{
        if(low<high)
        {
                int i,piv;
                piv=rearr(val,low,high,count);
                quicksort(val,low,piv-1,count);
                quicksort(val,piv+1,high,count);
        }
}

int main()
{
        int n,i,j,op=0;
        printf("Enter the number of Values: ");
        scanf("%d",&n);
        int *val=(int*)calloc(n,sizeof(int));
        printf("RAND values are:-\n");
        for(i=0;i<n;i++){
                val[i]=(rand()%100000);}
        quicksort(val,0,n-1,&op);
        printf("\n the number of ops are:- %d\n",op);
        op=0;

        printf("INC values are:-\n");
        for(i=0;i<n;i++){
                val[i]=i;}
        quicksort(val,0,n-1,&op);
        printf("\n the number of ops are:- %d\n",op);
        op=0;

        printf("DEC values are:-\n");
        for(i=n;i>0;i--){
                val[n-i]=i;
                }
        quicksort(val,0,n-1,&op);
        printf("\n the number of ops are:- %d\n",op);
        return 0;
}
