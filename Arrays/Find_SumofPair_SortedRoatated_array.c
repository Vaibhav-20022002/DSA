#include <stdio.h>
int findpivot(int arr[], int n)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            return mid;
        else if (arr[l] < arr[mid])
            l = mid;
        else
            r = mid;
    }
}
void findsumofpair(int arr[], int n, int sum, int *lowindex, int *highindex)
{
    *highindex = findpivot(arr, n);
    *lowindex = (*highindex + 1) % n;
    while (*lowindex != *highindex)
    {
        if (sum > arr[*lowindex] + arr[*highindex])
            *lowindex = (*lowindex + 1) % n;
        else if (sum < arr[*highindex] + arr[*lowindex])
            *highindex = (*highindex - 1 + n) % n;
        else
            return;
    }
}
int main(void)
{
    int arr[] = {11, 15, 6, 8, 9, 10}, lowindex=0, highindex=0;
    int n = sizeof(arr) / sizeof(arr[0]);
    findsumofpair(arr, n, 16, &lowindex, &highindex);
    printf("THE PAIR IS: (%d,%d)", lowindex, highindex);
    return 0;
}