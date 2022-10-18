//Time Cpmplexity: O(logn)
//Space Cpmplexity: O(1)

#include <stdio.h>
int findpivot(int arr[], int n)
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
int countrotate(int arr[], int n)
{
    return (findpivot(arr, n) + 1) % n;
}
int main(void)
{
    int arr[] = {5,6,1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("ROTATE COUNT IS: %d", countrotate(arr, n));
    return 0;
}