#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[7] = {50, 30, 20, 40, 80, 10, 60}; 
void swap(int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
int partition(int low, int high) {
    int pivot = a[high];   // last element as pivot
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(i, j);
        }
    }

    swap(i + 1, high);   // put pivot in correct location

    return i + 1;        // return pivot index
}
void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}
void main() {
    int n = 7;

    quickSort(0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}