// A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and
// is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum
// value that a thief can generate by stealing items.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// TC -> O(2 * n)
// SC -> O(n) = > AUXILIARY STACK SPACE
// int knapSack(int ind, vector<int> &weight, vector<int> &value, int w)
// {
//     // IF REACHING THE LAST INDEX RETURN THE VALUE OF THAT PARTICULAR ITEM, IF IT CAN BE FIT IN THE BAG:
//     if (ind == 0)
//     {
//         if (weight[0] <= w)
//             return value[0];
//         return 0;
//     }

//     // NOT PICKING UP THE ITEM:
//     int notPick = 0 + knapSack(ind - 1, weight, value, w);

//     // GIVING pick THE MINIMUM VALUE TO AVOID ITS CONSIDERATION:
//     int pick = -1e7;
//     // PICKING UP THE ITEM IF THE WEIGHT OF THE ITEM IS LESS THAN OR EQUAL TO THE WEIGHT ACCOMODATED BY THE BAG:
//     if (weight[ind] <= w)
//         pick = value[ind] + knapSack(ind - 1, weight, value, w - weight[ind]);

//     // RETURN THE MAXIMUM AMONG pick AND notPick:
//     return max(pick, notPick);
// }

// MEMOIZATION:
// TC -> O(n * w)
// SC -> O(n) + O(n * w) = > AUXILARY STACK SPACE + DP MATRIX
// int knapSack(int ind, vector<int> &weight, vector<int> &value, int w, vector<vector<int>> &dp)
// {
//     // IF REACHING THE LAST INDEX RETURN THE VALUE OF THAT PARTICULAR ITEM, IF IT CAN BE FIT IN THE BAG:
//     if (ind == 0)
//     {
//         if (weight[0] <= w)
//             return value[0];
//         return 0;
//     }

//     // IF THE RECURSION CALL FOR PARTICULAR <ind, w> IS PRECOMPUTED, RETURN THAT STORED VALUE:
//     if (dp[ind][w] != -1)
//         return dp[ind][w];

//     // NOT PICKING UP THE ITEM:
//     int notPick = 0 + knapSack(ind - 1, weight, value, w, dp);

//     // GIVING pick THE MINIMUM VALUE TO AVOID ITS CONSIDERATION:
//     int pick = -1e7;
//     // PICKING UP THE ITEM IF THE WEIGHT OF THE ITEM IS LESS THAN OR EQUAL TO THE WEIGHT ACCOMODATED BY THE BAG:
//     if (weight[ind] <= w)
//         pick = value[ind] + knapSack(ind - 1, weight, value, w - weight[ind], dp);

//     // RETURN THE MAXIMUM AMONG pick AND notPick:
//     return dp[ind][w] = max(pick, notPick);
// }

// TABULATION:
// TC -> O(n * w)
// SC -> O(n * w) => DP MATRIX
// int knapSack(int n, vector<int> &weight, vector<int> &value, int maxWeight)
// {
//     // CREATING A 2-D  DP MATRIX TO STORE VALUE OF <ind, w> :: <n, w + 1> :
//     vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

//     // BASE CASE :
//     for (int w = 0; w <= maxWeight; ++w)
//         if (weight[0] <= w)
//             dp[0][w] = value[0];

//     for (int ind = 1; ind < n; ++ind)
//     {
//         for (int w = 1; w <= maxWeight; ++w)
//         {
//             // NOT PICKING UP THE ITEM:
//             int notPick = 0 + dp[ind-1][w];

//             // GIVING pick THE MINIMUM VALUE TO AVOID ITS CONSIDERATION:
//             int pick = -1e7;
//             // PICKING UP THE ITEM IF THE WEIGHT OF THE ITEM IS LESS THAN OR EQUAL TO THE WEIGHT ACCOMODATED BY THE BAG:
//             if (weight[ind] <= w)
//                 pick = value[ind] + dp[ind-1][w-weight[ind]];

//             // STORING THE MAXIMUM AMONG pick AND notPick:
//             dp[ind][w] = max(pick, notPick);
//         }
//     }

//     // RETURN THE LAST STORED VALUE:
//     return dp[n - 1][maxWeight];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * w)
// SC -> O(w) => SINGLE ARRAY (prev) OPTIMIZATION
int knapSack(int n, vector<int> &weight, vector<int> &value, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    // BASE CASE :
    for (int w = weight[0]; w <= maxWeight; ++w)
        prev[w] = value[0];

    for (int ind = 1; ind < n; ++ind)
    {
        // WE ONLY REQUIRE THE LEFT ELEMENTS TO COMPUTE THE RIGHT ONES, SO COMPUTING THE ELEMENTS FROM RIGHT TO LEFT, HENCE IT CAN BE DONE
        // USING A SINGLE ROW ; "prev[w - weight[ind]]" -> DUE TO THIS !!!
        for (int w = maxWeight; w >= 0; --w)
        {
            // NOT PICKING UP THE ITEM:
            int notPick = 0 + prev[w];

            // GIVING pick THE MINIMUM VALUE TO AVOID ITS CONSIDERATION:
            int pick = -1e7;
            // PICKING UP THE ITEM IF THE WEIGHT OF THE ITEM IS LESS THAN OR EQUAL TO THE WEIGHT ACCOMODATED BY THE BAG:
            if (weight[ind] <= w)
                pick = value[ind] + prev[w - weight[ind]];

            // STORING THE MAXIMUM AMONG pick AND notPick:
            prev[w] = max(pick, notPick);
        }
    }

    // RETURN THE LAST STORED VALUE:
    return prev[maxWeight];
}
int main(void)
{
    int n = 4;
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int w = 5;

    // RECURSION:
    // cout << knapSack(n - 1, weight, value, w);

    // MEMOIZARION:
    // vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    // cout << knapSack(n - 1, weight, value, w, dp);

    // TABULATION:
    // cout << knapSack(n, weight, value, w);

    // SPACE OPTIMIZATION :
    cout << knapSack(n, weight, value, w);
    return 0;
}