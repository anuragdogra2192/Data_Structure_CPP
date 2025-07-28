/* Leet Code 1155.
1155. Number of Dice Rolls With Target Sum

You have n dice, and each dice has k faces numbered from 1 to k.

Given three integers n, k, and target, return the number of possible ways (out of the kn total ways)
to roll the dice, so the sum of the face-up numbers equals target.

Since the answer may be too large, return it modulo 109 + 7.

Example 1:
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.

Constraints:
1 <= n, k <= 30
1 <= target <= 1000
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    long long int mod = 1e+9 + 7;
public:
    int solveRec(int n, int k, int target)
    {
        //base case
        if(target < 0 || n < 0)
        {
            return 0;
        }
        if(target == 0 && n==0) //zero dice and target is also zero
        {//so we can make it in one way atleast
            return 1;
        }
        if(n==0 && target!=0)//zero dice and target is there
        {
            return 0;
        }
        if(n!=0 && target==0)//zero target and n dices are there.
        {
            return 0;
        }

        //1k case mera 
        int ans = 0;
        for(int i=1; i<=k; i++)
        {   //1k dice use hongaya, thats why n-1
            //And current face bhi use hogaya toh target mein se minus.
            ans += solveRec(n-1, k, target-i);
            //and baaki recursion
        }
        return ans;
    }

    int solveMem(int n, int k, int target, vector<vector<long long int>>& dp)
    {
        //base case
        if(target < 0 || n < 0)
        {
            return 0;
        }
        if(target == 0 && n==0) //zero dice and target is also zero
        {//so we can make it in one way atleast
            return 1;
        }
        if(n==0 && target!=0)//zero dice and target is there
        {
            return 0;
        }
        if(n!=0 && target==0)//zero target and n dices are there.
        {
            return 0;
        }
        
        if(dp[n][target] != -1)
        {
            return dp[n][target];
        }
        //1k case mera 
        long long int ans = 0;
        for(int i=1; i<=k; i++)
        {   //1k dice use hongaya, thats why n-1
            //And current face bhi use hogaya toh target mein se minus.
            ans += solveMem(n-1, k, target-i, dp);
            //and baaki recursion
        }
        dp[n][target] = ans % mod;
        return dp[n][target];
    }

    int solveUsingTab(int n, int k, int target)
    {
        vector<vector<long long int>>dp(n+1, vector<long long int>(target+1, 0));
        dp[0][0] = 1;
        
        for(int N=1; N<=n; N++)
        {   
            for(int t=1; t<=target; t++)
            {
                long long int ans = 0;
                for(int i=1; i<=k; i++)
                {   //1k dice use hongaya, thats why n-1
                    //And current face bhi use hogaya toh target mein se minus.
                    long long int tempAns = 0; //important hai ye part
                    if(t-i >= 0)
                    {
                        tempAns = dp[N-1][t-i];
                    }
                    ans = ans + tempAns % mod;
                }
                dp[N][t] = ans % mod;
            }
        }
        return dp[n][target];
    }

    int solveUsingTabSpaceOptimize(int n, int k, int target)
    {
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);

        prev[0] = 1;//inital state is always maintained in prev
         
        for(int N=1; N<=n; N++)
        {   
            for(int t=1; t<=target; t++)
            {
                long long int ans = 0;
                for(int i=1; i<=k; i++)
                {   //1k dice use hongaya, thats why n-1
                    //And current face bhi use hogaya toh target mein se minus.
                    long long int tempAns = 0; //important hai ye part
                    if(t-i >= 0)
                    {
                        tempAns = prev[t-i];
                    }
                    ans = ans + tempAns % mod;
                }
                curr[t] = ans % mod;
            }
            //Shifting
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        //return solveRec(n, k, target);

        //Step1: Create a 2D - as n and target both are changing
        //vector<vector<long long int>>dp(n+1, vector<long long int>(target+1, -1));
        //return solveMem(n, k, target, dp);
        //return solveUsingTab(n, k, target);
        return solveUsingTabSpaceOptimize(n, k, target);
    }
};