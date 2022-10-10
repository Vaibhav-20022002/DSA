#include <stdio.h>
int check(int brr[], int nb, int key)
{
    for (int i = 0; i < nb; ++i)
    {
        if (brr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
int kadane(int arr[], int brr[], int na, int nb)
{
    int sofar = 0, high = 0, highest = 0;
    for (int i = 0; i < na; ++i)
    {
        int f = check(brr, nb, arr[i]);
        if (f == 0)
        {
            sofar += arr[i];
            if (high < sofar)
            {
                high = sofar;
            }
        }
        if (f == 1)
        {
            sofar = 0;
            high = 0;
        }
        if (high > highest)
        {
            highest = high;
        }
    }
    return highest;
}
int main(void)
{
    int arr[] = {3, 4, 5, -4, 6};
    int na = sizeof(arr) / sizeof(arr[0]);
    int brr[] = {1, 8, 5};
    int nb = sizeof(brr) / sizeof(brr[0]);
    printf("THE MAXIMUM SUBARRAY SUM IS: %d", kadane(arr, brr, na, nb));
    return 0;
}