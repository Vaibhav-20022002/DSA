#include <stdio.h>
int swap(int *a, int *b, int count, int i)
{
    if (count == i)
        return 0;
    else
    {
        int t = *a;
        *a = *b;
        *b = t;
        return 1;
    }
}
int countminswaps(int arr[], int n, int k)
{
    int counter = 0, count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
        {
            counter += swap(&arr[count], &arr[i], count, i);
            ++count;
        }
    return counter;
}
int main(void)
{
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("MINIMUM SWAPS : %d", countminswaps(arr, n, 5));
    return 0;
}