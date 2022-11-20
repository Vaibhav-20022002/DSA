// You are given a list of stock prices, ‘prices’. Where ‘prices[i]’ represents the price on ‘i’th day. Your task is to calculate the
// maximum profit you can earn by trading stocks if you can only hold one stock at a time. After you sell your stock on the ‘i’th day,
// you can only buy another stock on ‘i + 2’ th day or later.
// For Example:
// You are given prices = {4, 9, 0, 4, 10}, To get maximum profits you will have to buy on day 0 and sell on day 1 to make a profit of 5,
// and then you have to buy on day 3  and sell on day 4 to make the total profit of 11. Hence the maximum profit is 11.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC -> O(2 ^ n)
// SC -> O(n) => AUXILIARY STACK SPACE EQUALS TO THE LENGTH OF ARRAY
// int stockProfit(int ind, bool buy, vector<int> &prices, int n)
// {
//     // BASE CASE :
//     // IF THE ind GOES OUT OF BOUND, RETURN ZERO:
//     if (ind >= n)
//         return 0;

//     // IF THE BUYING IS POSIBLE:
//     if (buy)
//         // PROFIT WILL BE NEGATIVE OF PRICES:
//         return max(-prices[ind] + stockProfit(ind + 1, 0, prices, n),
//                    0 + stockProfit(ind + 1, 1, prices, n));
//     // IF SELLING THE STOCK, BEFORE BUYING THERE IS A COOLDOWN OF 1 DAY(ind), MOVE TO THE NEXT TO NEXT INDEX:
//     return max(prices[ind] + stockProfit(ind + 2, 1, prices, n),
//                0 + stockProfit(ind + 1, 0, prices, n));
// }

// MEMOIZATION:
// TC -> O(n * 2)
// SC -> O(n * 2) + O(n) => DP MATRIX + AUXILIARY STACK SPACE
// int stockProfit(int ind, bool buy, vector<int> &prices, int n, vector<vector<int>> &dp)
// {
//     // BASE CASE :
//     // IF THE ind GOES OUT OF BOUND, RETURN ZERO:
//     if (ind >= n)
//         return 0;

//     // IF THE RECURSION CALL FOR PARTICULAR <ind, buy> IS PRECOMPUTED, RETURN THAT STORED VALUE:
//     if (dp[ind][buy] != -1)
//         return dp[ind][buy];

//     // IF THE BUYING IS POSIBLE:
//     if (buy)
//         // PROFIT WILL BE NEGATIVE OF PRICES:
//         return dp[ind][buy] = max(-prices[ind] + stockProfit(ind + 1, 0, prices, n, dp),
//                                   0 + stockProfit(ind + 1, 1, prices, n, dp));

//     // IF SELLING THE STOCK, BEFORE BUYING THERE IS A COOLDOWN OF 1 DAY(ind), SO MOVE TO THE NEXT TO NEXT INDEX:
//     return dp[ind][buy] = max(prices[ind] + stockProfit(ind + 2, 1, prices, n, dp),
//                               0 + stockProfit(ind + 1, 0, prices, n, dp));
// }

// TABULATION:
// TC -> O(n * 2)
// SC -> O(n * 2) => TABULATION MATRIX
// int stockProfit(vector<int> &prices, int n)
// {
//     // CREATING A 2-D VECTOR FOR TABULATION:
//     vector<vector<int>> dp(n + 2, vector<int>(2, 0));

//     // NOT REQUIRED AS ALL CELLS ARE ALREADY ZERO !!!
//     // BASE CASE:
//     // dp[n][0] = dp[n][1] = 0;

//     for (int ind = n - 1; ind >= 0; --ind)
//     {
//         for (int buy = 0; buy <= 1; ++buy)
//         {
//             // IF THE BUYING IS POSIBLE:
//             if (buy)
//                 // PROFIT WILL BE NEGATIVE OF PRICES:
//                 dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
//                                    0 + dp[ind + 1][1]);
//             // IF SELLING THE STOCK, BEFORE BUYING THERE IS A COOLDOWN OF 1 DAY(ind), MOVE TO THE NEXT TO NEXT INDEX:
//             else
//                 dp[ind][buy] = max(prices[ind] + dp[ind + 2][1],
//                                    0 + dp[ind + 1][0]);
//         }
//     }

