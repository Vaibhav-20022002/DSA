// You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting
// the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC -> O(2^n)
// SC -> O(n)
// int countSubsets(int ind, int tar, vector<int> &arr)
// {
//     // BASE CASE 1:
//     // IF tar BECOMES ZERO RETURN 1:
//     if (tar == 0)
//         return 1;

//     // BASE CASE 2:
//     // IF ind BECOMES ZERO AND THE REMAINING tar VALUE IS EQUAL TO ind RETURN 1, OTHERWISE 0:
//     if (ind == 0)
//         return arr[0] == tar;

//     // NOT PICKING UP:
//     int notPick = countSubsets(ind - 1, tar, arr);
//     int pick = 0;
//     if (arr[ind] <= tar)
//         pick = countSubsets(ind - 1, tar - arr[ind], arr);

//     // RETURN THE NUMBER OF RECURSION CALLS:
//     return pick + notPick;
// }

// MEMOIZATION:
// TC -> O(n*tar)
// SC -> O(n) + O(n*tar) => AUXILARY STACK SPACE + DP MATRIX
// int countSubsets(int ind, int tar, vector<int> &arr, vector<vector<int>> dp)
// {
//     // BASE CASE 1:
//     // IF tar BECOMES ZERO RETURN 1:
//     if (tar == 0)
//         return 1;

//     // BASE CASE 2:
//     // IF ind BECOMES ZERO AND THE REMAINING tar VALUE IS EQUAL TO ind RETURN 1, OTHERWISE 0:
//     if (ind == 0)
//         return arr[0] == tar;

//     // IF FOR THE PARTICULAR <ind, tar> IS PRE-COMPUTED, RETURN THAT :
//     if (dp[ind][tar] != -1)
//         return dp[ind][tar];

//     // NOT PICKING UP:
//     int notPick = countSubsets(ind - 1, tar, arr, dp);
//     int pick = 0;
//     if (arr[ind] <= tar)
//         pick = countSubsets(ind - 1, tar - arr[ind], arr, dp);

//     // RETURN THE NUMBER OF RECURSION CALLS:
//     return dp[ind][tar] = pick + notPick;
// }

// TABULATION:
// TC -> O(n*tar)
// SC -> O(n*tar) => DP MATRIX
// int countSubsets(int n, int tar, vector<int> &arr)
// {
//     // CREATING A TABULATION MATRIX OF ORDER <n, tar> :
//     vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

//     // BASE CASE 1:
//     // FOR EVERY VALUE OF ind, IF tar IS ZERO, MARK IT 1:
//     for (int ind = 0; ind < n; ++ind)
//         dp[ind][0] = 1;

//     // BASE CASE 2:
//     // IF THE VALUE OF tar IS SMALLER THAN OR EQUALS TO THE FIRST ELEMENT OF THE ARRAY, MARK IT 1:
//     if (arr[0] <= tar)
//         dp[0][arr[0]] = 1;

//     for (int ind = 1; ind < n; ++ind)
//     {
//         for (int sum = 0; sum <= tar; ++sum)
//         {
//             int notPick = dp[ind - 1][sum];
//             int pick = 0;
//             if (arr[ind] <= sum)
//                 pick = dp[ind - 1][sum - arr[ind]];
//             dp[ind][sum] = pick + notPick;
//         }
//     }

//     return dp[n - 1][tar];
// }

// SPACE OPTIMIZATION:
int countSubsets(int n, int tar, vector<int> &arr)
{
    // CREATING VECTORS OF ORDER <tar> TO STORE PREVIOUS & CURRENT ROW :
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

    // BASE CASE 1:
    // IF tar IS ZERO, MARK IT 1:
    prev[0] = curr[0] = 1;

    // BASE CASE 2:
    // IF THE VALUE OF tar IS SMALLER THAN OR EQUALS TO THE FIRST ELEMENT OF THE ARRAY, MARK IT 1:
    if (arr[0] <= tar)
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ++ind)
    {
        for (int sum = 0; sum <= tar; ++sum)
        {
            int notPick = prev[sum];
            int pick = 0;
            if (arr[ind] <= sum)
                pick = prev[sum - arr[ind]];
            curr[sum] = pick + notPick;
        }

        prev = curr;
    }

    return prev[tar];
}
int main(void)
{
    int tar = 3;
    vector<int> arr = {1, 2, 2, 3};
    int n = arr.size();

    // RECURSION:
    // cout << countSubsets(n - 1, tar, arr);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    // cout << countSubsets(n - 1, tar, arr, dp);

    // TABULATION:
    // cout << countSubsets(n, tar, arr);

    // SPACE OPTIMIZATION:
    cout << countSubsets(n, tar, arr);
    return 0;
}