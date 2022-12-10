// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total
// number of ways W, in which you can make a change for value V using coins of denominations from D. Print 0, if a change isn't possible.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC >> (FAR GREATER THAN) O(2 * n) => BECAUSE IN PICKING UP CASE, INDEX IS NOT REDUCING
// SC >> (FAR GREATER THAN) O(n) => BECAUSE IN PICKING UP CASE, INDEX IS NOT REDUCING
// int countWays(int ind, int target, vector<int> &coins)
// {
//     // BASE CASE :
//     if (ind == 0)
//         // IF THE target ACHIEVABLE BY THE LAST(FIRST) COIN, THEN RETURN 1 OTHERWISE 0:
//         return (target % coins[0] == 0);

//     // NOT PICKING UP THE COIN:
//     int notPick = countWays(ind - 1, target, coins);
//     // MAKE pick EQUALS TO ZERO AS target IS SMALLER THAN THE DENOMINATION, THEN THE NUMBER OF WAYS TO MAKE target IS ZERO:
//     int pick = 0;
//     // PICKING UP THE COIN, BUT INDEX NOT GET REDUCE AS WE'VE UNLIMITED SUPPLY OF COINS:
//     if (target >= coins[ind])
//         pick = countWays(ind, target - coins[ind], coins);

//     // RETURN THE TOTAL NUMBER OF RECURSION CALLS:
//     return pick + notPick;
// }

// MEMOIZATION:
// TC -> O(n * target)
// SC -> O(n * target) + >>O(n) => DP MATRIX + EXPONENTIAL SPACE COMPLEXITY
// int countWays(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
// {
//     // BASE CASE :
//     if (ind == 0)
//         // IF THE target ACHIEVABLE BY THE LAST(FIRST) COIN, THEN RETURN 1 OTHERWISE 0:
//         return (target % coins[0] == 0);

//     // IF THE RECURSION CALL FOR PARTICULAR <ind, target> IS ALREADY COMPUTED, RETURN THE STORED VALUE:
//     if (dp[ind][target] != -1)
//         return dp[ind][target];

//     // NOT PICKING UP THE COIN:
//     int notPick = countWays(ind - 1, target, coins, dp);
//     // MAKE pick EQUALS TO ZERO AS target IS SMALLER THAN THE DENOMINATION, THEN THE NUMBER OF WAYS TO MAKE target IS ZERO:
//     int pick = 0;
//     // PICKING UP THE COIN, BUT INDEX NOT GET REDUCE AS WE'VE UNLIMITED SUPPLY OF COINS:
//     if (target >= coins[ind])
//         pick = countWays(ind, target - coins[ind], coins, dp);

//     // RETURN THE TOTAL NUMBER OF RECURSION CALLS:
//     return dp[ind][target] = pick + notPick;
// }

// TABULATION:
// TC -> O(n * target)
// SC -> O(n * target) => TABULATION MATRIX
// int countWays(int n, int tar, vector<int> &coins)
// {
//     // CREATING A TABULATION MATRIX OF SIZE <n, target + 1>:
//     vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

//     // BASE CASE :
//     for (int target = 0; target <= tar; ++target)
//         dp[0][target] = (target % coins[0] == 0);

//     for (int ind = 1; ind < n; ++ind)
//     {
//         for (int target = 0; target <= tar; ++target)
//         {
//             // NOT PICKING UP THE COIN:
//             int notPick = dp[ind - 1][target];
//             // MAKE pick EQUALS TO ZERO AS target IS SMALLER THAN THE DENOMINATION, THEN THE NUMBER OF WAYS TO MAKE target IS ZERO:
//             int pick = 0;
//             // PICKING UP THE COIN, BUT INDEX NOT GET REDUCE AS WE'VE UNLIMITED SUPPLY OF COINS:
//             if (target >= coins[ind])
//                 pick = dp[ind][target - coins[ind]];

//             // STORE THE TOTAL NUMBER OF RECURSION CALLS:
//             dp[ind][target] = pick + notPick;
//         }
//     }

//     // RETURN THE LAST COMPUTED CELL:
//     return dp[n - 1][tar];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * target)
// SC -> O(n) => 1-D VECTOR FOR STORING PREVIOUS ROW
int countWays(int n, int tar, vector<int> &coins)
{
    // CREATING A 1-D VECTOR FOR STORING PREVIOUS ROW:
    vector<int> prev(tar + 1, 0);

    // BASE CASE :
    for (int target = 0; target <= tar; ++target)
        prev[target] = (target % coins[0] == 0);

    for (int ind = 1; ind < n; ++ind)
    {
        for (int target = 0; target <= tar; ++target)
        {
            // NOT PICKING UP THE COIN:
            int notPick = prev[target];
            // MAKE pick EQUALS TO ZERO AS target IS SMALLER THAN THE DENOMINATION, THEN THE NUMBER OF WAYS TO MAKE target IS ZERO:
            int pick = 0;
            // PICKING UP THE COIN, BUT INDEX NOT GET REDUCE AS WE'VE UNLIMITED SUPPLY OF COINS:
            if (target >= coins[ind])
                pick = prev[target - coins[ind]];

            // STORE THE TOTAL NUMBER OF RECURSION CALLS:
            prev[target] = pick + notPick;
        }
    }

    // RETURN THE LAST COMPUTED CELL:
    return prev[tar];
}
int main(void)
{
    int n = 3;
    vector<int> coins = {1, 2, 5};
    int target = 5;

    // RECURSION:
    cout << countWays(n - 1, target, coins);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    // cout << countWays(n - 1, target, coins,dp);

    // TABULATION:
    // cout << countWays(n, target, coins);

    // SPACE OPTIMIZATION:
    // cout << countWays(n, target, coins);
    return 0;
}