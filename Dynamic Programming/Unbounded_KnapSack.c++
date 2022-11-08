// You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. You need to fill the knapsack with
// the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC >> (FAR GREATER THAN) O(2 * n) => BECAUSE IN PICKING UP CASE, INDEX IS NOT REDUCING
// SC >> (FAR GREATER THAN) O(n) => BECAUSE IN PICKING UP CASE, INDEX IS NOT REDUCING
// int maxProfit(int ind, int w, vector<int> &profit, vector<int> &weight)
// {
//     // BASE CASE:
//     if (ind == 0)
//         return profit[0] * ((int)(w / weight[0]));

//     // IF NOT PICKING UP THE ITEM:
//     int notPick = 0 + maxProfit(ind - 1, w, profit, weight);
//     // IF PICKING UP THE ITEM IS NOT POSSIBLE, MAKE pick THE LEAST POSSIBLE TO AVOID ITS CONSIDERATION:
//     int pick = -1e8;
//     // IF PICKING UP THE ITEM, ONLY WHEN THE KNAPSACK CAPACITY IS MORE THAN THE ITEM WEIGHT:
//     if (weight[ind] <= w)
//         pick = profit[ind] + maxProfit(ind, w - weight[ind], profit, weight);

//     // RETURN THE MAX AMONG pick AND notPick:
//     return max(pick, notPick);
// }

// MEMOIZATION:
// TC -> O(n * w)
// SC -> O(n * w) + >>O(n) => DP MATRIX + EXPONENTIAL SPACE COMPLEXITY
// int maxProfit(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
// {
//     // BASE CASE:
//     if (ind == 0)
//         return profit[0] * ((int)(w / weight[0]));

//     // IF THE RECURSION CALL FOR PARTICULAR <ind, w> IS ALREADY COMPUTED, RETURN THE STORED VALUE:
//     if (dp[ind][w] != -1)
//         return dp[ind][w];

//     // IF NOT PICKING UP THE ITEM:
//     int notPick = 0 + maxProfit(ind - 1, w, profit, weight, dp);
//     // IF PICKING UP THE ITEM IS NOT POSSIBLE, MAKE pick THE LEAST POSSIBLE TO AVOID ITS CONSIDERATION:
//     int pick = -1e8;
//     // IF PICKING UP THE ITEM, ONLY WHEN THE KNAPSACK CAPACITY IS MORE THAN THE ITEM WEIGHT:
//     if (weight[ind] <= w)
//         pick = profit[ind] + maxProfit(ind, w - weight[ind], profit, weight, dp);

//     // RETURN THE MAX AMONG pick AND notPick:
//     return dp[ind][w] = max(pick, notPick);
// }

// TABULATION:
// TC -> O(n * w)
// SC -> O(n * w) => TABULATION MATRIX
// int maxProfit(int n, int W, vector<int> &profit, vector<int> &weight)
// {
//     // CREATING A TABULATION MATRIX OF SIZE <ind, w> :: <n, W> :
//     vector<vector<int>> dp(n, vector<int>(W + 1, 0));

//     // BASE CASE :
//     for (int w = 0; w <= W; ++w)
//         dp[0][w] = profit[0] * ((int)(w / weight[0]));

//     for (int ind = 1; ind < n; ++ind)
//     {
//         for (int w = 0; w <= W; ++w)
//         {
//             // IF NOT PICKING UP THE ITEM:
//             int notPick = 0 + dp[ind - 1][w];
//             // IF PICKING UP THE ITEM IS NOT POSSIBLE, MAKE pick THE LEAST POSSIBLE TO AVOID ITS CONSIDERATION:
//             int pick = -1e8;
//             // IF PICKING UP THE ITEM, ONLY WHEN THE KNAPSACK CAPACITY IS MORE THAN THE ITEM WEIGHT:
//             if (weight[ind] <= w)
//                 pick = profit[ind] + dp[ind][w - weight[ind]];

//             // STORE THE MAX AMONG pick AND notPick:
//             dp[ind][w] = max(pick, notPick);
//         }
//     }

//     // RETURN THE LAST COMPUTED CELL:
//     return dp[n - 1][W];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * w)
// SC -> O(n) => 1-D VECTOR FOR STORING PREVIOUS ROW
int maxProfit(int n, int W, vector<int> &profit, vector<int> &weight)
{
    // CREATING A 1-D VECTOR FOR STORING PREVIOUS ROW:
    vector<int> prev(W + 1, 0);

    // BASE CASE :
    for (int w = 0; w <= W; ++w)
        prev[w] = profit[0] * ((int)(w / weight[0]));

    for (int ind = 1; ind < n; ++ind)
    {
        for (int w = 0; w <= W; ++w)
        {
            // IF NOT PICKING UP THE ITEM:
            int notPick = 0 + prev[w];
            // IF PICKING UP THE ITEM IS NOT POSSIBLE, MAKE pick THE LEAST POSSIBLE TO AVOID ITS CONSIDERATION:
            int pick = -1e8;
            // IF PICKING UP THE ITEM, ONLY WHEN THE KNAPSACK CAPACITY IS MORE THAN THE ITEM WEIGHT:
            if (weight[ind] <= w)
                pick = profit[ind] + prev[w - weight[ind]];

            // STORE THE MAX AMONG pick AND notPick:
            prev[w] = max(pick, notPick);
        }
    }

    // RETURN THE LAST COMPUTED CELL:
    return prev[W];
}
int main(void)
{
    int n = 3, w = 15;
    vector<int> profit = {7, 2, 4};
    vector<int> weight = {5, 10, 20};

    // RECURSION:
    // cout << maxProfit(n - 1, w, profit, weight);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    // cout << maxProfit(n - 1, w, profit, weight, dp);

    // TABULATION:
    // cout << maxProfit(n, w, profit, weight);

    // SPACE OPTIMIZATION:
    cout << maxProfit(n, w, profit, weight);
    return 0;
}