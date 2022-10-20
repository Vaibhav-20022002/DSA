#include <stdio.h>
int binarysearch(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low / 2 + high / 2;
        if (key == arr[mid])
        {
            return mid + 1;
        }
        if (key < arr[mid])
        {
            return binarysearch(arr, low, mid - 1, key);
        }
        return binarysearch(arr, mid + 1, high, key);
    }
    return -1;
}
int main(void)
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int find;
    printf("ENTER THE NUMBER YOU WANT TO SEARCH ");
    scanf("%d", &find);
    printf("\nTHE POSITION OF THE ELEMENT IS %d", binarysearch(arr, 0, n - 1, find));
}