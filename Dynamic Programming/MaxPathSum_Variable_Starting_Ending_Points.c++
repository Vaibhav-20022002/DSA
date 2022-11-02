// You have been given an M*N matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from
// any cell in the first row to any cell in the last row.
// From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular
// cell (row, col), we can move in three directions

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// TC -> O(3 ^ (m * n))
// SC -> O(n) => PATH LENGTH STACK SPACE
// int f(int i, int j, int n, vector<vector<int>> &matrix)
// {
//     // BASE CASE 1:
//     // IF TRAVERSING THE MATRIX, PATH GOES OUT OF BOUND(ONLY DUE TO LEFT AND RIGHT DIAGONAL MOVEMENTS), RETURN A LARGE NEGATIVE VALUE:
//     if (j < 0 || j >= n)
//         return -1e9;

//     // BASE CASE 2:
//     // IF WE REACH AT THE 0th(FIRST ROW), RETURN THE VALUE AT THAT INDEX OF THE MATRIX:
//     if (i == 0)
//         return matrix[0][j];

//     // AS WE ARE MOVING FROM ENDING => STARTING, THE ALLOWED MOVEMENTS GETS REVERSED:
//     int up = matrix[i][j] + f(i - 1, j, n, matrix);
//     int Ldiagonal = matrix[i][j] + f(i - 1, j - 1, n, matrix);
//     int Rdiagonal = matrix[i][j] + f(i - 1, j + 1, n, matrix);

//     // RETURN MAXIMUM AMONG THEM:
//     return max(up, max(Ldiagonal, Rdiagonal));
// }
// int maxPathSum(int m, int n, vector<vector<int>> &matrix)
// {
//     // TAKING SMALLEST VALUE POSSIBLE, AS MATRIX CAN CONTAIN NEGATIVE VALUES:
//     int maxi = -1e9;
//     for (int j = 0; j < n; ++j)
//         maxi = max(maxi, f(m - 1, j, n, matrix));
//     return maxi;
// }

// MEMOIZATION:
// TC -> O(m * n)
// SC -> O(n) + O(m * n) => PATH LENGTH STACK SPACE + DP MATRIX
// int f(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
// {
//     // BASE CASE 1:
//     // IF TRAVERSING THE MATRIX, PATH GOES OUT OF BOUND(ONLY DUE TO LEFT AND RIGHT DIAGONAL MOVEMENTS), RETURN A LARGE NEGATIVE VALUE:
//     if (j < 0 || j >= n)
//         return -1e9;

//     // BASE CASE 2:
//     // IF WE REACH AT THE 0th(FIRST ROW), RETURN THE VALUE AT THAT INDEX OF THE MATRIX:
//     if (i == 0)
//         return matrix[0][j];

//     // BASE CASE 3:
//     // IF THE RECURSION FOR ith & jth IS PRE-COMPUTED, THEN RETURN STORED VALUE:
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // AS WE ARE MOVING FROM ENDING => STARTING, THE ALLOWED MOVEMENTS GETS REVERSED:
//     int up = matrix[i][j] + f(i - 1, j, n, matrix, dp);
//     int Ldiagonal = matrix[i][j] + f(i - 1, j - 1, n, matrix, dp);
//     int Rdiagonal = matrix[i][j] + f(i - 1, j + 1, n, matrix, dp);

//     // RETURN MAXIMUM AMONG THEM:
//     return dp[i][j] = max(up, max(Ldiagonal, Rdiagonal));
// }
// int maxPathSum(int m, int n, vector<vector<int>> &matrix)
// {
//     // TAKING SMALLEST VALUE POSSIBLE, AS MATRIX CAN CONTAIN NEGATIVE VALUES:
//     int maxi = -1e9;
//     // CREATING DP FOR MEMOIZATION:
//     vector<vector<int>> dp(m, vector<int>(n, -1));
//     for (int j = 0; j < n; ++j)
//         maxi = max(maxi, f(m - 1, j, n, matrix, dp));
//     return maxi;
// }

// TABULATION:
// TC -> O(m * n) + O(n) => FOR NESTED LOOPS + CALCULATING MAXIMUM AMONG LAST COMPUTED ROW IN TABULATION MATRIX
// SC -> O(m * n) => DP MATRIX
// int maxPathSum(int m, int n, vector<vector<int>> &matrix)
// {
//     // CREATING A TABULATION MATRIX:
//     vector<vector<int>> dp(m, vector<int>(n, 0));

//     for (int i = 0; i < m; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             // BASE CASE:
//             if (i == 0)
//                 dp[0][j] = matrix[0][j];
//             else
//             {
//                 int Ldiagonal = -1e9, Rdiagonal = -1e9;
//                 int up = matrix[i][j] + dp[i - 1][j];
//                 // OUT OF BOUND CONDITION:
//                 if (j > 0)
//                     Ldiagonal = matrix[i][j] + dp[i - 1][j - 1];
//                 // OUT OF BOUND CONDITION:
//                 if (j < n - 1)
//                     Rdiagonal = matrix[i][j] + dp[i - 1][j + 1];

//                 // STORING MAXIMUM AMONG THEM:
//                 dp[i][j] = max(up, max(Ldiagonal, Rdiagonal));
//             }
//         }
//     }
//
//     // RETURN THE MAXIMUM AMONG THE LAST ROW OF THE TABULATED MATRIX:
//     int maxi = -1e9;
//     for (int j = 0; j < n; ++j)
//         maxi = max(maxi, dp[m - 1][j]);
//     return maxi;
// }

// SPACE OPTIMIZATION:
// TC -> O(m * n) + O(n) => FOR NESTED LOOPS + CALCULATING MAXIMUM AMONG LAST COMPUTED ROW
// SC -> O(n) => STORING PREVIOUS ROW
int maxPathSum(int m, int n, vector<vector<int>> &matrix)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; ++i)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; ++j)
        {
            // BASE CASE:
            if (i == 0)
                curr[j] = matrix[0][j];
            else
            {
                int Ldiagonal = -1e9, Rdiagonal = -1e9;
                int up = matrix[i][j] + prev[j];
                // OUT OF BOUND CONDITION:
                if (j > 0)
                    Ldiagonal = matrix[i][j] + prev[j - 1];
                // OUT OF BOUND CONDITION:
                if (j < n - 1)
                    Rdiagonal = matrix[i][j] + prev[j + 1];

                // STORING MAXIMUM AMONG THEM:
                curr[j] = max(up, max(Ldiagonal, Rdiagonal));
            }
        }
        prev = curr;
    }

    // RETURN THE MAXIMUM AMONG THE LAST ROW OF THE TABULATED MATRIX:
    int maxi = -1e9;
    for (int j = 0; j < n; ++j)
        maxi = max(maxi, prev[j]);
    return maxi;
}
int main(void)
{
    int m = 4;
    int n = 4;
    vector<vector<int>> matrix = {{1, 2, 10, 4},
                                  {100, 3, 2, 1},
                                  {1, 1, 20, 2},
                                  {1, 2, 2, 1}};

    // RECURSION:
    // cout << maxPathSum(m, n, matrix);

    // MEMOIZATION:
    // cout << maxPathSum(m, n, matrix);

    // TABULATION:
    // cout << maxPathSum(m, n, matrix);

    // SPACE OPTIMIZATION:
    cout << maxPathSum(m, n, matrix);
    return 0;
}