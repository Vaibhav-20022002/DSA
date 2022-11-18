// You have been given stock values/prices for N number of days. Every i-th day signifies the price of a stock on that day. Your task is
// to find the maximum profit which you can make by buying and selling the stocks.
// Note :
// You may make as many transactions as you want but can not have more than one transaction at a time i.e, if you have the stock, you
// need to sell it first, and then only you can buy it again.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC -> O(2^n) => EVERY STOCK HAS TO OPTION, BUY OR SELL
// SC -> O(n) => AUXILIARY STACK SPACE EQUALS TO THE LENGTH OF ARRAY
// long getMaximumProfit(int ind, bool buy, vector<long> &values, int n)
// {
//     // BASE CASE:
//     // IF DAYS GETS COMPLETED (ARRAY GETS EXAUSTED), THERE IS NO PROFIT:
//     if (ind == n)
//         return 0;

//     // AT START PROFIT IS ZERO:
//     long profit = 0;
//     // IF THE BUYING IS POSSIBLE:
//     if (buy)
//         // TAKE MAXIMUM OF PROFIT BY BUYING THAT STOCK AND LEAVING THAT STOCK:
//         profit = max(-values[ind] + getMaximumProfit(ind + 1, 0, values, n),
//                      0 + getMaximumProfit(ind + 1, 1, values, n));
//     // IF BUYING IS NOT POSSIBLE OR SELLING IS POSSIBLE:
//     else
//         // TAKE MAXIMUM OF PROFIT BY SELLING THAT STOCK AND LEAVING THAT STOCK:
//         profit = max(values[ind] + getMaximumProfit(ind + 1, 1, values, n),
//                      0 + getMaximumProfit(ind + 1, 0, values, n));

//     // RETURN THE MAXIMUM PROFIT:
//     return profit;
// }

// MEMOIZATION:
// TC -> O(n * 2) => O(n * buy)
// SC -> O(n * 2) + O(n) => DP MATRIX + AUXLIARY STACK SPACE EQUALS TO THE LENGTH OF ARRAY
// long getMaximumProfit(int ind, bool buy, vector<long> &values, int n, vector<vector<long>> &dp)
// {
//     // BASE CASE:
//     // IF DAYS GETS COMPLETED (ARRAY GETS EXAUSTED), THERE IS NO PROFIT:
//     if (ind == n)
//         return 0;

//     // IF THE RECURSION CALL FOR PARTICULAR <n, buy> IS PRECOMPUTED, RETURN THAT VALUE:
//     if (dp[ind][buy] != -1)
//         return dp[ind][buy];

//     // AT START PROFIT IS ZERO:
//     long profit = 0;
//     // IF THE BUYING IS POSSIBLE:
//     if (buy)
//         // TAKE MAXIMUM OF PROFIT BY BUYING THAT STOCK AND LEAVING THAT STOCK:
//         profit = max(-values[ind] + getMaximumProfit(ind + 1, 0, values, n, dp),
//                      0 + getMaximumProfit(ind + 1, 1, values, n, dp));
//     // IF BUYING IS NOT POSSIBLE OR SELLING IS POSSIBLE:
//     else
//         // TAKE MAXIMUM OF PROFIT BY SELLING THAT STOCK AND LEAVING THAT STOCK:
//         profit = max(values[ind] + getMaximumProfit(ind + 1, 1, values, n, dp),
//                      0 + getMaximumProfit(ind + 1, 0, values, n, dp));

//     // RETURN THE MAXIMUM PROFIT:
//     return dp[ind][buy] = profit;
// }

// TABULATION:
// TC -> O(n * 2)
// SC -> O(n * 2) => TABULATION MATRIX
// long getMaximumProfit(int n, vector<long> &values)
// {
//     // CREATING A TABULATION MATRIX OF SIZE <n + 1, 2>:
//     vector<vector<long>> dp(n + 1, vector<long>(2, 0));

//     // BASE CASE :
//     dp[n][0] = dp[n][1] = 0;

