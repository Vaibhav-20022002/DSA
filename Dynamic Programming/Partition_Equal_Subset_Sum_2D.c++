// You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such
// that the sum of elements in both subsets is equal.

#include <iostream>
#include <vector>
using namespace std;
// RECURSION:
// TC -> O(2^(n))
// SC -> O(n) => AUXILARY STACK SPACE
// bool subset(int ind, int target, vector<int> &arr)
// {
//     // BASE CASE 1:
//     if (target == 0)
//         return true;

//     // BASE CASE 2:
//     // IF REACHED THE LAST INDEX AND THE ELEMENT IS EQUAL TO THE TARGET RETURN TRUE OTHERWISE FALSE:
//     if (ind == 0)
//         return arr[ind] == target;

//     // NOT PICK:
//     bool notPick = subset(ind - 1, target, arr);

//     // PICK:
//     // IF PICKING UP THE ELEMENT AND IS GREATER THAN THE TARGET, JUST MOVE TO NEXT INDEX (notPick):
//     bool pick = false;
//     if (arr[ind] <= target)
//         pick = subset(ind - 1, target - arr[ind], arr);

//     // RETURN EITHER pick or notPick:
//     return pick || notPick;
// }

// MEMOIZATION:
// TC -> O(n*k)
// SC -> O(n*k) + O(n) => DP MATRIX + AUXILARY STACK SPACE EQUALS TO THE ARRAY'S SIZE
// bool subset(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
// {
//     // BASE CASE 1:
//     if (target == 0)
//         return true;

//     // BASE CASE 2:
//     // IF REACHED THE LAST INDEX AND THE ELEMENT IS EQUAL TO THE TARGET RETURN TRUE OTHERWISE FALSE:
//     if (ind == 0)
//         return arr[ind] == target;

//     // IF THE RECURSION CALL FOR THE PARTICULAR <ind, target> IS ALREADY COMPUTED, RETURN IT:
//     if (dp[ind][target] != -1)
//         return dp[ind][target];

//     // NOT PICK:
//     bool notPick = subset(ind - 1, target, arr, dp);

//     // PICK:
//     // IF PICKING UP THE ELEMENT AND IS GREATER THAN THE TARGET, JUST MOVE TO NEXT INDEX (notPick):
//     bool pick = false;
//     if (arr[ind] <= target)
//         pick = subset(ind - 1, target - arr[ind], arr, dp);

//     // RETURN EITHER pick or notPick:
//     return dp[ind][target] = pick || notPick;
// }

// TABULATION:
// TC -> O(n*k)
// SC -> O(n*k)
// bool subset(int n, int k, vector<int> &arr)
// {
//     // CREATING A DP MATRIX OF SIZE <n,k+1> => 'k+1' IS DONE TO INCLUDE 'k' IN THE DP !
//     vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

//     // BASE CASE 1:
//     // FOR THE VALUE OF TARGET = 0, EVERY INDEX IS TRUE:
//     for (int i = 0; i < n; ++i)
//         dp[i][0] = true;

//     // BASE CASE 2:
//     // FOR THE FIRST INDEX, IF THE TARGET IS EQUAL TO THE ARRAY'S INDEX MARK IT TRUE:
//     dp[0][arr[0]] = true;

//     for (int ind = 1; ind < n; ++ind)
//     {
//         for (int target = 1; target <= k; ++target)
//         {
//             // NOT PICK:
//             bool notPick = dp[ind - 1][target];

//             // PICK:
//             // IF PICKING UP THE ELEMENT AND IS GREATER THAN THE TARGET, JUST MOVE TO NEXT INDEX (notPick):
//             bool pick = false;
//             if (arr[ind] <= target)
//                 pick = dp[ind - 1][target - arr[ind]];

//             // EITHER pick or notPick:
//             dp[ind][target] = pick || notPick;
//         }
//     }

//     // RETURN THE STARTING CASE OF RECURRENCE:
//     return dp[n - 1][k];
// }

// SPACE OPTMIZATION:
// TC -> O(n*k)
// SC -> O(k) => STORING PREVIOUS ROW
bool subset(int n, int k, vector<int> &arr)
{
    // CREATING A BOOL VECTOR FOR STORING PREVIOUS AND CURRENT ROW:
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);

    // BASE CASE 1:
    // FOR THE FIRST INDEX, VALUE IS ALWAYS TRUE:
    prev[0] = curr[0] = true;

    // BASE CASE 2:
    // FOR THE FIRST INDEX, IF THE TARGET IS EQUAL TO THE ARRAY'S INDEX MARK IT TRUE:
    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ++ind)
    {
        for (int target = 1; target <= k; ++target)
        {
            // NOT PICK:
            bool notPick = prev[target];

            // PICK:
            // IF PICKING UP THE ELEMENT AND IS GREATER THAN THE TARGET, JUST MOVE TO NEXT INDEX (notPick):
            bool pick = false;
            if (arr[ind] <= target)
                pick = prev[target - arr[ind]];

            // EITHER pick or notPick:
            curr[target] = pick || notPick;
        }
        prev = curr;
    }

    // RETURN THE STARTING CASE OF RECURRENCE:
    return prev[k];
}
int main(void)
{
    vector<int> arr = {8, 7, 6, 12, 4, 5};
    int n = arr.size();

    // AS WE HAVE TO PARTITION THE ARRAY INTO TWO SUBSETS HAVING EXACTLY EQUAL SUM, THEREFORE, WE'LL FIND A SINGLE SUBSET WITH THE SUM
    // HALF OF THE ARRAY !!!

    // SUMMING ALL ELEMENTS:
    int sum = 0;
    for (int it : arr)
        sum += it;

    // IF THE SUM OF THE ARRAY COMES OUT TO BE ODD THEN ITS IMPOSSIBLE TO DIVIDE THE ARRAY IN EQUAL SUBSETS SUM !!!

    if (sum % 2 != 0)
        cout << false;
    else
    {
        // RECURSION:
        // cout << subset(n - 1, sum / 2, arr);

        // MEMOIZATION:
        // CREATING A VECTOR FOR THE PARAMETERS<ind, target>::<array 's size, target' s constraint> :
        // vector<vector<int>> dp(arr.size(), vector<int>(1e7, -1));
        // cout << subset(n - 1, sum / 2, arr, dp);

        // TABULATION:
        // cout << subset(n, sum / 2, arr);

        // SPACE OPTIMZATION :
        cout << subset(n, sum / 2, arr);
    }
    return 0;
}