// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom
// row. The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
// You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to
// i or i + 1 index in row j + 1 in each step.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// TC -> O(2^(1+2+3+...+n))
// SC -> O(n)
// int minPathSum(int i, int j, int n, vector<vector<int>> &Triangle)
// {
//     // BASE CASE:
//     // IF ROW NUMBER GETS EQUAL TO THE LAST ROW, THEN RETURN THE VALUE AT THAT INDEX :
//     if (i == n - 1)
//         return Triangle[n - 1][j];

//     // AS WE ARE GOING STARTING POINT => ENDING POINT, THAT'S WHY NO CHANGE IN ALLOWED MOVEMENTS:
//     int down = Triangle[i][j] + minPathSum(i + 1, j, n, Triangle);
//     int diagonal = Triangle[i][j] + minPathSum(i + 1, j + 1, n, Triangle);

//     // RETURN MINIMUM AMONG THEM:
//     return min(down, diagonal);
// }

// MEMOIZATION:
// TC -> O(n*n), APPROX AS THE GIVEN MATRIX IS TRIANGULAR
// SC -> O(n) + O(n), RECURSION STACK SPACE + DP MATRIX
// int minPathSum(int i, int j, int n, vector<vector<int>> &Triangle, vector<vector<int>> &dp)
// {
//     if (i == n - 1)
//         return Triangle[n - 1][j];

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int down = Triangle[i][j] + minPathSum(i + 1, j, n, Triangle, dp);
//     int diagonal = Triangle[i][j] + minPathSum(i + 1, j + 1, n, Triangle, dp);

//     // RETURN MINIMUM AMONG THEM:
//     return min(down, diagonal);
// }

// TABULATION:
// TC -> O(n*n), APPROX AS THE GIVEN MATRIX IS TRIANGULAR
// SC -> O(n), DP MATRIX
// int minPathSum(int n, vector<vector<int>> &Triangle)
// {
//     vector<vector<int>> dp(n, vector<int>(n, 0));
//     // TABULATION ALWAYS BE DONE IN OPPOSITE MANNER OF RECURSION:
//     // AS RECURSION IS FROM STARTING POINT => ENDING POINT, SO TABULATION IS FROM ENDING POINT => STARTING POINT !!!
//     for (int i = n - 1; i >= 0; --i)
//     {
//         for (int j = i; j >= 0; --j)
//         {
//             if (i == n - 1)
//                 dp[i][j] = Triangle[i][j];
//             else
//             {
//                 int down = Triangle[i][j] + dp[i + 1][j];
//                 int diagonal = Triangle[i][j] + dp[i + 1][j + 1];
//                 dp[i][j] = min(down, diagonal);
//             }
//         }
//     }

//     // RETURN THE LAST TABULATED DP'S INDEX VALUE:
//     return dp[0][0];
// }

// SPACE OPTIMIZATION:
// TC -> O(n*n), APPROX AS THE GIVEN MATRIX IS TRIANGULAR
// SC -> O(n), PREVIOUS ROW
int minPathSum(int n, vector<vector<int>> &Triangle)
{
    // PREVIOUS ROW:
    vector<int> prev(n, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        // CURRENT ROW:
        vector<int> curr(n, 0);
        for (int j = n - 1; j >= 0; --j)
        {
            if (i == n - 1)
                curr[j] = Triangle[i][j];
            else
            {
                int down = Triangle[i][j] + prev[j];
                int diagonal = Triangle[i][j] + prev[j + 1];
                curr[j] = min(down, diagonal);
            }
        }
        prev = curr;
    }
    // RETURN THE LAST COMPUTED INDEX:
    return prev[0];
}
int main(void)
{
    int n = 4;
    vector<vector<int>> Triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    // RECURSION:
    // cout << minPathSum(0, 0, n, Triangle);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(4, -1));
    // cout << minPathSum(0, 0, n, Triangle, dp);

    // TABULATION:
    // cout << minPathSum(n, Triangle);

    // SPACE OPTIMIZATION:
    cout << minPathSum(n, Triangle);
    return 0;
}