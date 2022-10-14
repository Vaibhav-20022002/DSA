//MY SOLUTION :
//Time Complexity :O(n)
//Space Complexity :O(1)
/*
#include<stdio.h>
void moveallzeroestoend(int arr[], int n)
{
    int p;
    for (int i = 0; i < n; ++i)
        if (arr[i] == 0)
        {
            p = i;
            break;
        }
    for (int i = p; i < n; ++i)
        if (arr[i] != 0)
        {
            arr[p] = arr[i];
            ++p;
        }
    for (int i = p; i < n; ++i)
        arr[i] = 0;
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
int main(void)
{
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("ORIGINAL ARRAY: ");
    printarray(arr, n);
    moveallzeroestoend(arr, n);
    printf("\nMODIFIED ARRAY: ");
    printarray(arr, n);
    return 0;
}*/

//OPTIMIZED SOLUTION:
//Time Complexity: O(n)
//Space Complexity: O(1)
/*
#include <stdio.h>
void moveallzeroestoend(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] != 0)
            arr[count++] = arr[i];
    while (count < n)
        arr[count++] = 0;
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
int main(void)
{
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("ORIGINAL ARRAY: ");
    printarray(arr, n);
    moveallzeroestoend(arr, n);
    printf("\nMODIFIED ARRAY: ");
    printarray(arr, n);
    return 0;
}
*/
//BEST SOLUTION:
//Time Complexity: O(n)
//Space Complexity: O(1)
#include <stdio.h>
void swap(int *a, int *b)
{
    int p = *a;
    *a = *b;
    *b = p;
}
void moveallzeroestoend(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            swap(&arr[count++], &arr[i]);
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
int main(void)
{
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("ORIGINAL ARRAY: ");
    printarray(arr, n);
    moveallzeroestoend(arr, n);
    printf("\nMODIFIED ARRAY: ");
    printarray(arr, n);
    return 0;
}