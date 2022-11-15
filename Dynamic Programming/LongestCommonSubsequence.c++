// Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.
// For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are
// present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC -> O(2 * (n + m))
// SC -> O(n + m) => AUXILIARY STACK SPACE OF SUM OF THE SIZES OF BOTH STIRNGS
// int lengthof_LCS(int i, int j, string &s, string &t)
// {
//     // BASE CASE :
//     // IF ANY OF THE STRING GETS EMPTY!!!
//     if (i < 0 || j < 0)
//         return 0;

//     // CHECKING IF THE ith AND jth ELEMENTS ARE EQUAl, IF SO, ADD 1 :
//     if (s[i] == t[j])
//         return 1 + lengthof_LCS(i - 1, j - 1, s, t);

//     // IF THE ith AND jth ELEMENTS ARE NOT EQUAL, THEN REDUCE i or j AND TAKE MAXIMUM OF THEM :
//     return 0 + max(lengthof_LCS(i - 1, j, s, t), lengthof_LCS(i, j - 1, s, t));
// }

// MEMOIZATION:
// TC -> O(n * m)
// SC -> O(n + m) + O(n * m) => AUXILIARY STACK SPACE + DP MATRIX
// int lengthof_LCS(int i, int j, string &s, string &t, vector<vector<int>> &dp)
// {
//     // BASE CASE :
//     // IF ANY OF THE STRING GETS EMPTY!!!
//     if (i < 0 || j < 0)
//         return 0;

//     // IF THE RECURSION CALL FOR PARTICULAR <i, j> IS ALREADY COMPUTED, RETURN THE STORED VALUE:
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // CHECKING IF THE ith AND jth ELEMENTS ARE EQUAl, IF SO, ADD 1 :
//     if (s[i] == t[j])
//         return 1 + lengthof_LCS(i - 1, j - 1, s, t, dp);

//     // IF THE ith AND jth ELEMENTS ARE NOT EQUAL, THEN REDUCE i or j AND TAKE MAXIMUM OF THEM :
//     return max(lengthof_LCS(i - 1, j, s, t, dp), lengthof_LCS(i, j - 1, s, t, dp));
// }

// TABULATION:
//  TC -> O(n * m)
// SC -> O(n * m) => TABULATION MATRIX
// int lengthof_LCS(int n, int m, string &s, string &t)
// {
//     // SHIFTING THE ORIGIN:
//     // CREATING A TABULATION MATRIX OF SIZE <n + 1, m + 1> (DUE TO SHIFTING ORIGIN ONE AHEAD):
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     // BASE CASE :
//     // ALL <0, j> and <i, 0> ARE OF ZERO LENGTH:
//     // AS ALL CELLS ARE FILLED WITH ZERO, AND EXECUTION IS DONE FROM <1, 1>, SO NEED TO RUN BASE CASE LOOPS !!!
//     // for (int i = 0; i <= n; ++i)
//     //     dp[i][0] = 0;
//     // for (int j = 0; j <= m; ++j)
//     //     dp[0][j] = 0;

//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 1; j <= m; ++j)
//         {
//             // CHECKING IF THE ith AND jth ELEMENTS ARE EQUAl, IF SO, ADD 1 :
//             if (s[i - 1] == t[j - 1])
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             else
//                 // IF THE ith AND jth ELEMENTS ARE NOT EQUAL, THEN REDUCE i or j AND TAKE MAXIMUM OF THEM :
//                 dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }

