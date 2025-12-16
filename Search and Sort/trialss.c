#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int Heap[MAX];
//parent index i/2 for 1 based array
void input(){
    int n,i;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    printf("Enter value: ");
    for(i=1;i<=n;i++){
        scanf("%d", &Heap[i]);
        HeapUp();
    }
}
void HeapUp(int index){
    int i=index;
    while(i>1 && Heap[i]>Heap[i/1]){
        int temp = Heap[i];
        Heap[i] = Heap[i / 2];
        Heap[i / 2] = temp;
        i = i / 2;
    }
}
void HeapDown(int index, int n){
    int i=index;
    int j=2*i;
    while(j<=n){
        if (j < n && Heap[j] < Heap[j + 1])
            j = j + 1;
        if (Heap[i] >= Heap[j])
            break;
        int temp = Heap[i];
        Heap[i] = Heap[j];
        Heap[j] = temp;
        i=j;
        j=2*i;
    }
}