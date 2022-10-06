//Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements ?

//THIS IS MY ALGORITHM :
// Time Complexity:   O(n*d)
// Space Complexity : O(1)

/*
#include <stdio.h>
void rotate(int arr[], int d, int n)
{
    while (d != 0)
    {
        int firstelement = arr[0];
        for (int i = 0; i < n - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = firstelement;
        --d;
    }
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
}
#include <stdio.h>
int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("ARRAY BEFORE ROTATION: ");
    printarr(arr, n);
    rotate(arr, 2, n);
    printf("\nARRAY AFTER ROTATION:  ");
    printarr(arr, n);
    return 0;
}
*/

//THIS IS BEST ALGORITHM :
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <stdio.h>
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
}
void reverse(int arr[], int start, int end)
{
    int temp;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate(int arr[], int d, int n)
{
    reverse(arr, 0, n - 1 - d);
    reverse(arr, n - d, n - 1);
    reverse(arr, 0, n - 1);
}
int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("ARRAY BEFORE ROTATION: ");
    printarr(arr, n);
    rotate(arr, 3, n);
    printf("\nARRAY AFTER ROTATION:  ");
    printarr(arr, n);
    return 0;
}
