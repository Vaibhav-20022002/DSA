/*Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in 
your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted 
part are picked and placed at the correct position in the sorted part.
Algorithm:
To sort an array of size n in ascending order:
1: Iterate from arr[1] to arr[n] over the array.
2: Compare the current element (key) to its predecessor.
3: If the key element is smaller than its predecessor, compare it to the elements before. 
Move the greater elements one position up to make space for the swapped element.
*/
#include <stdio.h>
void insertionsort(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; ++i)
    {
        key = arr[i];
        for (j = i - 1; (j >= 0 && arr[j] > key); --j)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}
int main(void)
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionsort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}