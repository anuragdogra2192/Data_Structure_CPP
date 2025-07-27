/*Leet code 509.

509. Fibonacci Number

The Fibonacci numbers, commonly denoted F(n) form a sequence,
called the Fibonacci sequence, such that each number
is the sum of the two preceding ones, starting from 0 and 1. 

That is,
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
Constraints:
0 <= n <= 30

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
//Approach - 1: only recursion
    int solveUsingRecurion(int n)
    {
        //base case
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }

        int ans = solveUsingRecurion(n-1) + solveUsingRecurion(n-2);
        return ans;
    }

    //Approach 2:
    //Top Down Approach
    //In the above function,  n is the only parameter which is changeing in the recursion.
    //1-D DP solution ->1D DP array -> n to 0 
    //memoization
    int solveUsingMem(int n, vector<int>& dp)
    {
        //base case
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }
        //Step 3: Base case ke baad, check if ans already exist or not.
        if(dp[n] != -1)
        {//matlab ans avail hai
            return dp[n];
        }

        //Step 2: dp array mein ans store karo and return karo
        dp[n] = solveUsingMem(n-1, dp) + solveUsingMem(n-2, dp);
        return dp[n];
    }

    //Approach 3:
    //Bottom up approach, Faster
    //Time Complexity: O(n), but faster than recursion
    //Space Complexity: O(n)

    int solveUsingTabulation(int n)
    {
        //step 1: create a dp array, type: 1D dp, of size (n+1)
        vector<int> dp(n+1, -1);
        //step2: analyse base cases and update dp array
        dp[0] = 0;
        if(n == 0)
        {
            return 0;
        }

        dp[1] = 1;
        //step3: check parameter and reverse it and run the loop
        //In recursion, n->0
        //Reverse, 0->n
        for(int i=2; i<=n; i++)
        {//copy paste
            dp[i] = dp[i-1] + dp[i - 2];
        }
        // answer return, always remember recursion mein kya return kiya.
        return dp[n];
    }

    //Approach 3.1:
    //Bottom up approach with space optimization
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    int solveUsingTabWithSpaceOptimization(int n)
    {
        //step 1: create a dp array, type: 1D dp, of size (n+1)
        //vector<int> dp(n+1, -1);
        //step2: analyse base cases and update dp array
        //dp[0] = 0;
        if(n == 0)
        {
            return 0;
        }
        //dp[1] = 1;
        if(n == 1)
        {
            return 1;
        }
        int prev = 0;
        int curr = 1;
        //step3: check parameter and reverse it and run the loop
        //In recursion, n->0
        //Reverse, 0->n
        for(int i=2; i<=n; i++)
        {//copy paste
            //dp[i] = dp[i-1] + dp[i - 2];
            int ans = curr + prev;
            prev = curr;
            curr = ans;
        }
        //curr ans pe hi hai.
        return curr;
    }

    int fib(int n) {
        //return solveUsingRecurion(n);
        
        // Step1: Create dp array and pass it to the function.
        //vector<int> dp(n+1, -1);
        //Top Down approach - Recursion + Memoisation
        //return solveUsingMem(n, dp);

        //Bottom up approach
        //return solveUsingTabulation(n);

        //Bottom up approach with space optimization
        return solveUsingTabWithSpaceOptimization(n);
    }
};

/*
Notes: 
1) Base case store nai hota dp mein.
2) Ek baar solve karo and store karo.
*/