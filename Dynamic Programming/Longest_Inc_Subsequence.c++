// LIS CAN BE EASILY SOLVED USING BINARY SEARCH WITH BETTER COMPLEXITIES !!!


// For a given array with N elements, you need to find the length of the longest subsequence from the array such that all the elements
// of the subsequence are sorted in strictly increasing order.
// Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// RECURSION:
// TC -> O(2 ^ n)
// SC -> O(n) => AUXILIARY STACK SPACE EQUALS TO THE LENGTH OF ARRAY:
// int longestIncreasingSubsequence(int ind, int prev_ind, vector<int> &arr, int n)
// {
//     // BASE CASE :
//     // IF THE ARRAY GOES OUT OF BOUND, RETURN ZERO:
//     if (ind == n)
//         return 0;

//     // IF PICKING UP THE ELEMENT:
//     int pick = -1;
//     // PICK IS POSSIBLE WHENEVER prev_ind IS -1 (ALWAYS PICKING UP THE FIRST ELEMENT) OR
//     // ind's ELEMENT IS GREATER THAN prev_ind's ELEMENT:
//     if (prev_ind == -1 || arr[ind] > arr[prev_ind])
//         pick = 1 + longestIncreasingSubsequence(ind + 1, ind, arr, n);

//     // RETURN THE MAXIMUM AMONG pick AND notPick:
//     return max(pick, 0 + longestIncreasingSubsequence(ind + 1, prev_ind, arr, n));
// }

// MEMOIZATION:
// TC -> O(n * n)
// SC -> O(n * n) + O(n) => DP MATRIX + AUXILIARY STACK SPACE EQUALS TO THE LENGTH OF ARRAY
// int longestIncreasingSubsequence(int ind, int prev_ind, vector<int> &arr, int n, vector<vector<int>> &dp)
// {
//     // SHIFTING OF ORIGIN:
//     // BASE CASE :
//     // IF THE ARRAY GOES OUT OF BOUND, RETURN ZERO:
//     if (ind == n)
//         return 0;

//     // IF THE RECURSION CALL FOR PARTICULAR <ind, prev_ind> IS PRECOMPUTED, RETURN THAT STORED VALUE:
//     if (dp[ind][prev_ind + 1] != -1)
//         return dp[ind][prev_ind + 1];

//     // IF PICKING UP THE ELEMENT:
//     int pick = -1;
//     // PICK IS POSSIBLE WHENEVER prev_ind IS -1 (ALWAYS PICKING UP THE FIRST ELEMENT) OR
//     // ind's ELEMENT IS GREATER THAN prev_ind's ELEMENT:
//     if (prev_ind == -1 || arr[ind] > arr[prev_ind])
//         pick = 1 + longestIncreasingSubsequence(ind + 1, ind, arr, n, dp);

//     // RETURN THE MAXIMUM AMONG pick AND notPick:
//     return dp[ind][prev_ind + 1] = max(pick, 0 + longestIncreasingSubsequence(ind + 1, prev_ind, arr, n, dp));
// }

// TABULATION:
// TC -> O(n * n)
// SC -> O(n * n) => TABULATION MATRIX
// int longestIncreasingSubsequence(vector<int> &arr, int n)
// {
//     // CREATING A TABULATION MATRIX:
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//     // NOT REQUIRED AS ALL CELLS ARE ALREADY ZERO !!!
//     // BASE CASE:
//     // prev_ind IS ONE LESSER THAN ind, THEREFORE, dp[ind = n][prev_ind = ind-1 = n-1] = 0 !!!
//     // dp[n][n - 1] = 0;

//     for (int ind = n - 1; ind >= 0; --ind)
//     {
//         // prev_ind IS ONE LESSER THAN ind
//         for (int prev_ind = ind - 1; prev_ind >= -1; --prev_ind)
//         {
//             // IF PICKING UP THE ELEMENT:
//             int pick = -1;
//             // PICK IS POSSIBLE WHENEVER prev_ind IS -1 (ALWAYS PICKING UP THE FIRST ELEMENT) OR
//             // ind's ELEMENT IS GREATER THAN prev_ind's ELEMENT:
//             if (prev_ind == -1 || arr[ind] > arr[prev_ind])
//                 pick = 1 + dp[ind + 1][ind + 1];

//             // RETURN THE MAXIMUM AMONG pick AND notPick:
//             dp[ind][prev_ind + 1] = max(pick, 0 + dp[ind + 1][prev_ind + 1]);
//         }
//     }

//     // RETURN THE LAST COMPUTED CELL, dp[0][0] => dp[ind = 0][prev_ind = -1 + 1 = 0]:
//     return dp[0][0];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * n)
// SC -> O(n) + O(n) => 2 1-D VECTOR FOR STORING PREVOIUS AND CURRENT ROWS
// int longestIncreasingSubsequence(vector<int> &arr, int n)
// {
//     // CREATING 1-D VECTOR FOR STORING PREVIOUS ROW:
//     vector<int> prev(n + 1, 0);

