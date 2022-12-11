// There are ‘N’ diamonds in a mine. The size of each diamond is given in the form of integer array ‘A’. If the miner mines a diamond,
// then he gets 'size of previous unmined diamond * size of currently mined diamond * size of next unmined diamond' number of coins. If
// there isn’t any next or previous unmined diamond then their size is replaced by 1 while calculating the number of coins.
// Vladimir, a dumb miner was assigned the task to mine all diamonds. Since he is dumb he asks for your help to determine the maximum
// number of coins that he can earn by mining the diamonds in an optimal order.
// For Example:
// Suppose ‘N’ = 3, and ‘A’ = [7, 1, 8]

// The optimal order for mining diamonds will be [2, 1, 3].
// State of mine -    [7, 1, 8]    [7, 8]    [8]
// Coins earned -    (7*1*8) + (1*7*8) + (1*8*1)  = 56 + 56 + 8 = 120
// Hence output will be 120.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC -> O(exp)
// SC -> O(n) => AUXILIARY STACK SPACE EQUALS THE LENGTH OF THE ARRAY
// int maxCoins(int i, int j, vector<int> &a)
// {
//     // IF i & j CROSSES EACH OTHER THEN SIMPLY THERE IS NO DIAMOND LEFT, RETURN 0:
//     if (j < i)
//         return 0;

//     // TAKE A VARIABLE TO STORE MAXIMUM COINS AND ASSIGN IT THE LEAST POSSIBLE VALUE:
//     int maxx = -1e8;

//     // RUNNING A LOOP FROM FIRST DIAMOND FROM THE LAST DIAMOND I.E.; TRAVERSING EACH ELEMENT IN THE ARRAY IN THE RANGE:
//     for (int ind = i; ind <= j; ++ ind)
//     {
//         // WE ARE CALCULATING COINS BY GOING IN THE REVERSE FASHION I.E.; CONSIDERING THERE IS A SINGLE DIAMOND IN THE MINE TO THE ARRAY:
//         // COINS AFTER COLLECTIING A PARTICULAR 'ind' DIAMOND, ARE PRICE OF PREVIOUS * PRICE OF THAT DIAMOND * PRICE OF NEXT DIAMOND:
//         int coins = a[i - 1] * a[ind] * a[j + 1] + maxCoins(i, ind - 1, a) + maxCoins(ind + 1, j, a);

//         // UPDATING THE maxx :
//         if (coins > maxx)
//             maxx = coins;
//     }

//     // RETURN THE MAXIMUM COINS COLLECTED:
//     return maxx;
// }

// MEMOIZATION:
// TC -> O(n * n * n)
// SC -> O(n * n) + O(n) => DP MATRIX + AUXILIARY STACK SPACE EQUALS TO THE LENGTH OF THE ARRAY
// int maxCoins(int i, int j, vector<int> &a, vector<vector<int>> &dp)
// {
//     // IF i & j CROSSES EACH OTHER THEN SIMPLY THERE IS NO DIAMOND LEFT, RETURN 0:
//     if (j < i)
//         return 0;

//     // IF THE RECURSION CALL FOR PARTICULAR <i, j> IS ALREADY COMPUTED, RETURN THAT STORED VALUE:
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // TAKE A VARIABLE TO STORE MAXIMUM COINS AND ASSIGN IT THE LEAST POSSIBLE VALUE:
//     int maxx = -1e8;

//     // RUNNING A LOOP FROM FIRST DIAMOND FROM THE LAST DIAMOND I.E.; TRAVERSING EACH ELEMENT IN THE ARRAY IN THE RANGE:
//     for (int ind = i; ind <= j; ++ind)
//     {
//         // WE ARE CALCULATING COINS BY GOING IN THE REVERSE FASHION I.E.; CONSIDERING THERE IS A SINGLE DIAMOND IN THE MINE TO THE 
           // ARRAY:
//         // COINS AFTER COLLECTIING A PARTICULAR 'ind' DIAMOND, ARE PRICE OF PREVIOUS * PRICE OF THAT DIAMOND * PRICE OF NEXT DIAMOND:
//         int coins = a[i - 1] * a[ind] * a[j + 1] + maxCoins(i, ind - 1, a, dp) + maxCoins(ind + 1, j, a, dp);

//         // UPDATING THE maxx :
//         if (coins > maxx)
//             maxx = coins;
//     }

//     // RTEURN THE MAXIMUM COINS COLLECTED:
//     return maxx;
// }

// TABULATION:
// TC -> O(n * n * n)
// SC -> O(n * n) => TABULATION MATRIX
int maxCoins(vector<int> &a, int n)
{
    // CREATING A TABULATION MATRIX:
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    // NOT REQUIRED AS ALL CELLS ARE ALREADY ZERO: !!!
    // BASE CASE:
    // for (int i = 0; i <= n; ++i)
    //     for (int j = 0; j < i; ++j)
    //         dp[i][j] = 0;

    for (int i = n; i > 0; --i)
    {
            // IGNORING VALUES LESS THAN OR EQUAL TO THE BASE CASE:
        for (int j = i; j <= n; ++j)
        {
            // TAKE A VARIABLE TO STORE MAXIMUM COINS AND ASSIGN IT THE LEAST POSSIBLE VALUE:
            int maxx = -1e8;

            // RUNNING A LOOP FROM FIRST DIAMOND FROM THE LAST DIAMOND I.E.; TRAVERSING EACH ELEMENT IN THE ARRAY IN THE RANGE:
            for (int ind = i; ind <= j; ++ind)
            {
                // WE ARE CALCULATING COINS BY GOING IN THE REVERSE FASHION I.E.; CONSIDERING THERE IS A SINGLE DIAMOND IN THE MINE TO 
                // THE ARRAY:
                // COINS AFTER COLLECTIING A PARTICULAR 'ind' DIAMOND, ARE PRICE OF PREVIOUS * PRICE OF THAT DIAMOND * PRICE OF NEXT 
                // DIAMOND:
                int coins = a[i - 1] * a[ind] * a[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];

                // UPDATING THE maxx :
                if (coins > maxx)
                    maxx = coins;
            }

            // STORE THE MAX COINS SO FAR COLLLECTED:
            dp[i][j] = maxx;
        }
    }

    // RETURN THE LAST COMPUTED CALL:
    return dp[1][n];
}
int main(void)
{
    vector<int> a = {1, 5, 2, 8};
    int n = a.size();
    // AS FIRST AND LAST DIAMONDS' PRICE ARE DEPENDENT ON ITS PREVIOUS & NEXT DIAMONDS, SO JUST INSERT '1' ON BOTH ENDS :
    a.push_back(1);
    a.insert(a.begin(), 1);

    // RECURSION:
    // cout << maxCoins(1, n, a);

    // MEMOIZATION:
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // cout << maxCoins(1, n, a, dp);

    // TABULATION:
    cout << maxCoins(a, n);
    return 0;
}