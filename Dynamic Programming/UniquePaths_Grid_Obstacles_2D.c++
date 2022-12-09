// We are given an “N*M” Maze. The maze contains some obstacles. A cell is ‘blockage’ in the maze if its value is -1. 0 represents
// non-blockage. There is no path possible through a blocked cell.
// We need to count the total number of unique paths from the top-left corner of the maze to the bottom-right corner. At every cell, we
// can move either down or towards the right.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// TC -> O(2^(m*n))
// SC-> O((m - 1) + (n - 1)) => TOTAL LENGTH PATH
// int uniquePaths(int i, int j, vector<vector<int>> &matrix)
// {
//     //BASE CASE:
//     // IF REACHED THE STARTING POINT, THE OPTED PATH IS VALID AND UNIQUE SO RETURN 1:
//     if (i == 0 && j == 0)
//         return 1;
//     // IF THE PATH OPTED GOES OUT OF MATRIX THEN THE PATH IS INVALID, SO RETURN 0:
//     if (i < 0 || j < 0)
//         return 0;
//     // IF THE OPTED PATH CONTAINS THE DEAD CELL/OBSTACLE, THEN RETURN 0:
//     if (i >= 0 && j >= 0 && matrix[i][j] == -1)
//         return 0;

//     // ALLOWED MOVEMENTS ARE DOWN & RIGHT, BUT AS WE ARE MOVING DESTINATION -> STARTING POINT, SO MOVEMENTS GETS REVERSED !!!
//     int up = uniquePaths(i - 1, j, matrix);
//     int left = uniquePaths(i, j - 1, matrix);

//     // RETURN TOTAL NUMBER OF UNIQUE VALID PATHS:
//     return up + left;
// }

// MEMOIZATION:
// TC->O(m *n)
// SC->O((m - 1) + (n - 1)) + O(m *n) = > TOTAL LENGTH PATH + dp MATRIX
// int uniquePaths(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
// {
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (i == 0 && j == 0)
//         return dp[0][0] = 1;

//     if (i >= 0 && j >= 0 && matrix[i][j] == -1)
//         return 0;

//     int up = 0, left = 0;
//     if (i > 0)
//         up = uniquePaths(i - 1, j, matrix, dp);
//     if (j > 0)
//         left = uniquePaths(i, j - 1, matrix, dp);

//     // RETURN TOTAL NUMBER OF UNIQUE VALID PATHS:
//     return dp[i][j] = up + left;
// }

// TABULATION:
// int uniquePaths(int i, int j, vector<vector<int>> &matrix)
// {
//     vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
//     for (int x = 0; x <= i; ++x)
//     {
//         for (int y = 0; y <= j; ++y)
//         {
//             // BASE CASE:
//             if (x == 0 && y == 0)
//                 dp[0][0] = 1;

//             // IF THE OPTED PATH CONTAINS THE DEAD CELL/OBSTACLE, THEN MARK dp[x][y] AS 0:
//             else if (x >= 0 && y >= 0 && matrix[x][y] == -1)
//                 dp[x][y] = 0;

//             else
//             {
//                 int up = 0, left = 0;
//                 if (x > 0)
//                     // GOING UP IS POSSIBLE ONLY IF IT IS NOT THE FIRST ROW:
//                     up = dp[x - 1][y];
//                 if (y > 0)
//                     // GOING LEFT IS POSSIBLE ONLY IF IT IS NOT THE FIRST COLOUMN:
//                     left = dp[x][y - 1];
//                 dp[x][y] = up + left;
//             }
//         }
//     }
//     return dp[i][j];
// }

// SPACE OPTIMIZATION:
// TC -> O(m*n)
// SC -> O(n)
// BUT THERE IS MORE EFFICIENT WAY OF DOING THIS (check!!!):
// THIS IS ONLY A DYNAMIC PROGRAMMING APPROACH !!!
int uniquePaths(int i, int j, vector<vector<int>> &matrix)
{
    vector<int> prev(j + 1, 0);
    for (int x = 0; x <= i; ++x)
    {
        vector<int> curr(j + 1, 0);
        for (int y = 0; y <= j; ++y)
        {
            if (matrix[x][y] == -1)
            {
                curr[y] = 0;
            }
            else if (x == 0 && y == 0)
            {
                curr[0] = 1;
            }
            else
            {
                int up = 0, left = 0;
                if (x > 0)
                    up = prev[y];
                if (y > 0)
                    left = curr[y - 1];
                curr[y] = up + left;
            }
        }
        prev = curr;
    }
    return prev[j];
}
int main(void)
{
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix = {{0, 0, 0},
                                  {0, -1, 0},
                                  {0, 0, 0}};

    // RECURSION:
    // cout << uniquePaths(m - 1, n - 1, matrix);

    // MEMOIZATION:
    // AS THERE ARE OVERLAPPING SUBPROBLEMS SO WE CAN MEMOIZE IT !!!
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // cout << uniquePaths(m - 1, n - 1, matrix, dp);

    // TABULATION:
    // DONE TO REDUCE THE STACK SPACE USED IN RECURSIVE CALLS !
    // cout << uniquePaths(m - 1, n - 1, matrix);

    // SPACE OPTIMIZATION:
    // DONE TO REDUCE AUXILARY SPACE !
    cout << uniquePaths(m - 1, n - 1, matrix);
    return 0;
}