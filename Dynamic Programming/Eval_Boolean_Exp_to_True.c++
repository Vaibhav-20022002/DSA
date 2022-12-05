// You are given an expression ‘EXP’ in the form of a string where operands will be : (TRUE and FALSE) and operators will be : (AND, OR,
// XOR). Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
// Note :
// ‘T’ will represent the operand TRUE.
// ‘F’ will represent the operand FALSE.
// ‘|’ will represent the operator OR.
// ‘&’ will represent the operator AND.
// ‘^’ will represent the operator XOR.
// Note :
// As the answer can be very large, return the output modulo 1000000007.

#define mod 1000000007
#include <iostream>
#include <vector>
using namespace std;

long long evaluateExp(int i, int j, bool isTrue, string &exp)
{
    // BASE CASE:
    // IF THE PARTITION IS NOT POSSIBLE THERE IS NO WAY TO EVALUATE THE EXPRESSION, RETURN ZERO:
    if (i > j)
        return 0;

    // IF THERE IS ONLY A SINGLE CHARACTER TO EVALUATE:
    if (i == j)
    {
        // IF TRUE IS REQUIRED:
        if (isTrue)
            // RETURN IF CHARACTER IS TRUE:
            return exp[i] == 'T';
        // ELSE RETURN FALSE:
        return exp[i] == 'F';
    }

    // MAKE A VARIABLE TO COUNT THE NUMBER OF WAYS, INTIALIZED WITH ZERO:
    long long ways = 0;

    // MAKING PARTITION ON EVERY OPERATOR, FROM i to j-1 :
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        // COUNTING NUMBER OF WAYS IN WHICH LEFT SUBPROBLEM RETURN TRUE:
        long long leftTrue = evaluateExp(i, ind - 1, 1, exp) % mod;
        // COUNTING NUMBER OF WAYS IN WHICH RIGHT SUBPROBLEM RETURN TRUE:
        long long rightTrue = evaluateExp(ind + 1, j, 1, exp) % mod;
        // COUNTING NUMBER OF WAYS IN WHICH LEFT SUBPROBLEM RETURN FALSE:
        long long leftFalse = evaluateExp(1, ind - 1, 0, exp) % mod;
        // COUNTING NUMBER OF WAYS IN WHICH RIGHT SUBPROBLEM RETURN FALSE:
        long long rightFalse = evaluateExp(ind + 1, j, 0, exp) % mod;

        // IF THE CHARACTER IS '&':
        if (exp[ind] == '&')
        {
            // SUBPROBLEM CAN BE MADE TRUE ONLY IF BOTH LEFT AND RIGHT SUBPROBLEM ON '&' ARE TRUE:
            if (isTrue)
                ways = (ways + (leftTrue * rightTrue) % mod) % mod;
            // SUBPROBLEM CAN BE MADE FALSE IF LEFT SUBPROBLEM IS FALSE OR RIGHT SUBPROBLEM IS FALSE:
            else
                ways = (ways + (leftFalse * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightFalse) % mod) % mod;
        }
        // IF THE CHARACTER IS '|':
        else if (exp[ind] == '|')
        {
            // SUBPROBLEM CAN BE MADE TRUE IF ONE OF THE LEFT OR RIGHT SUBPROBLEM IS TRUE OR BOTH ARE TRUE:
            if (isTrue)
                ways = (ways + (leftTrue * rightTrue) % mod + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            // SUBPROBLEM CAN BE MADE FALSE ONLY IF BOTH LEFT AND RIGHT SUBPROBLEM ARE FALSE:
            else
                ways = (ways + (leftFalse * rightFalse) % mod) % mod;
        }
        // IF CHARACTER IS '^':
        else
        {
            // SUBPROBLEM CAN BE MADE TRUE IF LEFT SUBPROBLEM IS TRUE AND RIGHT SUBPROBLEM IS FALSE OR VICE VERSA:
            if (isTrue)
                ways = (ways + (leftTrue * rightFalse) % mod + (leftFalse * rightTrue) % mod) % mod;
            // SUBPROBLEM CAN BE MADE FALSE IF BOTH LEFT AND RIGHT SUBPROBLEM ARE FALSE OR BOTH ARE TRUE:
            else
                ways = (ways + (leftTrue * rightTrue) % mod + (leftFalse * rightFalse) % mod) % mod;
        }
    }
    // RETURN THE NUMBER OF WAYS :
    return ways;
}

int main(void)
{
    string exp = "F|T^F";
    int n = exp.size();

    // RECURSION:
    cout << evaluateExp(0, n - 1, 1, exp);
    return 0;
}