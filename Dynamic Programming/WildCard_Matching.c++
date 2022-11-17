// Given a text and a wildcard pattern of size N and M respectively, implement a wildcard pattern matching algorithm that finds if the
// wildcard pattern is matched with the text. The matching should cover the entire text not partial text.
// The wildcard pattern can include the characters ‘?’ and ‘*’
//  ‘?’ – matches any single character
//  ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC -> O(exp)
// SC -> O(n + m) => AUXILIARY STACK SPACE EQUALS TO SUM OF LENGTH OF BOTH STRINGS
// bool WildCard_Matching(int i, int j, string &pattern, string &text)
// {
//     // BASE CASE:
//     // IF BOTH THE STRING GETS EXHAUSTED, RETURN TRUE:
//     if (i < 0 && j < 0)
//         return true;
//     // IF THE PATTERN STRING GETS EXHAUSTED, RETURN FALSE:
//     if (i < 0 && j >= 0)
//         return false;
//     // IF THE TEXT STRING GETS EXHAUSTED, CHECK THAT REMAINING CHARACTERS IN PATTERN STRING ARE ALL '*':
//     if (j < 0 && i >= 0)
//     {
//         for (int k = 0; k <= i; ++k)
//             if (pattern[k] != '*')
//                 return false;
//         return true;
//     }

//     // IF THE CORRESPONDING CHARACTERS ARE MATCHING OR PATTERN'S CHARACTER IS '?' REDUCE BOTH STRINGS:
//     if (pattern[i] == text[j] || pattern[i] == '?')
//         return WildCard_Matching(i - 1, j - 1, pattern, text);
//     // IF THE PATTER'S CHARACTER IS '*', REDUCE THE TEXT STRING(FOR VARIABLE STRING MATCHING) OR REDUCE THE PATTERN'S STRING
//     // (FOR ZERO STRING MATCHING):
//     if (pattern[i] == '*')
//         return WildCard_Matching(i - 1, j, pattern, text) | WildCard_Matching(i, j - 1, pattern, text);

//     // ELSE RETURN FALSE:
//     return false;
// }

// MEMOIZATION:
// TC -> O(n * m)
// SC -> O(n + m) + O(n * m) => AUXILIARY STACK SPACE + DP MATRIX
// bool WildCard_Matching(int i, int j, string &pattern, string &text, vector<vector<int>> &dp)
// {
//     // BASE CASE:
//     // IF BOTH THE STRING GETS EXHAUSTED, RETURN TRUE:
//     if (i < 0 && j < 0)
//         return true;
//     // IF THE PATTERN STRING GETS EXHAUSTED, RETURN FALSE:
//     if (i < 0 && j >= 0)
//         return false;
//     // IF THE TEXT STRING GETS EXHAUSTED, CHECK THAT REMAINING CHARACTERS IN PATTERN STRING ARE ALL '*':
//     if (j < 0 && i >= 0)
//     {
//         for (int k = 0; k <= i; ++k)
//             if (pattern[k] != '*')
//                 return false;
//         return true;
//     }

//     // IF THE RECURSION CALL FOR PARTICULAR <i,j> IS PRE-COMPUTED, RETURN STORED VALUE:
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // IF THE CORRESPONDING CHARACTERS ARE MATCHING OR PATTERN'S CHARACTER IS '?', REDUCE BOTH STRINGS:
//     if (pattern[i] == text[j] || pattern[i] == '?')
//         return dp[i][j] = WildCard_Matching(i - 1, j - 1, pattern, text, dp);
//     // IF THE PATTER'S CHARACTER IS '*', REDUCE THE TEXT STRING(FOR VARIABLE STRING MATCHING) OR REDUCE THE PATTERN'S STRING
//     // (FOR ZERO STRING MATCHING):
//     if (pattern[i] == '*')
//         return dp[i][j] = WildCard_Matching(i - 1, j, pattern, text, dp) | WildCard_Matching(i, j - 1, pattern, text, dp);

//     // ELSE RETURN FALSE:
//     return dp[i][j] = false;
// }

