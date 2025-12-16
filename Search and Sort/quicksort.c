#include <stdio.h>
#include <stdlib.h>

int a[8] = {50, 30, 20, 40, 80, 10, 60, 70};
 
void swap(int i, int j) { //swap using idces for global array
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int Position(int low, int high) {
    int pivot = a[high];
    int i = low;
    int j = low;     // both start at low

    while (i < high) {
        if (a[i] < pivot) {
            swap(i, j);
            j++;
        }
        i++;
    }

    swap(j, high);   // pivot placed in the correct index
    return j;        // return pivot index
}

void quickSort(int low, int high) {
    if (low < high) {
        int p = Position(low, high);
        quickSort(low, p - 1); //p-1 imppppp
        quickSort(p + 1, high);
    }
}

void main() {
    int n = 8;
    quickSort(0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}
