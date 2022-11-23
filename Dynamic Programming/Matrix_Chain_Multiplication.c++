// Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices. The cost of matrix
// multiplication is defined as the number of scalar multiplications. A Chain of matrices A1, A2, A3,.....An is represented by a sequence
// of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.
// For example:
// For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

// Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.

#include <iostream>
#include <vector>
using namespace std;

// RECURSION:
// TC -> O(exp)
// SC -> O(n) => AUXILIARY STACK SPACE EQUALS TO THE LENGTH OF THE ARRAY
// int matrixMultiplication(int i, int j, vector<int> &arr)
// {
//     // BASE CASE :
//     // IF i & j BECOMES EQUALS, IT MEANS THERE IS A SINGLE MATRIX, SO NUMBER OF MULTIPLICATION IS ZERO:
//     if (i == j)
//         return 0;

//     // TAKE A VARIABLE TO STORE THE MINIMUM AMONG ALL. ASSIGN IT THE MAXIMUM VALUE POSSIBLE:
//     int minn = 1e8;

//     // RUNNING A PARTITION LOOP FROM i to j-1 :
//     for (int k = i; k < j; ++k)
//     {
//         // CALCULATE NUMBER OF MULTIPLICATION BY MULTIPLYING arr[i - 1], arr[k] & arr[j]:
//         int multiplications = arr[i - 1] * arr[k] * arr[j] + matrixMultiplication(i, k, arr) + matrixMultiplication(k + 1, j, arr);
//         // UPDATE THE minn:
//         minn = min(minn, multiplications);
//     }

//     // RETURN THE MINIMUM MULTIPLICATIONS:
//     return minn;
// }

// MEMOIZATION:
// TC -> O(n * n * n) => CALLS FOR i & j AND A PARTITION LOOP EMBEDDED
// SC -> O(n * n) + O(n) => DP MATRIX + AUXILIARY STACK SPACE
// int matrixMultiplication(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
// {
//     // BASE CASE :
//     // IF i & j BECOMES EQUALS, IT MEANS THERE IS A SINGLE MATRIX, SO NUMBER OF MULTIPLICATION IS ZERO:
//     if (i == j)
//         return 0;

//     // IF THE RECURSION CALL FOR PARTICULAR <i, j> IS PRECOMPUTED, RETURN THAT STORED VALUE:
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     // TAKE A VARIABLE TO STORE THE MINIMUM AMONG ALL. ASSIGN IT THE MAXIMUM VALUE POSSIBLE:
//     int minn = 1e8;

//     // RUNNING A PARTITION LOOP FROM i to j-1 :
//     for (int k = i; k < j; ++k)
//     {
//         // CALCULATE NUMBER OF MULTIPLICATION BY MULTIPLYING arr[i - 1], arr[k] & arr[j]:
//         int multiplications = arr[i - 1] * arr[k] * arr[j] + matrixMultiplication(i, k, arr, dp) + matrixMultiplication(k + 1, j, arr, dp);
//         // UPDATE THE minn:
//         minn = min(minn, multiplications);
//     }

//     // RETURN THE MINIMUM MULTIPLICATIONS:
//     return dp[i][j] = minn;
// }

// TABULATION:
// TC -> O(n * n * n) => CALLS FOR i & j AND A PARTITION LOOP EMBEDDED
// SC -> O(n * n) => TABULATION MATRIX
int matrixMultiplication(vector<int> &arr, int n)
{
    // CREATING A TABULATION MATRIX OF SIZE (n * n) :
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // NOT REQUIRED AS ALREADY ALL CELLS ARE ZEROS:
    // BASE CASE :
    // IF i & j BECOMES EQUALS, IT MEANS THERE IS A SINGLE MATRIX, SO NUMBER OF MULTIPLICATION IS ZERO:
    // for (int i = 0; i < n; ++i)
    // dp[i][i] = 0;

    for (int i = n - 1; i > 0; --i)
    {
        // THE BASE CASE WAS i == j, HENCE j CAN'T GO TO THE LEFT OF i, SO j WILL BE STARTING FROM 'i + 1' (AS i == j IS ALREADY COMPUTED) :
        for (int j = i + 1; j < n; ++j) 
        {
            // TAKE A VARIABLE TO STORE THE MINIMUM AMONG ALL. ASSIGN IT THE MAXIMUM VALUE POSSIBLE:
            int minn = 1e8;

            // RUNNING A PARTITION LOOP FROM i to j-1 :
            for (int k = i; k < j; ++k)
            {
                // CALCULATE NUMBER OF MULTIPLICATION BY MULTIPLYING arr[i - 1], arr[k] & arr[j]:
                int multiplications = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                // UPDATE THE minn:
                if (minn > multiplications)
                    minn = multiplications;
            }

            // RETURN THE MINIMUM MULTIPLICATIONS:
            dp[i][j] = minn;
        }
    }

    // RTEURN THE LAST COMPUTED CALL:
    return dp[1][n - 1];
}
int main(void)
{
    vector<int> arr = {10, 15, 20, 25};
    int n = arr.size();

    // RECURSION:
    // cout << matrixMultiplication(1, n - 1, arr);

    // MEMOIZATION:
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout << matrixMultiplication(1, n - 1, arr, dp);

    // TABULATION:
    cout << matrixMultiplication(arr, n);
    return 0;
}