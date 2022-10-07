#include <stdio.h>
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void EvengreaterthanOdd(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        if ((i % 2 != 0 && arr[i] < arr[i + 1]) || (i % 2 == 0 && arr[i] > arr[i + 1]))
            swap(&arr[i], &arr[i + 1]);
}
int main(void)
{
    int arr[] = {1, 3, 2, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("ORIGINAL ARRAY: ");
    printarray(arr, n);
    EvengreaterthanOdd(arr, n);
    printf("\nMODIFIED ARRAY: ");
    printarray(arr, n);
    return 0;
}