//     // RETURN THE LAST COMPUTED CELLS:
//     return dp[0][1];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * 2)
// SC -> O(2 + 2 + 2) => 3 VECTORS FOR STORING CURRENT, PREVIOUS AND SECOND PREVIOUS
// int stockProfit(vector<int> &prices, int n)
// {
//     // CREATING 3 1-D VECTORS FOR STORING CURRENT, PREVIOUS, SECOND PREVIOUS ROWS:
//     vector<int> curr(2, 0);
//     vector<int> prev(2, 0);
//     vector<int> prev2(2, 0);

//     // NOT REQUIRED AS ALL CELLS ARE ALREADY ZERO !!!
//     // BASE CASE:
//     // dp[n][0] = dp[n][1] = 0;

//     for (int ind = n - 1; ind >= 0; --ind)
//     {
//         for (int buy = 0; buy <= 1; ++buy)
//         {
//             // IF THE BUYING IS POSIBLE:
//             if (buy)
//                 // PROFIT WILL BE NEGATIVE OF PRICES:
//                 curr[buy] = max(-prices[ind] + prev[0],
//                                 0 + prev[1]);
//             // IF SELLING THE STOCK, BEFORE BUYING THERE IS A COOLDOWN OF 1 DAY(ind), MOVE TO THE NEXT TO NEXT INDEX:
//             else
//                 curr[buy] = max(prices[ind] + prev2[1],
//                                 0 + prev[0]);
//         }
//         prev2 = prev;
//         prev = curr;
//     }

//     // RETURN THE LAST COMPUTED CELLS:
//     return curr[1];
// }

// SPACE OPTIMIZATION:
// TC -> O(n)
// SC -> O(2 + 2 + 2) => 3 VECTORS FOR STORING CURRENT, PREVIOUS AND SECOND PREVIOUS
int stockProfit(vector<int> &prices, int n)
{
    // CREATING 3 1-D VECTORS FOR STORING CURRENT, PREVIOUS, SECOND PREVIOUS ROWS:
    vector<int> curr(2, 0);
    vector<int> prev(2, 0);
    vector<int> prev2(2, 0);

    // NOT REQUIRED AS ALL CELLS ARE ALREADY ZERO !!!
    // BASE CASE:
    // dp[n][0] = dp[n][1] = 0;

    for (int ind = n - 1; ind >= 0; --ind)
    {
        // for (int buy = 0; buy <= 1; ++buy)
        // {
        // IF THE BUYING IS POSIBLE:
        // if (buy)
        // PROFIT WILL BE NEGATIVE OF PRICES:
        curr[1] = max(-prices[ind] + prev[0],
                      0 + prev[1]);
        // IF SELLING THE STOCK, BEFORE BUYING THERE IS A COOLDOWN OF 1 DAY(ind), MOVE TO THE NEXT TO NEXT INDEX:
        // else
        curr[0] = max(prices[ind] + prev2[1],
                      0 + prev[0]);
        // }
        prev2 = prev;
        prev = curr;
    }

    // RETURN THE LAST COMPUTED CELLS:
    return curr[1];
}
int main(void)
{
    vector<int> prices = {4, 9, 0, 4, 10};
    int n = prices.size();

    // RECURSION:
    // cout << stockProfit(0, 1, prices, n);

    // MEMOIZATION:
    // vector<vector<int>> dp(n+1, vector<int> (2,-1));
    // cout << stockProfit(0, 1, prices, n,dp);

    // TABULATION:
    // cout << stockProfit(prices, n);

    // SPACE OPTIMIZATION:
    // cout << stockProfit(prices, n);

    // SPACE OPTIMIZATION 2:
    cout << stockProfit(prices, n);
    return 0;
}