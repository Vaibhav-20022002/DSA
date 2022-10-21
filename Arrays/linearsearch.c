#include <stdio.h>
int linearsearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == key)
        {
            return i + 1;
        }
    }
    return 0;
}
int main()
{
    int arr[] = {7, 5, 3, 6, 9, 8, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int find;
    printf("ENTER THE NUMBER YOU WANT TO SEARCH: ");
    scanf("%d", &find);
    int pos = linearsearch(arr, n, find);
    if (pos == 0)
    {
        printf("NO ELEMEMT IS FOUND!!!");
    }
    else
    {
        printf("THE POSITION OF THE ELEMENT IS %d", pos);
    }
    return 0;
}