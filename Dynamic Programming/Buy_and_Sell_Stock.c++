// You are Harshad Mehta’s friend. He told you the price of a particular stock for the next ‘N’ days. You can either buy or sell a stock.
// Also, you can only complete at most 2-transactions. Find the maximum profit that you can earn from these transactions. You can take
// help from Mr. Mehta as well.
// Note
// 1. Buying a stock and then selling it is called one transaction.
// 2. You are not allowed to do multiple transactions at the same time. This means you have to sell the stock before buying it again.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC -> O(exp)
// SC -> O(n) => AUXILIARY STACK SPACE EQUALS TO THE LENGTH OF ARRAY
// int maxProfit(int ind, int buy, int transactions, vector<int> &prices, int n)
// {
//     // BASE CASE:
//     // IF THE NUMBER OF TRANSACTIONS GETS EXHAUTSED OR DAYS (ARRAY) GETS EXHAUSTED, NO BUY & SELLING IS POSSIBLE, RETURN ZERO:
//     if (transactions == 0 || ind == n)
//         return 0;

//     // IF BUYING THE STOCK IS POSSIBLE:
//     if (buy)
//         // PROFIT WILL BE NEGATIVE OF PRICES, TRANSACTION REMAINS SAME AS TRANSACTIONS IS NOT COMPLETED:
//         return max(-prices[ind] + maxProfit(ind + 1, 0, transactions, prices, n),
//                    0 + maxProfit(ind + 1, 1, transactions, prices, n));

//     // PROFIT WILL BE POSITIVE OF PRICES, TRANSACTION GETS COMPLETED (TRANSACTION = BUYING + SELLING), REDUCE TRANSACTION BY '1':
//     return max(prices[ind] + maxProfit(ind + 1, 1, transactions - 1, prices, n),
//                0 + maxProfit(ind + 1, 0, transactions, prices, n));
// }

// MEMOIZATION:
// TC -> O(n * 2 * 3)
// SC -> O(n * 2 * 3) + O(n) => DP MATRIX + AUXILIARY STACK SPACE
// int maxProfit(int ind, int buy, int transactions, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
// {
//     // BASE CASE:
//     // IF THE NUMBER OF TRANSACTIONS GETS EXHAUTSED OR DAYS (ARRAY) GETS EXHAUSTED, NO BUY & SELLING IS POSSIBLE, RETURN ZERO:
//     if (transactions == 0 || ind == n)
//         return 0;

//     // IF THE RECURSION CALL FOR PARTICULAR <ind, buy, transactions> IS PRECOMPUTED, RETURN STORED VALUE:
//     if (dp[ind][buy][transactions] != -1)
//         return dp[ind][buy][transactions];

//     // IF BUYING THE STOCK IS POSSIBLE:
//     if (buy)
//         // PROFIT WILL BE NEGATIVE OF PRICES, TRANSACTION REMAINS SAME AS TRANSACTIONS IS NOT COMPLETED:
//         return dp[ind][buy][transactions] = max(-prices[ind] + maxProfit(ind + 1, 0, transactions, prices, n, dp),
//                                                 0 + maxProfit(ind + 1, 1, transactions, prices, n, dp));

//     // PROFIT WILL BE POSITIVE OF PRICES, TRANSACTION GETS COMPLETED (TRANSACTION = BUYING + SELLING), REDUCE TRANSACTION BY '1':
//     return dp[ind][buy][transactions] = max(prices[ind] + maxProfit(ind + 1, 1, transactions - 1, prices, n, dp),
//                                             0 + maxProfit(ind + 1, 0, transactions, prices, n, dp));
// }

// TABULATION:
// TC -> O(n * 2 * 3)
// SC -> O(n * 2 * 3) => TABULATION MATRIX
// int maxProfit(int n, vector<int> &prices)
// {
//     // CREATING A 3-D VECTOR FOR STORING <ind, buy, transactions> :
//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