//     // NOT REQUIRED AS ALL CELLS ARE ALREADY ZERO !!!
//     // BASE CASE:
//     // prev_ind IS ONE LESSER THAN ind, THEREFORE, dp[ind = n][prev_ind = ind-1 = n-1] = 0 !!!
//     // prev[n - 1] = 0;

//     for (int ind = n - 1; ind >= 0; --ind)
//     {
//         // CREATING 1-D VECTOR FOR STORING CURRENT ROW:
//         vector<int> curr(n + 1, 0);

//         // prev_ind IS ONE LESSER THAN ind
//         for (int prev_ind = ind - 1; prev_ind >= -1; --prev_ind)
//         {
//             // IF PICKING UP THE ELEMENT:
//             int pick = -1;
//             // PICK IS POSSIBLE WHENEVER prev_ind IS -1 (ALWAYS PICKING UP THE FIRST ELEMENT) OR
//             // ind's ELEMENT IS GREATER THAN prev_ind's ELEMENT:
//             if (prev_ind == -1 || arr[ind] > arr[prev_ind])
//                 pick = 1 + prev[ind + 1];

//             // RETURN THE MAXIMUM AMONG pick AND notPick:
//             curr[prev_ind + 1] = max(pick, 0 + prev[prev_ind + 1]);
//         }
//         prev = curr;
//     }

//     // RETURN THE LAST COMPUTED CELL, dp[0][0] => dp[ind = 0][prev_ind = -1 + 1 = 0]:
//     return prev[0];
// }

// SPACE OPTIMIZATION 2:
// TC -> O(n * n)
// SC -> O(n) => DP VECTOR
// int longestIncreasingSubsequence(vector<int> &arr, int n)
// {
//     // CREATING A DP VECTOR FOR STORING LIS, WHERE DP[i] SIGNIFIES MAXIMUM LENGTH OF LIS TILL 'i', INITIALIZED WITH '1' AS
//     // MAXIMUM LENGTH OF LIS FOR EVERY ELEMENT IS THE ELEMENT ITSELF IE.; '1':
//     vector<int> dp(n, 1);

//     // MAKING A VARIABLE FOR STORING MAXIMUM AMONG ALL dp[i]'s :
//     int maxx = 1;

//     // TRAVERSING THE ARRAY:
//     for (int ind = 0; ind < n; ++ind)
//     {
        // // TRAVERSING THE ARRAY BACK TILL ind - 1 FOR COMPUTING THE LIS:
        // for (int prev_ind = 0; prev_ind < ind; ++prev_ind)
        //     // IF ANY PREVIOUS ELEMENT IS LESSER THAN ind's ELEMENT, ADD ONTO THE DP:
        //     if (arr[prev_ind] < arr[ind] && 1 + dp[prev_ind] > dp[ind])
        //         dp[ind] = 1 + dp[prev_ind];
        // // AFTER EVERY COMPUTION FOR dp[i], UPDATE THE maxx :
        // maxx = max(maxx, dp[ind]);
        // }

//     // RETURN THE MAXIMUM LENGTH OF LIS:
//     return maxx;
// }

// SPACE OPTIMIZATION 3:
int longestIncreasingSubsequence(vector<int> &arr, int n)
{
    // CREATING A TEMPORARY ARRAY FOR STORING THE ELEMENTS:
    vector<int> temp;

    // INSERTING THE FIRST ELEMENT AT FIRST :
    temp.emplace_back(arr[0]);

    // TRAVERSING THE ARRAY:
    for (int i = 1; i < n; ++i)
    {
        // IF THE ELEMENT IS GREATER THAN LAST INSERTED ELEMENT SIMPLY INSERT IT IN THE VECTOR:
        if (arr[i] > temp.back())
            temp.emplace_back(arr[i]);

        // IF NOT THE ABOVE CASE, THEN FIND THE ELEMENT IN THE temp VECTOR OR JUST GREATER THAN IT AND REPLACE arr[i] WITH
        // FINDED INDEX:
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    // RETURN THE SIZE OF TEMPORARY ARRAY:
    return temp.size();
}
int main(void)
{
    vector<int> arr = {5, 4, 11, 1, 16, 8};
    int n = arr.size();

    // RECURSION:
    // cout << longestIncreasingSubsequence(0, -1, arr, n);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // cout << longestIncreasingSubsequence(0, -1, arr, n, dp);

    // TABULATION:
    // cout << longestIncreasingSubsequence(arr, n);

    // SPACE OPTIMIZATION:
    // cout << longestIncreasingSubsequence(arr, n);

    // SPACE OPIMIAZTION 2:
    // cout << longestIncreasingSubsequence(arr, n);

    // SPACE OPTIMIZATION 3:
    cout << longestIncreasingSubsequence(arr, n);
    return 0;
}