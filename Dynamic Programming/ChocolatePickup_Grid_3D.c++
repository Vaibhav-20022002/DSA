// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he
// wants to collect as many chocolates as possible with the help of his friends.
// Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of
// them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates
// in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick
// the chocolates in it.
// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the
// ‘GRID’.
// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// TC -> O(3^(r * c) + 3(r * c)) => EXPLORING ALL GRID TWICE, ONE BY ALICE AND ONE BY BOB
// SC -> O(c) => AUXILARY STACK SPACE EQUAL TO THE PATH LENGTH
// int maxChocolates(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
// {
//     // OUT OF BOUND CASE:
//     if (j1 < 0 || j2 < 0 || j1 == c || j2 == c)
//         // AS CALCULATING THE MAXIMUM, RETURN THE LARGE NEGATIVE NUMBER TO MAKE AVOID THE PATH:
//         return -1e9;
//
//     // BASE CASE :
//     if (i == r - 1)
//     {
//         if (j1 == j2)
//             return grid[r - 1][j1];
//         return grid[r - 1][j1] + grid[r - 1][j2];
//     }
//
//     // TAKE VARIABLE TO STORE MAXIMUM NUMBER OF CHOCOLATES AND ASSIGN IT ZERO, BECAUSE THERE ARE NO NEGATIVE VALUE TO DECREASE IT:
//     int maxi = 0;
//     // dj1 => CHANGE IN COLOUMN OF ALICE ([j1-1], [j1], [j1+1]):
//     for (int dj1 = -1; dj1 <= 1; ++dj1)
//     {
//         // dj2 => CHANGE IN COLOUMN OF BOB ([j2-1], [j2], [j2+1]):
//         for (int dj2 = -1; dj2 <= 1; ++dj2)
//         {
//             // IF ALICE AND BOB ARE ON THE SAME BOX OF THE GRID, COLLECT THE CHOCOLATES ONCE:
//             if (j1 == j2)
//                 maxi = max(maxi, grid[i][j1] + maxChocolates(i + 1, j1 + dj1, j2 + dj2, r, c, grid));
//             else
//                 maxi = max(maxi, grid[i][j1] + grid[i][j2] + maxChocolates(i + 1, j1 + dj1, j2 + dj2, r, c, grid));
//         }
//     }
//     // RETURN THE MAXIMUM CHOCOLATE COLLECTED BY ALICE AND BOB:
//     return maxi;
// }

// MEMOIZATION:
// TC -> O(r*c*c)
// SC -> O(c) + O(r*c*c) => AUXILARY STACK SPACE EQUAL TO THE PATH LENGTH + MEMOIZED MATRIX
// int maxChocolates(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
// {
//     // OUT OF BOUND CASE:
//     if (j1 < 0 || j2 < 0 || j1 == c || j2 == c)
//         // AS CALCULATING THE MAXIMUM, RETURN THE LARGE NEGATIVE NUMBER TO MAKE AVOID THE PATH:
//         return -1e9;
//
//     // BASE CASE :
//     if (i == r - 1)
//     {
//         if (j1 == j2)
//             return dp[i][j1][j2] = grid[r - 1][j1];
//         return dp[i][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
//     }
//
//     // IF RECURSION CALL FOR <i, j1, j2> IS ALREADY COMPUTED, SIMPLY RETURN THE STORED ONE:
//     if (dp[i][j1][j2] != -1)
//         return dp[i][j1][j2];
//

//     // TAKE VARIABLE TO STORE MAXIMUM NUMBER OF CHOCOLATES AND ASSIGN IT ZERO, BECAUSE THERE ARE NO NEGATIVE VALUE TO DECREASE IT:
//     int maxi = 0;
//     // dj1 => CHANGE IN COLOUMN OF ALICE ([j1-1], [j1], [j1+1]):
//     for (int dj1 = -1; dj1 <= 1; ++dj1)
//     {
//         // dj2 => CHANGE IN COLOUMN OF BOB ([j2-1], [j2], [j2+1]):
//         for (int dj2 = -1; dj2 <= 1; ++dj2)
//         {
//             // IF ALICE AND BOB ARE ON THE SAME BOX OF THE GRID, COLLECT THE CHOCOLATES ONCE:
//             if (j1 == j2)
//                 maxi = max(maxi, grid[i][j1] + maxChocolates(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp));
//             else
//                 maxi = max(maxi, grid[i][j1] + grid[i][j2] + maxChocolates(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp));
//         }
//     }
//     // RETURN THE MAXIMUM CHOCOLATE COLLECTED BY ALICE AND BOB:
//     return dp[i][j1][j2] = maxi;
// }

// TABULATION:
// TC -> O(r*c*c)
// SC -> O(r*c*c) => DP MATRIX
// ALWAYS WRITE BASE CASE OUTSIDE THE TABULATION LOOPS OTHERWISE IT MIGHT LEAD TO TLE, AS IT REPEATEDLY CHECK FOR BASE CONDITION !
// int maxChocolates(int r, int c, vector<vector<int>> &grid)
// {
//     // CREATING A 3-D VECTOR FOR THE PARAMETERS <i, j1, j2> :: <r, c, c> :
//     vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

//     // BASE CASE:
//     for (int j1 = 0; j1 < c; ++j1)
//     {
//         for (int j2 = 0; j2 < c; ++j2)
//         {
//             if (j1 == j2)
//                 dp[r - 1][j1][j2] = grid[r - 1][j1];
//             else
//                 dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
//         }
//     }

