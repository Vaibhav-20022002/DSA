/*Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides the input array into two 
halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is 
used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and 
arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. See the following C implementation 
for details.

MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
*/
#include <stdio.h>
void merge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1;
    int n2 = h - m;
    int i, j, k;
    int left[n1], right[n2];
    for (i = 0; i < n1; ++i)
    {
        left[i] = arr[l + i];
    }
    for (j = 0; j < n2; ++j)
    {
        right[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            ++k;
            ++i;
        }
        else
        {
            arr[k] = right[j];
            ++k;
            ++j;
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        ++k;
        ++i;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        ++k;
        ++j;
    }
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low / 2 + high / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main(void)
{
    int arr[] = {5, 17, 4, 8, 9, 1, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
