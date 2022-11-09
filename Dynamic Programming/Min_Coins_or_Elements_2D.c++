// You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the minimum number of
// elements you have to take to reach the target sum ‘X’.
// Note:
// You have an infinite number of elements of each type.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC >> (FAR GREATER THAN) O(2 * n) => BECAUSE IN PICKING UP CASE, INDEX IS NOT REDUCING
// SC >> (FAR GREATER THAN) O(n) => BECAUSE IN PICKING UP CASE, INDEX IS NOT REDUCING
// int minElements(int ind, int target, vector<int> &nums)
// {
//     // BASE CASE :
//     // IF REACHING THE LAST (FIRST HERE) :
//     if (ind == 0)
//     {
//         // IF target CAN BE ACHIEVED BY TAKING FINITE NUMBER OF ELEMENTS, THEN RETURN THE REQUIRED ELEMENTS:
//         if (target % nums[0] == 0)
//             return target / nums[0];
//         // ELSE RETURN MAXIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
//         return 1e7;
//     }

//     // NOT PICKING UP THE ELEMENTS:
//     int notPick = 0 + minElements(ind - 1, target, nums);
//     // AS WE REQUIRE THE MINIMUM, MAKE pick MAXIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
//     int pick = 1e7;
//     // PICKING UP THE ELEMENT, ONLY IF ITS VALUE IS LESS THAN OR EQUAL TO THE target:
//     if (nums[ind] <= target)
//         pick = 1 + minElements(ind, target - nums[ind], nums);

//     // RETURN THE MINIMUM OF pick AND notPick:
//     return min(pick, notPick);
// }

// MEMOIZATION:
// TC -> O(n * x)
// SC -> O(n * x) + >>O(x) => DP MATRIX + EXPONENTIAL SPACE COMPLEXITY
// int minElements(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
// {
//     // BASE CASE :
//     // IF REACHING THE LAST (FIRST HERE) :
//     if (ind == 0)
//     {
//         // IF target CAN BE ACHIEVED BY TAKING FINITE NUMBER OF ELEMENTS, THEN RETURN THE REQUIRED ELEMENTS:
//         if (target % nums[0] == 0)
//             return target / nums[0];
//         // ELSE RETURN MAXIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
//         return 1e7;
//     }

//     // IF THE RECURSION CALL FOR PARTICULAR <ind, target>, RETURN THE STORED VALUE:
//     if (dp[ind][target] != -1)
//         return dp[ind][target];

//     // NOT PICKING UP THE ELEMENTS:
//     int notPick = 0 + minElements(ind - 1, target, nums, dp);
//     // AS WE REQUIRE THE MINIMUM, MAKE pick MAXIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
//     int pick = 1e7;
//     // PICKING UP THE ELEMENT, ONLY IF ITS VALUE IS LESS THAN OR EQUAL TO THE target:
//     if (nums[ind] <= target)
//         pick = 1 + minElements(ind, target - nums[ind], nums, dp);

//     // RETURN THE MINIMUM OF pick AND notPick:
//     return dp[ind][target] = min(pick, notPick);
// }

// TABULATION:
// TC -> O(n * x)
// SC -> O(n * x) => TABULATION MATRIX 
// int minElements(int n, int x, vector<int> &nums)
// {
//     // CREATING A DP MATRIX FOR STORING RECURSION CALLS FOR <ind, target> :: <n,x> :
//     vector<vector<int>> dp(n, vector<int>(x + 1, 0));

//     // BASE CASE :
//     for (int target = 0; target <= x; ++target)
//     {
//         if (target % nums[0] == 0)
//             dp[0][target] = target / nums[0];
//         else
//             dp[0][target] = 1e7;
//     }

//     for (int ind = 1; ind < n; ++ind)
//     {
//         for (int target = 1; target <= x; ++target)
//         {
//             // NOT PICKING UP THE ELEMENTS:
//             int notPick = 0 + dp[ind - 1][target];
//             // AS WE REQUIRE THE MINIMUM, MAKE pick MAXIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
//             int pick = 1e7;
//             // PICKING UP THE ELEMENT, ONLY IF ITS VALUE IS LESS THAN OR EQUAL TO THE target:
//             if (nums[ind] <= target)
//                 pick = 1 + dp[ind][target - nums[ind]];

//             // STORE THE MINIMUM OF pick AND notPick:
//             dp[ind][target] = min(pick, notPick);
//         }
//     }

//     // RETURN THE LAST COMPUTED INDEX VALUE:
//     return dp[n - 1][x];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * x)
// SC -> O(n) => 1-D VECTOR FOR STORING PREVIOUS ROW
int minElements(int n, int x, vector<int> &nums)
{
    // CREATING A VECTOR FOR STORING PREVIOUS ROW:
    vector<int> prev(x + 1, 0);
    // CREATING A VECTOR FOR STORING CURRENT ROW:
    vector<int> curr(x + 1, 0);

    // BASE CASE :
    for (int target = 0; target <= x; ++target)
    {
        if (target % nums[0] == 0)
            prev[target] = target / nums[0];
        else
            prev[target] = 1e7;
    }

    for (int ind = 1; ind < n; ++ind)
    {
        for (int target = 0; target <= x; ++target)
        {
            // NOT PICKING UP THE ELEMENTS:
            int notPick = 0 + prev[target];
            // AS WE REQUIRE THE MINIMUM, MAKE pick MAXIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
            int pick = 1e7;
            // PICKING UP THE ELEMENT, ONLY IF ITS VALUE IS LESS THAN OR EQUAL TO THE target:
            if (nums[ind] <= target)
                pick = 1 + curr[target - nums[ind]];

            // STORE THE MINIMUM OF pick AND notPick:
            curr[target] = min(pick, notPick);
        }
        prev = curr;
    }

    // RETURN THE LAST COMPUTED INDEX VALUE:
    return prev[x];
}
int main(void)
{
    int n = 3;
    int x = 4;
    vector<int> nums = {12, 1, 3};

    // RECURSION:
    // cout << minElements(n - 1, x, nums);

    // MEMOIZATION:
    // vector<vector<int>> dp(n,vector<int> (x+1,-1));
    // cout << minElements(n - 1, x, nums,dp);

    // TABULATION:
    // cout << minElements(n, x, nums);

    // SPACE OPTIMIZTION:
    cout << minElements(n, x, nums);
    return 0;
}