//Given an array of integers, task is to print the array in the order –
//smallest number, Largest number, 2nd smallest number, 2nd largest number,
// 3rd smallest number, 3rd largest number and so on…..
//Time Complexity : O(n Log n) 
//Auxiliary Space : O(n)
/*
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
void rearrange(int arr[], int n)
{
    quicksort(arr, 0, n - 1);
    int temparray[n];
    int i = 0, j = n - 1, k = 0;
    while (k < n)
    {
        if (k % 2 == 0)
        {
            temparray[k] = arr[i];
            ++i;
        }
        else
        {
            temparray[k] = arr[j];
            --j;
        }
        ++k;
    }
    for (int q = 0; q < n; ++q)
        arr[q] = temparray[q];
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
int main(void)
{
    int arr[] = {5, 8, 1, 4, 2, 9, 3, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("ORIGINAL ARRAY: ");
    printarray(arr, n);
    rearrange(arr, n);
    printf("\nMODIFIED ARRAY: ");
    printarray(arr, n);
    return 0;
}
*/
//Time Complexity : O(n) 
//Auxiliary Space : O(1)

//C++ CODE: 
// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;

// Prints max at first position, min at second position
// second max at third position, second min at fourth
// position and so on.
void rearrange(int arr[], int n)
{
	// initialize index of first minimum and first
	// maximum element
	int max_idx = n - 1, min_idx = 0;

	// store maximum element of array
	int max_elem = arr[n - 1] + 1;

	// traverse array elements
	for (int i = 0; i < n; i++) {
		// at even index : we have to put maximum element
		if (i % 2 == 0) {
			arr[i] += (arr[max_idx] % max_elem) * max_elem;
			max_idx--;
		}

		// at odd index : we have to put minimum element
		else {
			arr[i] += (arr[min_idx] % max_elem) * max_elem;
			min_idx++;
		}
	}

	// array elements back to it's original form
	for (int i = 0; i < n; i++)
		arr[i] = arr[i] / max_elem;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1,3,4,7,10,15,45 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	rearrange(arr, n);

	cout << "\nModified Array: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
