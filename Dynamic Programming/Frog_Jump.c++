// Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb
// either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in
// the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be
// used by the frog to jump from stair 0 to stair N-1.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// int frogJump(int n, vector<int> &height)
// {
//     if (n == 0)
//         return 0;
//     int onejump = frogJump(n - 1, height) + abs(height[n] - height[n - 1]);
//     int twojump = INT32_MAX;
//     if (n > 1)
//         twojump = frogJump(n - 2, height) + abs(height[n] - height[n - 2]);
//     return min(onejump, twojump);
// }

// MEMOIZATION:
// int frogJump(int n, vector<int> &height, vector<int> &dp)
// {
//     if (n == 0)
//         return 0;
//     if (dp[n] != -1)
//         return dp[n];
//     int onejump = frogJump(n - 1, height, dp) + abs(height[n] - height[n - 1]);
//     int twojump = INT32_MAX;
//     if (n > 1)
//         twojump = frogJump(n - 2, height, dp) + abs(height[n] - height[n - 2]);
//     return dp[n] = min(onejump, twojump);
// }

// TABULATION:
// int frogJump(int n, vector<int> &height)
// {
//     vector<int> dp(n);
//     dp[0] = 0;
//     for (int i = 1; i < n; ++i)
//     {
//         int onejump = dp[i - 1] + abs(height[n] - height[n - 1]);
//         int twojump = INT32_MAX;
//         if (i > 1)
//             twojump = dp[i - 2] + abs(height[n] - height[n - 2]);
//         dp[i] = min(onejump, twojump);
//     }
//     return dp[n - 1];
// }

// SPACE OPTIMIZATION:
int frogJump(int n, vector<int> &height)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < n; ++i)
    {
        int onejump = prev1 + abs(height[i] - height[i - 1]);
        int twojump = INT32_MAX;
        if (i > 1)
            twojump = prev2 + abs(height[i] - height[i - 2]);
        int curr = min(onejump, twojump);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(void)
{
    int N = 4;
    vector<int> height = {10, 20, 30, 10};
    // RECURSION:
    // cout << frogJump(N - 1, height);

    //MEMOIZATION:
    // vector<int> dp(N, -1);
    // cout << frogJump(N - 1, height, dp);

    // TABULATION:
    // vector<int> dp(N);
    // cout << frogJump(N - 1, height);

    // SPACE OPTIMIZATION:
    cout << frogJump(N - 1, height);
    return 0;
}