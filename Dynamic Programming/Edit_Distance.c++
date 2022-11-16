// You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find the "Edit Distance" between the strings.
// Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can
// perform the following three operations:
//     1. Delete a character
//     2. Replace a character with another one
//     3. Insert a character

// Note:
// Strings don't contain spaces in between.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// TC -> O(exp)
// SC -> O(n + m) => AUXILIARY STACK SPACE
// int makeString(int i, int j, string &s1, string &s2)
// {
//     // BASE CASE:
//     // IF THE SECOND STRING GETS EXHAUSTED, DELETE REMAINING CHARACTERES AND ADD MOVES:
//     if (j < 0)
//         return i + 1;
//     // IF THE FIRST STRING GETS EXHAUSTED, INSERT REMAINING CHARACTERS AND ADD MOVES:
//     if (i < 0)
//         return j + 1;

//     // IF THE CHARACTERS ARE MATCHING, NO NEED TO ADD MOVES, AND REDUCE BOTH i & j:
//     if (s1[i] == s2[j])
//         return 0 + makeString(i - 1, j - 1, s1, s2);

//     // ELSE PERFORM OPERATIONS:
//     // TAKE MINIMUM MOVES BY PERFORMING DELETE, REPLACE, INSERT OPERATION:
//     return min(1 + makeString(i - 1, j, s1, s2), min(1 + makeString(i - 1, j - 1, s1, s2), 1 + makeString(i, j - 1, s1, s2)));
// }

// MEMOIZATION:
// TC -> O(n * m)
// SC -> O(n + m) + O(n * m) => AUXILIARY STAK SPACE + DP MATRIX
// int makeString(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
// {
//     // BASE CASE:
//     // IF THE SECOND STRING GETS EXHAUSTED, DELETE REMAINING CHARACTERES AND ADD MOVES:
//     if (j < 0)
//         return i + 1;
//     // IF THE FIRST STRING GETS EXHAUSTED, INSERT REMAINING CHARACTERS AND ADD MOVES:
//     if (i < 0)
//         return j + 1;

//     // IF THE RECURSION CALL FOR PARTICULAR <i, j> IS PRECOMPUTED, RETURN THAT STORED VALUE:
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // IF THE CHARACTERS ARE MATCHING, NO NEED TO ADD MOVES, AND REDUCE BOTH i & j:
//     if (s1[i] == s2[j])
//         return 0 + makeString(i - 1, j - 1, s1, s2, dp);

//     // ELSE PERFORM OPERATIONS:
//     // TAKE MINIMUM MOVES BY PERFORMING DELETE, REPLACE, INSERT OPERATION:
//     return min(1 + makeString(i - 1, j, s1, s2, dp), min(1 + makeString(i - 1, j - 1, s1, s2, dp), 1 + makeString(i, j - 1, s1, s2, dp)));
// }

// TABULATION:
// TC -> O(n * m)
// SC -> O(n * m) => TABULATION MATRIX
// int makeString(int n, int m, string &s1, string &s2)
// {
//     // CREATING A TABULATION MATRIX OF SIZE <n+1, m+1> :
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     // BASE CASE:
//     // IF THE SECOND STRING GETS EXHAUSTED, DELETE REMAINING CHARACTERES AND ADD MOVES:
//     for (int i = 0; i <= n; ++i)
//         dp[i][0] = i;
//     // IF THE FIRST STRING GETS EXHAUSTED, INSERT REMAINING CHARACTERS AND ADD MOVES:
//     for (int j = 0; j <= m; ++j)
//         dp[0][j] = j;

//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 1; j <= m; ++j)
//         {
//             if (s1[i - 1] == s2[j - 1])
//                 dp[i][j] = 0 + dp[i - 1][j - 1];

//             // ELSE PERFORM OPERATIONS:
//             // TAKE MINIMUM MOVES BY PERFORMING DELETE, REPLACE, INSERT OPERATION:
//             else
//                 dp[i][j] = min(1 + dp[i - 1][j], min(1 + dp[i - 1][j - 1], 1 + dp[i][j - 1]));
//         }
//     }

//     // RETURN THE LAST COMPUTED CELL:
//     return dp[n][m];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * m)
// SC -> O(n) + O(n) => TWO 1-D VECTORS FOR STORING CURRENT AND PREVIOUS ROWS:
int makeString(int n, int m, string &s1, string &s2)
{
    // CREATING TWO 1-D VECTORS FOR STORING CURRENT AND PREVIOUS ROWS:
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    // BASE CASE:
    // IF THE FIRST STRING GETS EXHAUSTED, INSERT REMAINING CHARACTERS AND ADD MOVES:
    for (int j = 0; j <= m; ++j)
        prev[j] = j;

    for (int i = 1; i <= n; ++i)
    {
        // IF THE SECOND STRING GETS EXHAUSTED, DELETE REMAINING CHARACTERES AND ADD MOVES:
        curr[0] = i;
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 0 + prev[j - 1];

            // ELSE PERFORM OPERATIONS:
            // TAKE MINIMUM MOVES BY PERFORMING DELETE, REPLACE, INSERT OPERATION:
            else
                curr[j] = min(1 + prev[j], min(1 + prev[j - 1], 1 + curr[j - 1]));
        }
        prev = curr;
    }

    // RETURN THE LAST COMPUTED CELL:
    return prev[m];
}
int main(void)
{
    string s = "whgtdwhgtdg";
    string t = "aswcfg";
    int n = s.size();
    int m = t.size();

    // RECURSION:
    // cout << makeString(n - 1, m - 1, s, t);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << makeString(n - 1, m - 1, s, t, dp);

    // TABULATION:
    // cout << makeString(n, m, s, t);

    // SPACE OPTIMIZATION:
    cout << makeString(n, m, s, t);
    return 0;
}