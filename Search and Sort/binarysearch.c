#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
void main(){
    int a[]={1,15,78,90,94,102,113};
    int ub=11,mid,key=15,lb=0;
    while(lb<=ub){
        mid=(lb+ub)/2;
        if(key==a[mid]){
            printf("Element found at position %d",mid+1);
            exit(0);
        }
        else if(a[mid]>key)
            ub=mid-1;
        else    
            lb=mid+1;
    }
    printf("Element not found");
}