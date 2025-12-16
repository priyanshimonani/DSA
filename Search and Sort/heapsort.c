#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void RestoreHeapUp(int Heap[], int index);
void RestoreHeapDown(int Heap[], int index, int n);

void main() {
    int Heap[MAX];
    int n, i, j;

    printf("Enter no. of elements: ");
    scanf("%d", &n);
    // build max-heap by inserting one by one (1-based index)
    printf("Enter elements:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &Heap[i]);        // read next element into heap
        RestoreHeapUp(Heap, i);      // fix heap upwards after insert
    }
    j = n;
    while(n>=1) {
        int temp=Heap[1];    // root (max element)
        Heap[1] = Heap[n];       // move last to root
        Heap[n] = temp;          // put max at the end
        n = n - 1;               // reduce heap size
        RestoreHeapDown(Heap, 1, n);
    }
    n = j;  // restore n (now array 1..n is sorted)

    // display sorted array
    printf("\nSorted array (ascending):\n");
    for (i = 1; i <= n; i++)
        printf("%d ", Heap[i]);
    printf("\n");
}

// Percolate up: fix heap after inserting at position `index`
void RestoreHeapUp(int Heap[], int index) {
    int i = index;
    while (i > 1 && Heap[i] > Heap[i / 2]) {   // parent = i/2
        int temp = Heap[i];
        Heap[i] = Heap[i / 2];
        Heap[i / 2] = temp;
        i = i / 2;                             // move up
    }
}

// Percolate down: fix heap after removing root
void RestoreHeapDown(int Heap[], int index, int n) {
    int i = index;
    int j = 2 * i;          // left child index

    while (j <= n) {
        // choose larger child (right child exists and is bigger)
        if (j < n && Heap[j] < Heap[j + 1])
            j = j + 1;

        // if parent is already larger, heap property satisfied
        if (Heap[i] >= Heap[j])
            break;

        // swap parent with larger child
        int temp = Heap[i];
        Heap[i] = Heap[j];
        Heap[j] = temp;

        // move down
        i = j; //parent
        j = 2 * i; //child
    }
}
