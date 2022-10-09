#include <stdio.h>
int Max_Subarray_Sum(int arr[], int n)
{
    int currmax = 0, trumax = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum > currmax)
            currmax = sum;
        else if (sum < 0)
            sum = 0;
        if (currmax > trumax)
            trumax = currmax;
    }
    return trumax;
}
int main(void)
{
    int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Max_Subarray_Sum(arr, n);
    printf("THE MAXIMUM SUBARRAY SUM : %d", Max_Subarray_Sum(arr, n));
    return 0;
}