// We are given an “M*N” matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix,
// such that there is a minimum cost past that we select.
// At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of
// the given matrix.
#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// TC -> O(2^(m*n))
// SC-> O((m - 1) + (n - 1)) => TOTAL LENGTH PATH
// int minPathSum(int i, int j, vector<vector<int>> &matrix)
// {
//     //BASE CASE:
//     // IF REACHED THE STARTING POINT RETURN THE STARTING INDEX'S VALUE:
//     if (i == 0 && j == 0)
//         return matrix[0][0];

//     // IF THE PATH OPTED GOES OUT OF MATRIX THEN THE PATH IS INVALID, SO RETURN THE MAXIMUM VALUE THAT IS NOT POSSIBLE:
//     if (i < 0 || j < 0)
//         return INT16_MAX;

//     // ALLOWED MOVEMENTS ARE DOWN & RIGHT, BUT AS WE ARE MOVING DESTINATION -> STARTING POINT, SO MOVEMENTS GETS REVERSED !!!
//     int up = matrix[i][j] + minPathSum(i - 1, j, matrix);
//     int left = matrix[i][j] + minPathSum(i, j - 1, matrix);
//     return min(up, left);
// }

// MEMOIZATION:
// TC->O(m *n)
// SC->O((m - 1) + (n - 1)) + O(m *n) = > TOTAL LENGTH PATH + dp MATRIX
// int minPathSum(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
// {
//     if (i == 0 && j == 0)
//         return dp[0][0] = matrix[0][0];

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int up = INT16_MAX, left = INT16_MAX;
//     if (i > 0)
//         up = matrix[i][j] + minPathSum(i - 1, j, matrix, dp);
//     if (j > 0)
//         left = matrix[i][j] + minPathSum(i, j - 1, matrix, dp);

//     // RETURN MINIMUM PATH SUM:
//     return dp[i][j] = min(up, left);
// }

// TABULATION:
// TC -> O(m *n)
// SC -> O(m *n) = > dp MATRIX
// int minPathSum(int i, int j, vector<vector<int>> &matrix)
// {
//     vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
//     for (int x = 0; x <= i; ++x)
//     {
//         for (int y = 0; y <= j; ++y)
//         {
//             if (x == 0 && y == 0)
//                 dp[0][0] = matrix[0][0];

//             else
//             {
//                 int up = INT16_MAX, left = INT16_MAX;
//                 if (x > 0)
//                     up = matrix[x][y] + dp[x - 1][y];
//                 if (y > 0)
//                     left = matrix[x][y] + dp[x][y - 1];

//                 dp[x][y] = min(up, left);
//             }
//         }
//     }
//     return dp[i][j];
// }

// SPACE OPTIMIZATION:// TC -> O(m*n)
// SC -> O(n)
// BUT THERE IS MORE EFFICIENT WAY OF DOING THIS (check!!!):
// THIS IS ONLY A DYNAMIC PROGRAMMING APPROACH !!!
int minPathSum(int i, int j, vector<vector<int>> &matrix)
{
    vector<int> prev(j + 1, 0);
    for (int x = 0; x <= i; ++x)
    {
        vector<int> curr(j + 1, 0);
        for (int y = 0; y <= j; ++y)
        {
            if (x == 0 && y == 0)
                curr[0] = matrix[0][0];
            else
            {
                int up = INT16_MAX, left = INT16_MAX;
                if (x > 0)
                    up = matrix[x][y] + prev[y];
                if (y > 0)
                    left = matrix[x][y] + curr[y - 1];

                curr[y] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[j];
}
int main(void)
{
    int m = 2;
    int n = 3;
    vector<vector<int>> matrix = {{5, 9, 6},
                                  {11, 5, 2}};

    //   RECURSION:
    // cout << minPathSum(m - 1, n - 1, matrix);

    // MEMOIZATION:
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << minPathSum(m - 1, n - 1, matrix, dp);#

    // TABULATION:
    // cout << minPathSum(m - 1, n - 1, matrix);

    // SPACE OPTIMIZATION:
    cout << minPathSum(m - 1, n - 1, matrix);
    return 0;
}