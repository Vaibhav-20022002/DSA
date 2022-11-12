// You are given 2 non-empty strings “str” and “ptr” consisting of lowercase English alphabets only. Your task is to convert string “str”
// into string “ptr”. In one operation you can do either of the following on “str”:
// Remove a character from any position in “str”.
// Add a character to any position in “str”.
// You have to find the minimum number of operations required to convert string “str” into “ptr”.

#include <iostream>
#include <vector>
using namespace std;
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
int main(void)
{
    string str = "aa";
    string ptr = "aaa";
    int n = str.size();
    int m = ptr.size();

    // NUMBER OF DELETIONS = n - len(LCS)
    // NUMBER OF INSERTIONS = m + len(LCS)
    // TOTAL NUMBER OF OPERTIONS = n + m - 2len(LCS)

    cout << n + m - 2 * lengthof_LCS(n, m, str, ptr);
    return 0;
}