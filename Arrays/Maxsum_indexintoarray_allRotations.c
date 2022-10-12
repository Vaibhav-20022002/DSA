//Time Complexity: O(n)
//Space Complexity: O(1)

#include <stdio.h>
int findpivotindex(int arr[], int n)
{
    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[left] < arr[mid])
            left = mid;
        else if (arr[mid] > arr[(mid - 1 + n) % n] && arr[mid] > arr[(mid + 1) % n])
            return mid;
        else if (left == right)
            return (mid + 1) % n;
        else
            right = mid;
    }
}
int maxsum(int arr[], int n)
{
    int sum = 0;
    int pivotindex = findpivotindex(arr, n);
    int diff = n - 1 + -pivotindex;
    for (int i = 0; i < n; ++i)
        sum += ((i + diff) % n) * arr[i];
    return sum;
}
int main(void)
{
    int arr[] = {8, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("THE MAXIMUM SUM OF (i*arr[i]) AMONG ALL ROTATIONS IS: %d", maxsum(arr, n));
    return 0;
}