/*Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements 
if they are in wrong order.*/
#include <stdio.h>
void bubblesort(int arr[], int n)
{
    while (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }

        --n;
    }
}
int main(void)
{
    int arr[] = {8, 5, 0, 2, 5, 4, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}