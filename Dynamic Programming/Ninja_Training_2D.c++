// A Ninja has an ‘N’ Day training schedule. He has to perform one of these three activities (Running, Fighting Practice, or Learning
// New Moves) each day. There are merit points associated with performing an activity each day. The same activity can’t be performed on
// two consecutive days. We need to find the maximum merit points the ninja can attain in N Days.
// We are given a 2D Array POINTS of size ‘N*3’ which tells us the merit point of specific activity on that particular day. Our task is
// to calculate the maximum number of merit points that the ninja can earn.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// int maxMerits(int day, int last, vector<vector<int>> &Points)
// {
//     // THE ACTIVITY PERFORMED PREVIOUSLY CAN'T BE PERFORMED ON THE NEXT DAY:
//     if (day == 0)
//     {
//         int maxi = 0;
//         for (int task = 0; task < 3; ++task)
//             if (task != last)
//                 maxi = max(maxi, Points[0][task]);
//         return maxi;
//     }

//     int maxi = 0;
//     for (int task = 0; task < 3; ++task)
//     {
//         if (task != last)
//         {
//             int merits = Points[day][task] + maxMerits(day - 1, task, Points);
//             maxi = max(maxi, merits);
//         }
//     }
//     return maxi;
// }

// MEMOIZATION:
// int maxMerits(int day, int last, vector<vector<int>> &Points, vector<vector<int>> &dp)
// {
//     if (day == 0)
//     {
//         int maxi = 0;
//         for (int i = 0; i <= 2; i++)
//         {
//             if (i != last)
//                 maxi = max(maxi, Points[0][i]);
//         }
//         return dp[day][last] = maxi;
//     }

//     if (dp[day][last] != -1)
//         return dp[day][last];

//     int maxi = 0;
//     for (int task = 0; task < 3; ++task)
//     {
//         if (task != last)
//         {
//             int merits = Points[day][task] + maxMerits(day - 1, task, Points, dp);
//             maxi = max(maxi, merits);
//         }
//     }
//     return dp[day][last] = maxi;
// }

// TABULATION:
// int maxMerits(int n, vector<vector<int>> &Points)
// {
//     vector<vector<int>> dp(n, vector<int>(4, 0));
//     dp[0][0] = max(Points[0][1], Points[0][2]);
//     dp[0][1] = max(Points[0][0], Points[0][2]);
//     dp[0][2] = max(Points[0][1], Points[0][0]);
//     dp[0][3] = max(Points[0][1], max(Points[0][0], Points[0][2]));
//     for (int day = 1; day < n; ++day)
//     {
//         for (int last = 0; last < 4; ++last)
//         {
//             // dp[day][last] = 0;
//             for (int task = 0; task < 3; ++task)
//             {
//                 if (task != last)
//                 {
//                     int merits = Points[day][task] + dp[day - 1][task];
//                     dp[day][last] = max(dp[day][last], merits);
//                 }
//             }
//         }
//     }
//     return dp[n - 1][3];
// }

// SPACE OPTIMIZATION:
// TC -> O(N*4*3)
// SC -> O(4)
int maxMerits(int n, vector<vector<int>> &Points)
{
    vector<int> prev(4, 0);
    prev[0] = max(Points[0][1], Points[0][2]);
    prev[1] = max(Points[0][0], Points[0][2]);
    prev[2] = max(Points[0][1], Points[0][0]);
    prev[3] = max(Points[0][1], max(Points[0][0], Points[0][2]));
    for (int day = 1; day < n; ++day)
    {
        vector<int> dp(4, 0);
        for (int last = 0; last < 4; ++last)
        {
            for (int task = 0; task < 3; ++task)
            {
                if (task != last)
                {
                    int merits = Points[day][task] + prev[task];
                    dp[last] = max(dp[last], merits);
                }
            }
        }
        prev = dp;
    }
    return prev[3];
}
int main(void)
{
    int day = 3;
    vector<vector<int>> Points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};
    // RECURSION:
    // cout << maxMerits(day-1, 3, Points);

    // MEMOIZATION:
    // vector<vector<int>> dp(day, vector<int>(4, -1));
    // cout << maxMerits(day - 1, 3, Points, dp);

    // TABULATION:
    // cout << maxMerits(day, Points);

    // SPACE OPTIMZATION:
    cout << maxMerits(day, Points);
    return 0;
}