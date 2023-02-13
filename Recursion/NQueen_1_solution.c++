// PRINTING ONLY ONE SOLUTION:
#include <iostream>
#include <vector>
using namespace std;
void printmat(vector<vector<int>> &mat, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
bool isSafe(int row, int col, vector<vector<int>> &mat, int n, vector<int> &firstHash, vector<int> &rowHash, vector<int> &thirdHash)
{
    if (rowHash[row] == 1 || thirdHash[row + col] == 1 || firstHash[n - 1 + row - col] == 1)
        return false;
    return true;
}
bool NQueen(int col, vector<vector<int>> &mat, int n, vector<int> &firstHash, vector<int> &rowHash, vector<int> &thirdHash)
{
    if (col == n)
    {
        printmat(mat, n);
        return true;
    }
    for (int row = 0; row < n; ++row)
    {
        if (isSafe(row, col, mat, n, firstHash, rowHash, thirdHash))
        {
            mat[row][col] = 1;
            firstHash[n - 1 + row - col] = 1;
            thirdHash[row + col] = 1;
            rowHash[row] = 1;
            if (NQueen(col + 1, mat, n, firstHash, rowHash, thirdHash))
                return true;
            mat[row][col] = 0;
            rowHash[row] = 0;
            thirdHash[row + col] = 0;
            firstHash[n - 1 + row - col] = 0;
        }
    }
    return false;
}
int main(void)
{
    int n = 4;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<int> rowHash(n, 0);
    vector<int> firstHash(2 * n - 2, 0);
    vector<int> thirdHash(2 * n - 2, 0);
    bool one = NQueen(0, mat, n, firstHash, rowHash, thirdHash);
    return 0;
}