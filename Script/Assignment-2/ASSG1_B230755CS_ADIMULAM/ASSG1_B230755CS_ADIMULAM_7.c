#include<stdio.h>

void merge(int a[],int l,int h,int r){
    int n1=r-l+1,n2=h-r;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=a[l+i];

    }

    for(int i=0;i<n2;i++){
        R[i]=a[r+1+i];

    }
   int  x=0;
   int y=0;
    for(int i=l;i<=h;i++){
        if(L[x]<=R[y]&&x<n1&&y<n2){
            a[i]=L[x];
            x++;
            continue;
        }
        if(L[x]>R[y]&&x<n1&&y<n2){
            a[i]=R[y];
            y++;
            continue;
        }
        if(x>=n1){
            a[i]=R[y];
            y++;
            continue;
        }
         if(y>=n2){
            a[i]=L[x];
            x++;
            continue;
        }
    }

}

void merge_sort(int a[],int l,int h){
    if(l<h){
    int r=(l+h)/2;
    merge_sort(a,l,r);
    merge_sort(a,r+1,h);
    merge(a,l,h,r);
    }
}

int main(){
    int g=1,n;
    scanf("%d",&n);
    if(n>=1 && n<=100000){
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<1||a[i]>100000){
            g=0;
        }
    }

        if(g!=0){
            merge_sort(a,0,n-1);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
    }
    printf("\n");
    }
    else
    printf("invalid elements in the array\n");
    }
    else
    printf("invalid size of the array\n");
    return 0;
}
