// HERE IS ONLY THE 'SPACE OPTIMIZED SOLUTION', AS OTHER ONES ARE CODED IN "House_Robber" PROBLEM !!!

// A thief needs to rob money in a street. The houses in the street are arranged in a circular manner. Therefore the first and the last
// house are adjacent to each other. The security system in the street is such that if adjacent houses are robbed, the police will get
// notified.
// Given an array of integers “Arr” which represents money at each house, we need to return the maximum amount of money that the thief
// can rob without alerting the police.

#include <iostream>
#include <vector>
using namespace std;
int maxMoney(vector<int> &arr)
{
    int n = arr.size();
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int nonPick = 0 + prev;

        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }
    return prev;
}
long House_Robber(vector<int> &arr, int n)
{
    vector<int> exc_first, exc_last;
    for (int i = 0; i < n; ++i)
    {
        if (i != 0)
            exc_first.emplace_back(arr[i]);
        if (i != n - 1)
            exc_last.emplace_back(arr[i]);
    }
    return max(maxMoney(exc_last), maxMoney(exc_first));
}
int main(void)
{
    vector<int> arr = {0};
    int n = arr.size();
    cout << "MAXIMUM MONEY ROBBED " << House_Robber(arr, n);
    return 0;
}