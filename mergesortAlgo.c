#include <stdio.h>
int main() {
    float w[]={10,20,30}, v[]={60,100,120};
    float r[3], cap=50, total=0;

    for(int i=0;i<3;i++)
        r[i] = v[i]/w[i];

    for(int i=0;i<2;i++)
        for(int j=i+1;j<3;j++)
            if(r[i]<r[j]) {
                float t;
                t=r[i]; r[i]=r[j]; r[j]=t;
                t=w[i]; w[i]=w[j]; w[j]=t;
                t=v[i]; v[i]=v[j]; v[j]=t;
            }

    printf("Selected:\n");

    for(int i=0;i<3;i++) {
        if(cap>=w[i]) {
            cap -= w[i];
            total += v[i];
            printf("Full item %d\n", i+1);
        } else {
            float f = cap/w[i];
            total += v[i]*f;
            printf("Item %d: %.2f fraction\n", i+1, f);
            break;
        }
    }

    printf("Total=%.2f", total);
}
