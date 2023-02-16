#include <iostream>
#include <vector>
using namespace std;
int CountPaths(vector<vector<int>> arr, int r, int c, int i, int j)
{
    if (i == r || j == c || arr[i][j] == 0)
        return 0;
    if (i == r - 1 && j == c - 1)
        return 1;
    int cnt = 0;
    cnt += CountPaths(arr, r, c, i + 1, j);
    cnt += CountPaths(arr, r, c, i, j + 1);
    return cnt;
}
int main(void)
{
    int r = 3, c = 3;
    vector<vector<int>> arr = {{1, 0, 1}, {1, 1, 0}, {1, 1, 1}};
    cout << CountPaths(arr, r, c, 0, 0);
    return 0;
}