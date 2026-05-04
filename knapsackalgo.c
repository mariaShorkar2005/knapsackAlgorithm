#include <stdio.h>
int n;
int clean(int a[], int size, int b[]) {
    int k = 0;
    for(int i=0;i<size;i++){
        if(a[i]<0) continue;
        int dup = 0;
        for(int j=0;j<k;j++)
            if(b[j]==a[i]) dup=1;
        if(!dup) b[k++] = a[i];
    }
    return k;
}

void merge(int a[], int l, int m, int r){
  int  temp[50], i=l, j=m+1, k=0;
  while(i<=m && j<=r)
  temp[k++] = (a[i]<a[j]) a[i++] : a[j++];
  while(i<=m) temp[k++] = a[i++];
  while(j<=r) temp[k++] = a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i] = temp[k];

    for(int x=0;x<n;x++) printf("%d ",a[x]);
    printf("\n");
}

void mergeSort(int a[], int l, int r) {
    if(l<r) {
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main() {
    int a[]={45,-10,20,15,45,30,-5,25,60,15,35,-2};
    int b[50];
    n = clean(a,12,b);
    printf("Cleaned:\n");
    for(int i=0;i<n;i++) printf("%d ",b[i]);

    printf("\n\nSteps:\n");
    mergeSort(b,0,n-1);

    printf("\nFinal:\n");
    for(int i=0;i<n;i++) printf("%d ",b[i]);
}

