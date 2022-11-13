// Given two strings, ‘A’ and ‘B’. Return the shortest supersequence string ‘S’, containing both ‘A’ and ‘B’ as its subsequences. If there
// are multiple answers, return any of them.
// Note: A string 's' is a subsequence of string 't' if deleting some number of characters from 't' (possibly 0) results in the string 's'.

#include <iostream>
#include <vector>
#include <algorithm> //FOR reverse()
using namespace std;
int len(int n, int m, string &s, string &t)
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
int lengthof_Supersequence(int n, int m, string &s, string &t)
{
    // LENGTH OF SUPERSEQUENCE = n - len(LCS) + m - len(LCS) + len(LCS) = n + m + len(LCS)
    return n + m - len(n, m, s, t);
}

void printSS(int n, int m, string &s, string &t)
{
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

    // TAKE EMPTY STRING:
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        // IF BOTH ARE EQUAL:
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s[i - 1];
            --i;
        }
        else
        {
            ans += t[j - 1];
            --j;
        }
    }

    // ADD WHATS LEFT:
    while (i > 0)
    {
        ans += s[i - 1];
        --i;
    }
    while (j > 0)
    {
        ans += t[j - 1];
        --j;
    }

    // REVERSING THE STRING AS IT IS FILLED IN REVERSE MANNER:
    reverse(ans.begin(), ans.end());
    // PRINTING THE STRING:
    cout << ans;
}
int main(void)
{
    string a = "brute";
    string b = "groot";
    int n = a.size();
    int m = b.size();

    // PRINTING THE LENGTH OF THE SUPERSEQUENCE:
    cout << lengthof_Supersequence(n, m, a, b) << "\n";
    // PRINTING THE SUPERSEQUENCE:
    printSS(n, m, a, b);
    return 0;
}