//     // RETURN THE LAST COMPUTED CELL:
//     return dp[n][m];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * m)
// SC -> O(n) => 1-D VECTOR FOR STORING PREVIOUS ROW
int lengthof_LCS(int n, int m, string &s, string &t)
{
    // SHIFTING THE ORIGIN:
    // CREATING A 1-D VECTOR FOR STORING PREVIOUS ROW:
    vector<int> prev(m + 1, 0);

    // BASE CASE :
    // ALL <0, j> and <i, 0> ARE OF ZERO LENGTH:
    // AS ALL CELLS ARE FILLED WITH ZERO, AND EXECUTION IS DONE FROM <1, 1>, SO NEED TO RUN BASE CASE LOOPS !!!
    // for (int j = 0; j <= m; ++j)
    //     prev[j] = 0;

    for (int i = 1; i <= n; ++i)
    {
        // CREATING A 1-D VECTOR FOR STORING CURRENT ROW:
        vector<int> curr(m + 1, 0);
        for (int j = 1; j <= m; ++j)
        {

            // CHECKING IF THE ith AND jth ELEMENTS ARE EQUAl, IF SO, ADD 1 :
            if (s[i - 1] == t[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                // IF THE ith AND jth ELEMENTS ARE NOT EQUAL, THEN REDUCE i or j AND TAKE MAXIMUM OF THEM :
                curr[j] = 0 + max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }

    // RETURN THE LAST COMPUTED CELL:
    return prev[m];
}

// PRINTING THE LCS:
void printLCS(int n, int m, string &s, string &t)
{
    // AS WE HAVE TO PRINT THE STRING CONTAINING THE LCS, THE RECURSION CALL IS NOT A OPTIMIZED WAY, THUS WE USE TABULATION MATRIX FOR
    // STORING IT !!!

    // SHIFTING THE ORIGIN:
    // CREATING A TABULATION MATRIX OF SIZE <n + 1, m + 1> (DUE TO SHIFTING ORIGIN ONE AHEAD):
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // BASE CASE :
    // ALL <0, j> and <i, 0> ARE OF ZERO LENGTH:
    // AS ALL CELLS AR EFILLED WITH ZERO, AND EXECUTION IS DONE FROM <1, 1>, SO NEED TO RUN BASE CASE LOOPS !!!
    // for (int i = 0; i <= n; ++i)
    //     dp[i][0] = 0;
    // for (int j = 0; j <= m; ++j)
    //     dp[0][j] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            // CHECKING IF THE ith AND jth ELEMENTS ARE EQUAl, IF SO, ADD 1 :
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                // IF THE ith AND jth ELEMENTS ARE NOT EQUAL, THEN REDUCE i or j AND TAKE MAXIMUM OF THEM :
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // THE LENGTH OF LCS IS STORED AT THE INDEX dp[n][m] !!!
    int len = dp[n][m];
    string str = "";

    // AS WE ARE BACKTRACKING THE TABULATION MATRIX, SO IF WE DIRECTLY STORE THE STRING IT GETS STORED IN REVERSE ORDER. TO AVOID IT,
    // FILL THE STRING WITH DUMMY CHARACTERS AND TAKE ACCOUNT OF INDEX AND REDUCE IT TO FILL THE STRING STRING IN REVERSE MANNER !!!
    for (int i = 0; i < len; ++i)
        str += " ";

    int index = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i-1] == t[j-1])
        {
            // IF THE ELEMENTS ARE EQUAL, MOVE DIAGONALLY UPWARD IN THE TABULATION MATRIX:
            str[index--] = s[i-1];
            --i;
            --j;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
            --j;
        else
            --i;
    }

    // PRINT THE LCS STRING:
    cout << str;
}
main(void)
{
    string s = "abcdb";
    string t = "bcacdhb";
    int n = s.size();
    int m = t.size();

    // RECURSION:
    // cout << lengthof_LCS(n - 1, m - 1, s, t) << "\n";

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << lengthof_LCS(n - 1, m - 1, s, t, dp) << "\n";

    // TABULATION:
    // cout << lengthof_LCS(n, m, s, t) << "\n";

    // SPACE OPTIMIZATION:
    cout << lengthof_LCS(n, m, s, t) << "\n";

    // PRINTING THE LCS:
    printLCS(n, m, s, t);
    return 0;
}
