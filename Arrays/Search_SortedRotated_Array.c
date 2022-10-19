//Time Complexity : O(logn)
//Space Complexity : O(1)

#include <stdio.h>
int search(int arr[], int left, int right, int key)
{
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[left] <= arr[mid])
        {
            if (key >= arr[left] && key <= arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (key > arr[mid] && key <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
int main(void)
{
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 1;
    printf("THE INDEX IS: %d", search(arr, 0, n - 1, key));
    return 0;
}