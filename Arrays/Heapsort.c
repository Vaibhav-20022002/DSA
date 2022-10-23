#include <stdio.h>
#define left(i) (i<<1) //SAME AS "left=2*i+1"
#define right(i) (i<<1)+1//SAME AS "right=2*i+2"
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = left(i);
    int right =right(i);
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n>>1; i >= 0; --i)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i - 1, 0);
    }
}
int main(void)
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("UNSORTED ARRAY: ");
    printarray(arr, n);
    heapSort(arr, n);
    printf("\nSORTED ARRAY:   ");
    printarray(arr, n);
    return 0;
}
