// Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the
// subsequence are adjacent elements in the array.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// int maxsum(int ind, vector<int> &arr)
// {
//     // BASE CASE 1:
//     // IF NOT PICKED THE 1st INDEX ELEMENT THEN HAVE TO SELECT THE 0th ELEMENT !
//     if (ind == 0)
//         return arr[0];
//     // BASE CASE 2:
//     // IF PICKED THE 1st ELEMENT THEN NOT PICK THE 0th ELEMENT AND MOVED TO -1 POSITION (NOT VALID) !
//     if (ind < 0)
//         return 0;

//     int pick = INT16_MIN;
//     if (ind > 1)
//         pick = maxsum(ind - 2, arr) + arr[ind];
//     int notPick = maxsum(ind - 1, arr) + 0;

//     // RETURNING THE MAX OF BOTH:
//     return max(pick, notPick);
// }
 
// MEMOIZATION:
// int maxsum(int ind, vector<int> &arr, vector<int> &dp)
// {

//     if(ind == 0) return arr[ind];
//     if(ind < 0)  return 0;
//     if(dp[ind] != -1) return dp[ind];

//     int pick= arr[ind]+ maxsum(ind-2, arr,dp);
//     int nonPick = 0 + maxsum(ind-1, arr, dp);

//     return dp[ind]=max(pick, nonPick);
// }

// TABULATION:
// int maxsum(int ind, vector<int> &arr)
// {
//     vector<int> dp(ind, -1);
//     dp[0] = arr[0];
//     for (int i = 1; i < ind; ++i)
//     {
//         int pick = arr[i];
//         if (i > 1)
//             pick += dp[i - 2];
//         int nonPick = 0 + dp[i - 1];

//         dp[i] = max(pick, nonPick);
//     }
//     return dp[ind - 1];
// }

// SPACE OPTIMIZATION:
int maxsum(int n, vector<int> &arr)
{
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}
int main(void)
{
    vector<int> arr = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    int n = arr.size() - 1;
    // maxsum(index, given_array):
    // RECURSION:
    // cout << "Maximum Sum: " << maxsum(n, arr);

    // NOT WORKING !!!
    // MEMOIZATION:
    // vector<int> dp(n, -1);
    // cout << "Maximum Sum: " << maxsum(n, arr, dp);

    // TABULATION:
    // cout << "Maximum Sum: " << maxsum(n, arr);

    // SPACE OPTIMIZATION:
    cout << "Maximum Sum: " << maxsum(n, arr);
    return 0;
}