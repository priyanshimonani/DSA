#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void main(){
    int a[]={12,11,15,10,1};
    int i,j,mindex,temp,min;
    for(i=0;i<4;i++)
    {
        mindex=i;
        for(j=i+1;j<=4;j++){//searching for min
            if(a[j]<a[mindex])
                mindex=j;
        }
        temp=a[i];
        a[i]=a[mindex];
        a[mindex]=temp; //remember!!! search for minimum element INDEX, not minimum element
    }
    for(j=0;j<5;j++)
        printf("%d ",a[j]);
}