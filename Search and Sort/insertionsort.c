#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void main(){
    int a[]={12,11,15,10,13};
    int k,i,key;
    for(k=0;k<4;k++)
    {
        i=k;
        key=a[i+1];
        while(i>=0 && key<a[i]){
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
    for(k=0;k<=4;k++)
        printf("%d ",a[k]);
}