//     // NOT REQUIRED AS ALL CELLS ARE ALREADY ZERO !!!
//     // BASE CASE:
//     // for (int ind = 0; ind <= n; ++ind)
//     // {
//     //     dp[ind][0][0] = 0;
//     //     dp[ind][1][0] = 0;
//     // }
//     // for (int transactions = 0; transactions < 3; ++transactions)
//     // {
//     //     dp[n][0][transactions] = 0;
//     //     dp[n][1][transactions] = 0;
//     // }

//     for (int ind = n - 1; ind >= 0; --ind)
//     {
//         for (int buy = 0; buy < 2; ++buy)
//         {
//             // transactions = 0 IS A BASE CASE WHICH IS ALREADY COMPUTED:
//             for (int transactions = 1; transactions <= 2; ++transactions)
//             {
//                 // IF BUYING THE STOCK IS POSSIBLE:
//                 if (buy)
//                     // PROFIT WILL BE NEGATIVE OF PRICES, TRANSACTION REMAINS SAME AS TRANSACTIONS IS NOT COMPLETED:
//                     dp[ind][buy][transactions] = max(-prices[ind] + dp[ind + 1][0][transactions],
//                                                      0 + dp[ind + 1][1][transactions]);

//                 // PROFIT WILL BE POSITIVE OF PRICES, TRANSACTION GETS COMPLETED (TRANSACTION = BUYING + SELLING), REDUCE TRANSACTION
//                 // BY '1':
//                 else
//                     dp[ind][buy][transactions] = max(prices[ind] + dp[ind + 1][1][transactions - 1],
//                                                      0 + dp[ind + 1][0][transactions]);
//             }
//         }
//     }

//     // RETURN THE LAST COMPUTED CELL:
//     return dp[0][1][2];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * 2 * 3)
// SC -> O(2 * 3) + O(2 * 3) => 2 VECTORS FOR STORING PREVIOUS AND CURENT ROWS
int maxProfit(int n, vector<int> &prices)
{
    // CREATING 2 2-D VECTORS FOR STORING PREVIOUS AND CURRENT ROWS:
    vector<vector<int>> prev(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    // NOT REQUIRED AS ALL CELLS ARE ALREADY ZERO !!!
    // BASE CASE:
    // for (int ind = 0; ind <= n; ++ind)
    // {
    //     prev[0][0] = 0;
    //     prev[1][0] = 0;
    // }
    // for (int transactions = 0; transactions < 3; ++transactions)
    // {
    //     prev[0][transactions] = 0;
    //     prev[1][transactions] = 0;
    // }

    for (int ind = n - 1; ind >= 0; --ind)
    {
        for (int buy = 0; buy < 2; ++buy)
        {
            // transactions = 0 IS A BASE CASE WHICH IS ALREADY COMPUTED:
            for (int transactions = 1; transactions <= 2; ++transactions)
            {
                // IF BUYING THE STOCK IS POSSIBLE:
                if (buy)
                    // PROFIT WILL BE NEGATIVE OF PRICES, TRANSACTION REMAINS SAME AS TRANSACTIONS IS NOT COMPLETED:
                    curr[buy][transactions] = max(-prices[ind] + prev[0][transactions],
                                                  0 + prev[1][transactions]);

                // PROFIT WILL BE POSITIVE OF PRICES, TRANSACTION GETS COMPLETED (TRANSACTION = BUYING + SELLING), REDUCE TRANSACTION
                // BY '1':
                else
                    curr[buy][transactions] = max(prices[ind] + prev[1][transactions - 1],
                                                  0 + prev[0][transactions]);
            }
        }
        prev = curr;
    }

    // RETURN THE LAST COMPUTED CELL:
    return prev[1][2];
}

int main(void)
{
    vector<int> prices = {3, 3, 5, 0, 3, 1, 4};
    int n = prices.size();

    // RECURSION:
    // cout << maxProfit(0, 1, 2, prices, n);

    // MEMOIZATION:
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // cout << maxProfit(0, 1, 2, prices, n, dp);

    // TABULATION:
    // cout << maxProfit(n, prices);

    // SPACE OPTIMIZATION:
    cout << maxProfit(n, prices);
    return 0;
}