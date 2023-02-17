#include <iostream>
#include <vector>
using namespace std;
void subsets(int arr[], int n, int ind, vector<int> &ds)
{
    if (ind == n)
    {
        for (auto it : ds)
            cout << it << " ";
        cout << "\n";
        return;
    }
    ds.emplace_back(arr[ind]);
    subsets(arr, n, ind + 1, ds);
    ds.pop_back();
    subsets(arr, n, ind + 1, ds);
}
int main(void)
{
    int arr[] = {4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ds;
    subsets(arr, n, 0, ds);
    return 0;
}