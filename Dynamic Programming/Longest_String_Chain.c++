// You are given an array ‘ARR’ of strings, where each string consists of English lowercase letters.
// Let’s say a string ‘A’ is a predecessor of string ‘B’ if and only if we can add exactly one letter anywhere in ‘A’ to make it equal
// to ‘B’. For example “abd” is a predecessor of “abcd”, we can add “c” in “abd” to make a string “abcd”
// A string chain is a sequence of strings where for every ‘i’ in [1 . . . (K - 1)], ‘Si’ is the predecessor of ‘Si+1’. And the length
// of such a string chain is ‘K’.
// Now your task is to find the length of the longest possible string chain.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkPossible(string &s1, string &s2)
{
    // GETTING SIZES OF BOTH STRINGS:
    int n1 = s1.size();
    int n2 = s2.size();

    // IF THE DIFFERENCE BETWEEN BOTH THE STRINGS IS NOT 1, RETURN FALSE:
    if (n1 != n2 + 1)
        return false;

    // MAKE TWO POINTERS POINTING AT THE START OF BOTH STRINGS:
    int first = 0, second = 0;

    // TRAVERSE TILL FIRST STRING GETS EXHAUSTED:
    while (first < n1)
    {
        // IF BOTH THE STRING's CORRESPONDING CHARACTERS ARE MATCHING, INCREMENT BOTH's POINTERS BY 1:
        if (s1[first] == s2[second])
        {
            ++first;
            ++second;
        }
        // IF NOT MATCHING INCREMENT THE FIRST STRING's POINTER:
        else
            ++first;
    }

    // IF BOTH POINTERS REACHES THE END OF THEIR RESPECTIVE STRINGS, RETURN TRUE OTHERWISE FALSE:
    if (first == n1 && second == n2)
        return true;
    return false;
}

bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int longestStrChain(vector<string> &arr, int n)
{
    // AS WE REQUIRE A SUBSET, SO THEREFORE NO ORDER IS REQUIRED, BUT FOR USING LONGEST INCREASING SUBSEQUENCE WE'VE TO SORT
    // THE ARRAY ACCORDING TO THE SIZE OF STRING IN THE INCREASING ORDER !!!
    sort(arr.begin(), arr.end(), comp);

    // CREATING A DP VECTOR FOR STORING LIS, WHERE DP[i] SIGNIFIES MAXIMUM LENGTH OF LIS TILL 'i', INITIALIZED WITH '1' AS
    // MAXIMUM LENGTH OF LIS FOR EVERY ELEMENT IS THE ELEMENT ITSELF IE.; '1':
    vector<int> dp(n, 1);

    // MAKING A VARIABLE FOR STORING MAXIMUM AMONG ALL dp[i]'s :
    int maxx = 1;

    // TRAVERSING THE ARRAY:
    for (int ind = 0; ind < n; ++ind)
    {
        // TRAVERSING THE ARRAY BACK TILL ind - 1 FOR COMPUTING THE LIS:
        for (int prev_ind = 0; prev_ind < ind; ++prev_ind)
            // CHECK IF THERE IS A POSSIBLITY OF MAKING STRING 'i' BY ADDING A CHARACTER IN 'prev' STRING, RETURN true OR false:
            if (checkPossible(arr[ind], arr[prev_ind]) && 1 + dp[prev_ind] > dp[ind])
                dp[ind] = 1 + dp[prev_ind];
        // AFTER EVERY COMPUTION FOR dp[ind], UPDATE THE maxx :
        maxx = max(maxx, dp[ind]);
    }

    // RETURN THE MAXIMUM LENGTH OF LIS:
    return maxx;
}
int main(void)
{
    vector<string> arr = {"a", "bc", "ad", "adc", "bcd"};
    int n = arr.size();

    // CAN BE SOLVED BY LONGEST INCREASING SUBSEQUENCE BY ADDING ONE CONDITION THAT CHECK FOR THE POSSIBILITY OF MAKING STRING SAME
    // BY ADDING ONE CHARACTER !!!

    cout << longestStrChain(arr, n);
    return 0;
}