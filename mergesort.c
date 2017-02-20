#include<stdio.h>
#include<stdlib.h>
void merge(int *val,int low,int high,int mid, int *count)
{
        int n1,n2,i,j,k;
        n1=mid-low+1;
        n2=high-mid;
        int l[n1],r[n2];
        for(i=0;i<n1;i++)
                l[i]=val[i+low];
        for(i=0;i<n2;i++)
                r[i]=val[i+mid+1];
        i=j=0;
        k=low;
        while(i<n1 && j<n2)
        {
                (*count)++;
                if(l[i]>=r[j])
                {
                        val[k]=r[j];
                        j++;
                        k++;
                }
                else if(l[i]<r[j])
                {
                        val[k]=l[i];
                        i++;
                        k++;
                }
        }
        while(i<n1)
        {
                (*count)++;
                val[k]=l[i];
                i++;
                k++;
        }
        while(j<n2)
        {
                (*count)++;
                val[k]=r[j];
                j++;
                k++;
        }
}
        
void mergesort(int* val,int low,int high, int* count)
{
        if(low>=high)
                return;
        int mid=(low+high)/2;
        mergesort(val,low,mid,count);
        mergesort(val,mid+1,high,count);
        merge(val,low,high,mid,count);
}

int main()
{       int i,n,ops=0;
        printf("Enter n: ");
        scanf("%d",&n);
        int *val=(int*)calloc(n,sizeof(int));
        for(i=0;i<n;i++)
                val[i]=(rand()%10000);
        mergesort(val,0,n-1,&ops);
        printf("\nRANDOM Ops are: %d\n",ops);
        ops=0;
        for(i=n;i>0;i--)
                val[n-i]=i;
        mergesort(val,0,n-1,&ops);
        printf("\nDECREASING Ops are: %d\n",ops);
        ops=0;
        for(i=1;i<=n;i++)
                val[i]=i;
        mergesort(val,0,n-1,&ops);
        printf("\nINCREASING Ops are: %d\n",ops);
        return 0;
}