//     for (int ind = n - 1; ind >= 0; --ind)
//     {
//         for (int buy = 0; buy < 2; ++buy)
//         {
//             // IF THE BUYING IS POSSIBLE:
//             if (buy)
//                 // TAKE MAXIMUM OF PROFIT BY BUYING THAT STOCK AND LEAVING THAT STOCK:
//                 dp[ind][buy] = max(-values[ind] + dp[ind + 1][0],
//                                    0 + dp[ind + 1][1]);
//             // IF BUYING IS NOT POSSIBLE OR SELLING IS POSSIBLE:
//             else
//                 // TAKE MAXIMUM OF PROFIT BY SELLING THAT STOCK AND LEAVING THAT STOCK:
//                 dp[ind][buy] = max(values[ind] + dp[ind + 1][1],
//                                    0 + dp[ind + 1][0]);
//         }
//     }
//     // RETURN THE LAST COMPUTED CELL:
//     return dp[0][1];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * 2)
// SC -> O(2) + O(2) => 2 VECTOR OF SIZE '2' FOR STORING PREVIOUS AND CURRENT ROWS
// long getMaximumProfit(int n, vector<long> &values)
// {
//     // CREATING 2 1-D VECTORS OF SIZE '2' FOR STORING PREVIOUS AND CURRENT ROWS:
//     vector<long> prev(2, 0), curr(2, 0);

//     // NOT REQUIRED AS PREV IS ALREADY SET TO ZERO !!!
//     // BASE CASE :
//     // prev[0] = prev[1] = 0;

//     for (int ind = n - 1; ind >= 0; --ind)
//     {
//         for (int buy = 0; buy < 2; ++buy)
//         {
//             // IF THE BUYING IS POSSIBLE:
//             if (buy)
//                 // TAKE MAXIMUM OF PROFIT BY BUYING THAT STOCK AND LEAVING THAT STOCK:
//                 curr[buy] = max(-values[ind] + prev[0],
//                                 0 + prev[1]);
//             // IF BUYING IS NOT POSSIBLE OR SELLING IS POSSIBLE:
//             else
//                 // TAKE MAXIMUM OF PROFIT BY SELLING THAT STOCK AND LEAVING THAT STOCK:
//                 curr[buy] = max(values[ind] + prev[1],
//                                 0 + prev[0]);
//         }
//         prev = curr;
//     }
//     // RETURN THE LAST COMPUTED CELL:
//     return prev[1];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * 2)
// SC -> O(2) + O(2) => 2 VECTOR OF SIZE '2' FOR STORING PREVIOUS AND CURRENT ROWS
long getMaximumProfit(int n, vector<long> &values)
{
    // DECLARING 4 VARIABLES FOR EACH CASE:
    long prevNotBuy, prevBuy, currNotBuy, currBuy;

    // BASE CASE:
    prevNotBuy = prevBuy = 0;

    // NOT REQUIRED AS PREV IS ALREADY SET TO ZERO !!!
    // BASE CASE :
    // prev[0] = prev[1] = 0;

    for (int ind = n - 1; ind >= 0; --ind)
    {

        // IF THE BUYING IS POSSIBLE:
        // TAKE MAXIMUM OF PROFIT BY BUYING THAT STOCK AND LEAVING THAT STOCK:
        currBuy = max(-values[ind] + prevNotBuy,
                      0 + prevBuy);
        // IF BUYING IS NOT POSSIBLE OR SELLING IS POSSIBLE:

        // TAKE MAXIMUM OF PROFIT BY SELLING THAT STOCK AND LEAVING THAT STOCK:
        currNotBuy = max(values[ind] + prevBuy,
                         0 + prevNotBuy);

        prevNotBuy = currNotBuy;
        prevBuy = currBuy;
    }
    // RETURN THE LAST COMPUTED CELL:
    return prevBuy;
}
int main(void)
{
    vector<long> values = {1, 2, 3, 4, 5, 6, 7};
    int n = values.size();

    // RECURSION:
    // cout << getMaximumProfit(0, 1, values, n);

    // MEMOIZATION:
    // vector<vector<long>> dp(n, vector<long>(2, -1));
    // cout << getMaximumProfit(0, 1, values, n, dp);

    // TABULATION:
    // cout << getMaximumProfit(n, values);

    // SPACE OPTIMZATION:
    // cout << getMaximumProfit(n, values);

    // SPACE OPTIMIZATION 2:
    cout << getMaximumProfit(n, values);
    return 0;
}