// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the
// maximum cost obtained by cutting the rod and selling its pieces.
#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC >> (FAR GREATER THAN) O(2 * n) => BECAUSE IN PICKING UP CASE, INDEX IS NOT REDUCING
// SC >> (FAR GREATER THAN) O(n) => BECAUSE IN PICKING UP CASE, INDEX IS NOT REDUCING
// int maxCost(int ind, int n, vector<int> &price)
// {
//     // BASE CASE :
//     if (ind == 0)
//         // IF ON THE LAST(FIRST) INDEX, CUT THE ROD TILL REMAINING n PIECES:
//         return n * price[0];

//     // IF NOT CUTTING THE ROD:
//     int notCut = 0 + maxCost(ind - 1, n, price);
//     // IF CUTTING THE ROD, MAKE cut MINIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
//     int cut = -1e8;
//     // IF ROD LENGTH IS LESS THAN n, CUT THE ROD:
//     if (ind + 1 <= n)
//         cut = price[ind] + maxCost(ind, n - (ind + 1), price);

//     // RETURN THE MAXIMUM AMONG notCut AND cut :
//     return max(cut, notCut);
// }

// MEMOIZATION:
// TC -> O(n * n)
// SC -> O(n * n) + >>O(n) => DP MATRIX + EXPONENTIAL SPACE COMPLEXITY
// int maxCost(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
// {
//     // BASE CASE :
//     if (ind == 0)
//         // IF ON THE LAST(FIRST) INDEX, CUT THE ROD TILL REMAINING n PIECES:
//         return n * price[0];

//     // IF THE RECURSION CALL FOR PARTICULAR <ind, n> IS ALREADY COMPUTED, RETURN THE STORED VALUE:
//     if (dp[ind][n] != -1)
//         return dp[ind][n];

//     // IF NOT CUTTING THE ROD:
//     int notCut = 0 + maxCost(ind - 1, n, price, dp);
//     // IF CUTTING THE ROD, MAKE cut MINIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
//     int cut = -1e8;
//     // IF ROD LENGTH IS LESS THAN n, CUT THE ROD:
//     if (ind + 1 <= n)
//         cut = price[ind] + maxCost(ind, n - (ind + 1), price, dp);

//     // RETURN THE MAXIMUM AMONG notCut AND cut :
//     return dp[ind][n] = max(cut, notCut);
// }

// TABULATION :
// TC -> O(n * n)
// SC -> O(n * n) => TABULATION MATRIX
// int maxCost(int N, vector<int> &price)
// {
//     // CREATING A TABULATED MATRIX OF SIZE <ind, n> :
//     vector<vector<int>> dp(N, vector<int>(N + 1, 0));

//     // BASE CASE :
//     for (int n = 0; n <= N; ++n)
//         dp[0][n] = n * price[0];

//     for (int ind = 1; ind < N; ++ind)
//     {
//         for (int n = 0; n <= N; ++n)
//         {
//             // IF NOT CUTTING THE ROD:
//             int notCut = 0 + dp[ind - 1][n];
//             // IF CUTTING THE ROD, MAKE cut MINIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
//             int cut = -1e8;
//             // IF ROD LENGTH IS LESS THAN n, CUT THE ROD:
//             if (ind + 1 <= n)
//                 cut = price[ind] + dp[ind][n - (ind + 1)];

//             // STORE THE MAXIMUM AMONG notCut AND cut :
//             dp[ind][n] = max(cut, notCut);
//         }
//     }

//     // RETURN THE LAST COMPUTED CELL:
//     return dp[N - 1][N];
// }

// SPACE OPTIMIZATION:
// TC -> O(n * n)
// SC -> O(n) => 1-D VECTOR FOR STORING PREVIOUS ROW
int maxCost(int N, vector<int> &price)
{
    // CREATING A 1-D VECTOR TO STORE PREVIOUS ROW:
    vector<int> prev(N + 1, 0);

    // BASE CASE :
    for (int n = 0; n <= N; ++n)
        prev[n] = n * price[0];

    for (int ind = 1; ind < N; ++ind)
    {
        for (int n = 0; n <= N; ++n)
        {
            // IF NOT CUTTING THE ROD:
            int notCut = 0 + prev[n];
            // IF CUTTING THE ROD, MAKE cut MINIMUM POSSIBLE TO AVOID ITS CONSIDERATION:
            int cut = -1e8;
            // IF ROD LENGTH IS LESS THAN n, CUT THE ROD:
            if (ind + 1 <= n)
                cut = price[ind] + prev[n - (ind + 1)];

            // STORE THE MAXIMUM AMONG notCut AND cut :
            prev[n] = max(cut, notCut);
        }
    }

    // RETURN THE LAST COMPUTED CELL:
    return prev[N];
}
int main(void)
{
    int n = 8;
    vector<int> price = {3, 5, 8, 9, 10, 17, 17, 20};

    // RECURSION:
    // cout << maxCost(n - 1, n, price);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // cout << maxCost(n - 1, n, price, dp);

    // TABULATION:
    // cout << maxCost(n, price);

    // SPACE OPTIMIZATION:
    cout << maxCost(n, price);
    return 0;
}