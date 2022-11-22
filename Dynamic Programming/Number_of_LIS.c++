// Given an integer array ‘ARR’ of length ‘N’, return the number of longest increasing subsequences in it.
// The longest increasing subsequence(LIS) is the longest subsequence of the given sequence such that all elements of the subsequence
// are in increasing order.
// Note :
// The subsequence should be a strictly increasing sequence.

#include <iostream>
#include <vector>
using namespace std;

int findNumberOfLIS(vector<int> &arr, int n)
{
    // CREATING A DP VECTOR FOR STORING LIS, WHERE DP[i] SIGNIFIES MAXIMUM LENGTH OF LIS TILL 'i', INITIALIZED WITH '1' AS
    // MAXIMUM LENGTH OF LIS FOR EVERY ELEMENT IS THE ELEMENT ITSELF IE.; '1':
    vector<int> dp(n, 1);

    // CREATING A count ARRAY FOR KEEPING COUNT OF NUMBER OF LIS :
    vector<int> count(n, 1);

    // MAKING A VARIABLE FOR STORING MAXIMUM AMONG ALL dp[i]'s :
    int maxx = 1;

    // TRAVERSING THE ARRAY:
    for (int ind = 0; ind < n; ++ind)
    {
        // TRAVERSING THE ARRAY BACK TILL ind - 1 FOR COMPUTING THE LIS:
        for (int prev_ind = 0; prev_ind < ind; ++prev_ind)
        {
            // IF ANY PREVIOUS ELEMENT IS LESSER THAN ind's ELEMENT, ADD ONTO THE DP AND THE COUNT REMAINS SAME AS PREVIOUS:
            if (arr[prev_ind] < arr[ind] && 1 + dp[prev_ind] > dp[ind])
            {
                dp[ind] = 1 + dp[prev_ind];
                count[ind] = count[prev_ind];
            }
            // IF PREVIOUS LENGTH OF LIS IS SAME AS OF CURRENT ONE, ADD IT TO THE COUNT OF CURRENT INDEX:
            else if (arr[ind] > arr[prev_ind] && 1 + dp[prev_ind] == dp[ind])
                count[ind] += count[prev_ind];
        }

        // AFTER EVERY COMPUTION FOR dp[i], UPDATE THE maxx :
        maxx = max(maxx, dp[ind]);
    }

    // CALCULATE NUMBER OF LIS FROM THE COUNT ARRAY AND RETURN :
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (dp[i] == maxx)
            cnt += count[i];
    return cnt;
}
int main(void)
{
    vector<int> arr = {50, 3, 90, 60, 80};
    int n = arr.size();

    // CAN BE SOLVED USING LONGEST INCREASING SUBSEQUENCE BY KEEPING COUNT ARRAY THAT KEEPS COUNT OF NUMBER OF LIS !!!

    cout << findNumberOfLIS(arr, n);
    return 0;
}