//     // AS BASE CASE IS ALREADY CONSIDERED, RUN LOOPS FROM r-2 => 0:
//     for (int i = r - 2; i >= 0; --i)
//     {
//         for (int j1 = 0; j1 < c; ++j1)
//         {
//             for (int j2 = 0; j2 < c; ++j2)
//             {
//                 // TAKE VARIABLE TO STORE MAXIMUM NUMBER OF CHOCOLATES AND ASSIGN IT ZERO, BECAUSE THERE ARE NO NEGATIVE VALUE
//                 // TO DECREASE IT:
//                 int maxi = 0;
//                 // JUST WRITE THE RECURRENCE:
//                 // dj1 => CHANGE IN COLOUMN OF ALICE ([j1-1], [j1], [j1+1]):
//                 for (int dj1 = -1; dj1 <= 1; ++dj1)
//                 {
//                     // dj2 => CHANGE IN COLOUMN OF BOB ([j2-1], [j2], [j2+1]):
//                     for (int dj2 = -1; dj2 <= 1; ++dj2)
//                     {
//                         // IF ALICE AND BOB ARE ON THE SAME BOX OF THE GRID, COLLECT THE CHOCOLATES ONCE:
//                         if (j1 == j2 && j1 + dj1 >= 0 && j1 + dj1 < c)
//                             maxi = max(maxi, grid[i][j1] + dp[i + 1][j1 + dj1][j2 + dj2]);
//                         else if (j1 + dj1 >= 0 && j2 + dj2 >= 0 && j1 + dj1 < c && j2 + dj2 < c)
//                             maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + dj1][j2 + dj2]);
//                     }
//                 }
//                 // RETURN THE MAXIMUM CHOCOLATE COLLECTED BY ALICE AND BOB:
//                 dp[i][j1][j2] = maxi;
//             }
//         }
//     }

//     // RETURN THE INITIAL POSITION INDEX VALUE OF ALICE AND BOB:
//     return dp[0][0][c - 1];
// }

// SPACE OPTIMIZATION:
// TC -> O(r*c*c)
// SC -> O(c*c) => PREVIOUS ROW
int maxChocolates(int r, int c, vector<vector<int>> &grid)
{
    // 2-D VECTOR FOR STORING PREVIOUS ROW:
    vector<vector<int>> prev(c, vector<int>(c, 0));
    for (int j1 = 0; j1 < c; ++j1)
    {
        for (int j2 = 0; j2 < c; ++j2)
        {
            if (j1 == j2)
                prev[j1][j2] = grid[r - 1][j1];
            else
                prev[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    // AS BASE CASE IS ALREADY CONSIDERED, RUN LOOPS FROM r-2 => 0:
    for (int i = r - 2; i >= 0; --i)
    {
        // 2-D VECTOR FOR STORING CURRENT ROW:
        vector<vector<int>> curr(c, vector<int>(c, 0));
        for (int j1 = 0; j1 < c; ++j1)
        {
            for (int j2 = 0; j2 < c; ++j2)
            {
                // TAKE VARIABLE TO STORE MAXIMUM NUMBER OF CHOCOLATES AND ASSIGN IT ZERO, BECAUSE THERE ARE NO NEGATIVE VALUE
                // TO DECREASE IT:
                int maxi = 0;
                // JUST WRITE THE RECURRENCE:
                // dj1 => CHANGE IN COLOUMN OF ALICE ([j1-1], [j1], [j1+1]):
                for (int dj1 = -1; dj1 <= 1; ++dj1)
                {
                    // dj2 => CHANGE IN COLOUMN OF BOB ([j2-1], [j2], [j2+1]):
                    for (int dj2 = -1; dj2 <= 1; ++dj2)
                    {
                        // IF ALICE AND BOB ARE ON THE SAME BOX OF THE GRID, COLLECT THE CHOCOLATES ONCE:
                        if (j1 == j2 && j1 + dj1 >= 0 && j1 + dj1 < c)
                            maxi = max(maxi, grid[i][j1] + prev[j1 + dj1][j2 + dj2]);
                        else if (j1 + dj1 >= 0 && j2 + dj2 >= 0 && j1 + dj1 < c && j2 + dj2 < c)
                            maxi = max(maxi, grid[i][j1] + grid[i][j2] + prev[j1 + dj1][j2 + dj2]);
                    }
                }
                // RETURN THE MAXIMUM CHOCOLATE COLLECTED BY ALICE AND BOB:
                curr[j1][j2] = maxi;
            }
        }
        prev = curr;
    }

    // RETURN THE INITIAL POSITION INDEX VALUE OF ALICE AND BOB:
    return prev[0][c - 1];
}
int main(void)
{
    int r = 3;
    int c = 4;
    vector<vector<int>> grid = {{2, 3, 1, 2},
                                {3, 4, 2, 2},
                                {5, 6, 3, 5}};

    // RECURSION:
    // cout << maxChocolates(0, 0, c - 1, r, c, grid);

    // MEMOIZATION:
    // CREATING A 3-D VECTOR FOR THE PARAMETERS <i, j1, j2> :: <r, c, c> :
    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    // cout << maxChocolates(0, 0, c - 1, r, c, grid, dp);

    // TABULATION:
    // cout << maxChocolates(r, c, grid);

    // SPACE OPTIMIZATION:
    cout << maxChocolates(r, c, grid);
    return 0;
}