// TABULATION:
// TC -> O(n * m)
// SC -> O(n * m)
// bool WildCard_Matching(int n, int m, string &pattern, string &text)
// {
//     // CREATING A 2-D TABULATION MATRIX:
//     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));

//     // BASE CASE :
//     dp[0][0] = true;

//     // STARTING 'i' & 'j 'WITH '1' AS '0' IS ALREADY INTIALIZED !!!
//     for (int j = 1; j <= m; ++j)
//         dp[0][j] = false;

//     for (int i = 1; i <= n; ++i)
//     {
//         bool flag = true;
//         for (int k = 1; k <= i; ++k)
//             if (pattern[k - 1] != '*')
//             {
//                 flag = false;
//                 break;
//             }
//         dp[i][0] = flag;
//     }

//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 1; j <= m; ++j)
//         {
//             // IF THE CORRESPONDING CHARACTERS ARE MATCHING OR PATTERN'S CHARACTER IS '?' REDUCE BOTH STRINGS:
//             if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
//                 dp[i][j] = dp[i - 1][j - 1];
//             // IF THE PATTER'S CHARACTER IS '*', REDUCE THE TEXT STRING(FOR VARIABLE STRING MATCHING) OR REDUCE THE PATTERN'S STRING
//             // (FOR ZERO STRING MATCHING):
//             else if (pattern[i - 1] == '*')
//                 dp[i][j] = dp[i - 1][j] | dp[i][j - 1];

//             // ELSE RETURN FALSE:
//             else
//                 dp[i][j] = false;
//         }
//     }

//     // RETURN THE LAST COMPUTED CELL:
//     return dp[n][m];
// }

// SPACE OPTIMAZATION:
bool WildCard_Matching(int n, int m, string &pattern, string &text)
{
    // CREATING 2, 1-D VECTORS FOR STORING PREVIOUS AND CURRENT ROWS:
    vector<bool> prev(m + 1, false), curr(m + 1, false);

    // BASE CASE :
    prev[0] = true;

    // NOT REQUIRED:
    // STARTING 'i' & 'j 'WITH '1' AS '0' IS ALREADY INTIALIZED !!!
    // for (int j = 1; j <= m; ++j)
    //     prev[j] = false;

    // AS BEING DONE FOR EVERY ROW, SO NOT REQUIRED TO BE DONE HERE !!!
    // for (int i = 1; i <= n; ++i)
    // {
    //     bool flag = true;
    //     for (int k = 1; k <= i; ++k)
    //         if (pattern[k - 1] != '*')
    //         {
    //             flag = false;
    //             break;
    //         }
    //     dp[i][0] = flag;
    // }

    for (int i = 1; i <= n; ++i)
    {
        // BASE CASE:
        bool flag = true;
        for (int k = 1; k <= i; ++k)
            if (pattern[k - 1] != '*')
            {
                flag = false;
                break;
            }
        curr[0] = flag;

        for (int j = 1; j <= m; ++j)
        {
            // IF THE CORRESPONDING CHARACTERS ARE MATCHING OR PATTERN'S CHARACTER IS '?' REDUCE BOTH STRINGS:
            if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
                curr[j] = prev[j - 1];
            // IF THE PATTER'S CHARACTER IS '*', REDUCE THE TEXT STRING(FOR VARIABLE STRING MATCHING) OR REDUCE THE PATTERN'S STRING
            // (FOR ZERO STRING MATCHING):
            else if (pattern[i - 1] == '*')
                curr[j] = prev[j] | curr[j - 1];

            // ELSE RETURN FALSE:
            else
                curr[j] = false;
        }

        prev = curr;
    }

    // RETURN THE LAST COMPUTED CELL:
    return prev[m];
}
int main(void)
{
    string pattern = "ab*cd";
    string text = "abdefcd";
    int n = pattern.size();
    int m = text.size();

    // RECURSION:
    // cout << WildCard_Matching(n - 1, m - 1, pattern, text);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // cout << WildCard_Matching(n - 1, m - 1, pattern, text, dp);

    // TABULATION:
    // cout << WildCard_Matching(n, m, pattern, text);

    // SPACE OPTIMIZATION:
    cout << WildCard_Matching(n, m, pattern, text);
    return 0;
}