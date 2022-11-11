// You have been given a string ‘A’ consisting of lower case English letters. Your task is to find the length of the longest palindromic
// subsequence in ‘A’.
// A subsequence is a sequence generated from a string after deleting some or no characters of the string without changing the order of the
// remaining string characters. (i.e. “ace” is a subsequence of “abcde” while “aec” is not).
// A string is said to be palindrome if the reverse of the string is the same as the actual string. For example, “abba” is a palindrome,
// but “abbc” is not a palindrome.

// THIS PROBLEM CAN BE SOLVED USING LONGEST COMMON SUBSEQUENCES SOLUTION BY DOING FEW MODIFICATION. SINCE, A PALINDROMIC STRING IS THE
// ONE WHICH IS SAME AS ITS REVERSE. SO, BY FINDING A LCS OF THAT STRING WITH ITS REVERSE CAN DO THE JOB !!!

#include <bits/stdc++.h>
using namespace std;

// SPACE OPTIMIZATION:
// TC -> O(n * n)
// SC -> O(n) => 1-D VECTOR FOR STORING PREVIOUS ROW
int lengthof_LCS(int n, int m, string &s, string &t)
{
    // SHIFTING THE ORIGIN:
    // CREATING A 1-D VECTOR FOR STORING PREVIOUS ROW:
    vector<int> prev(m + 1, 0);

    // BASE CASE :
    // ALL <0, j> and <i, 0> ARE OF ZERO LENGTH:
    // AS ALL CELLS AR EFILLED WITH ZERO, AND EXECUTION IS DONE FROM <1, 1>, SO NEED TO RUN BASE CASE LOOPS !!!
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
        if (s[i - 1] == t[j - 1])
        {
            // IF THE ELEMENTS ARE EQUAL, MOVE DIAGONALLY UPWARD IN THE TABULATION MATRIX:
            str[index--] = s[i - 1];
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
int main(void)
{
    string s = "bbabcbcab";
    string t = s;
    int n = s.size();
    reverse(s.begin(), s.end());
    cout << lengthof_LCS(n, n, s, t) << "\n";

    // PRINTING THE PALINDROMIC STRING:
    printLCS(n, n, s, t);
    return 0;
}