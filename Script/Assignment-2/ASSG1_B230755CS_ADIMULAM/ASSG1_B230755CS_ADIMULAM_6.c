#include<stdio.h>
int partition(int a[],int l,int h,int r){
    int i=l-1,key=a[r],k;
    for(int j=l;j<=h;j++){
        if(a[j]<key){
            i++;
            k=a[i];
            a[i]=a[j];
            a[j]=k;
            if(a[j]==key){
                r=j;
            }


        }
    }
    if(r!=i+1){
        k=a[i+1];
        a[i+1]=a[r];
        a[r]=k;
    }
    return i+1;
}

void quick_sort(int a[],int l,int h){
    if(l<h){
   int r=partition(a,l,h,l);
    quick_sort(a,l,r-1);
    quick_sort(a,r+1,h);
    }
}

int main(){
    int g=1,n;
    scanf("%d",&n);
    if(n>=0 && n<=10000){
    if(n!=0){
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<1||a[i]>1000000){
            g=0;
        }
    }

        if(g!=0){
            quick_sort(a,0,n-1);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
    }
    printf("\n");
    }

    else
    printf("invalid ID\n");
    }
    }
    else
    printf("invalid number of songs in the library\n");
    return 0;
}
