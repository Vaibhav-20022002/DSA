// FIBONACCI SERIES: 0,1,1,2,3,5,8,13,21,…

#include <iostream>
#include <vector>
using namespace std;

// RECURSIVE WAY:
// TC-> EXPONENTIAL O(2^N)
// int Fibo(int n)
// {
//     if (n <= 1)
//         return n;
//     return Fibo(n - 1) + Fibo(n - 2);
// }

// MEMOIZATION:
// STORING OVERLAPPING RECURSIVE CALLS' RETURNED VALUES !
// TC-> O(N)
// SC-> O(N)+O(N)
// int Fibo(int n, vector<int> &dp)
// {
//     if (n <= 1)
//         return n;
//     if (dp[n] != -1)
//         return dp[n];
//     return dp[n] = Fibo(n - 1, dp) + Fibo(n - 2, dp);
// }

// TABULATION:
// STORING VALUES BY THE RECURRENCE RELATION: dp[i] = dp[i - 1] + dp[i - 2] !
// TC-> O(N)
// SC-> O(N)
// int Fibo(int n)
// {
//     vector<int> dp(n + 1);
//     dp[0] = 0;
//     dp[1] = 1;
//     for (int i = 2; i <= n; ++i)
//         dp[i] = dp[i - 1] + dp[i - 2];
//     return dp[n];
// }

// SPACE OPTIMIZATION:
// RECURRENCE RELATION: dp[i] = dp[i - 1] + dp[i - 2], REQUIRES ONLY PREVIOUS 2 VALUES TO CALCULATE NEXT TERM, SO THERE IS NO NEED TO 
// CREATE A WHOLE ARRAY !!!
// TC-> O(N)
// SC-> O(1)
int Fibo(int n)
{
    int prev2 = 0, prev1 = 1;
    int curr;
    for (int i = 2; i <= n; ++i)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
int main(void)
{
    int n = 8;
    // RECURSION:
    // printf("THE %dth TERM OF THE FIBONACCI SERIES IS: %d", n, Fibo(n));

    // MEMOIZATION:
    // vector<int> dp(n + 1, -1);
    // printf("THE %dth TERM OF THE FIBONACCI SERIES IS: %d", n, Fibo(n, dp));

    // TABULATION:
    // printf("THE %dth TERM OF THE FIBONACCI SERIES IS: %d", n, Fibo(n));

    // SPACE OPTIMIZATION:
    printf("THE %dth TERM OF THE FIBONACCI SERIES IS: %d", n, Fibo(n));
    return 0;
}