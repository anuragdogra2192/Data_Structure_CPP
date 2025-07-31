/*Leet code 279.
279. Perfect Squares

Given an integer n, return the least number of perfect square
numbers that sum to n.

A perfect square is an integer that is the 
square of an integer; 
in other words, it is the product of some integer with itself.
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

Constraints:
1 <= n <= 104
*/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int solveRec(int n)
    {
        //base case
        if(n <= 0)
        {
            return 0;
        }
        //1 case mein karunga
        int ans = INT_MAX;
        for(int i=1; i<=sqrt(n); i++)
        {
            int perfectSquare = i*i;
            //Baaki recur sambhalega
            int numOFSquares = 1 + solveRec(n-perfectSquare);
            ans = min(ans, numOFSquares);
        }
        return ans;
    }
    int solveMem(int n, vector<int>& dp)
    {
        //base case
        if(n == 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        //1 case mein karunga
        int ans = INT_MAX;
        for(int i=1; i<=sqrt(n); i++)
        {
            int perfectSquare = i*i;
            //Baaki recur sambhalega
            int numOFSquares = 1 + solveMem(n-perfectSquare, dp);
            ans = min(ans, numOFSquares);
        }
        dp[n] = ans;
        return dp[n];
    }
    //T.C. O(n*sqrt(n))
    int solveTab(int n)
    {
        vector<int> dp(n+1, 0);
        //Analyzing the base case
        //dp[0] = 0;
        //Recur n->0 
        //Reverse 0->n
        for(int i = 1; i<=n; i++)
        {
            int ans = INT_MAX;
            for(int j=1; j<=sqrt(i); j++)
            {
                int perfectSquare = j*j;
                //Baaki recur sambhalega
                int numOFSquares = 1 + dp[i-perfectSquare];
                ans = min(ans, numOFSquares);
            }
            dp[i] = ans;
        }
        return dp[n];
    }

    int numSquares(int n) {
        //return solveRec(n);
        //1D dp, only n is changing
        //vector<int> dp(n+1, -1);
        //return solveMem(n, dp);
        return solveTab(n);
    }
};