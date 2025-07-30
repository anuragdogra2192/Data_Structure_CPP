/* Leet code 1049.
1049. Last Stone Weight II
//Important and really beautiful problem

You are given an array of integers stones where stones[i] 
is the weight of the ith stone.

We are playing a game with the stones. On each turn, 
we choose any two stones and smash them together. 
Suppose the stones have weights x and y with x <= y. 
The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.

Example 1:
Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
Example 2:

Input: stones = [31,26,33,21,40]
Output: 5

Constraints:
1 <= stones.length <= 30
1 <= stones[i] <= 100
*/

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
    //positive negative pattern
    int solveRec(vector<int>& stones, int i, int sum)
    {
        //base casse
        if(i == stones.size())
        {   
            if(sum < 0) return INT_MAX;//just to ignore all negetive
            //only need positive sum
            return sum;
        }
        //lets take ith stone positive
        int pos = solveRec(stones, i+1, sum + stones[i]);
        //lets take ith stone negative
        int neg = solveRec(stones, i+1, sum - stones[i]);

        return min(pos, neg);
    }
    //Top down 
    int solveMem(vector<int>& stones, int i, int sum, vector<vector<int>>& dp, int& totalSum)
    {
        //base casse
        if(i == stones.size())
        {   
            if(sum < 0) return INT_MAX;//just to ignore all negetive
            //only need positive sum
            return sum;
        }
        if(dp[i][sum + totalSum] != -1)
        {
            return dp[i][sum + totalSum];
        }

        //lets take ith stone positive
        int pos = solveMem(stones, i+1, sum + stones[i], dp, totalSum);
        //lets take ith stone negative
        int neg = solveMem(stones, i+1, sum - stones[i], dp, totalSum);
        
        //sum + totalSum to map in +ve part of number line
        dp[i][sum + totalSum] = min(pos, neg);
        
        return dp[i][sum + totalSum];
    }

    int solveTab(vector<int>& stones)
    {
        int n = stones.size();
        //as sum can be -ve and +ve so we need to map to 0 -- +ves
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n+1, vector<int>(2*totalSum + 1, 0));
        
        //base case analysis
        //sum ranges from -totalSum to totalSum
        for(int sum=-totalSum; sum<=totalSum; sum++)
        {   
            dp[n][sum + totalSum] = sum < 0 ? INT_MAX : sum; 
        }
        //Reverse 
        for(int i = n-1; i>=0; i--)
        {
            for(int j = totalSum; j >= -totalSum; j--)
            {
                int pos = INT_MAX; 
                int neg = INT_MAX;

                if(j + stones[i] <= totalSum)
                {
                    ///lets take ith stone positive
                    pos = dp[i+1][totalSum + j + stones[i]];
                }
                if(j - stones[i] >= -totalSum)
                {
                    //lets take ith stone negative
                    neg = dp[i+1][totalSum + j - stones[i]];    
                }
                //sum + totalSum to map in +ve part of number line
                dp[i][j + totalSum] = min(pos, neg);
            }
        }
        //0 is mapped to totalSum
        return dp[0][totalSum];
    }
    
    int solveTabSC(vector<int>& stones)
    {
        int n = stones.size();
        //as sum can be -ve and +ve so we need to map to 0 -- +ves
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> curr (2*totalSum + 1, 0);
        vector<int> next (2*totalSum + 1, 0);
        
        //base case analysis
        //sum ranges from -totalSum to totalSum
        for(int sum=-totalSum; sum<=totalSum; sum++)
        {   
            next[sum + totalSum] = sum < 0 ? INT_MAX : sum; 
        }
        //Reverse 
        for(int i = n-1; i>=0; i--)
        {
            for(int j = totalSum; j >= -totalSum; j--)
            {
                int pos = INT_MAX; 
                int neg = INT_MAX;

                if(j + stones[i] <= totalSum)
                {
                    ///lets take ith stone positive
                    pos = next[totalSum + j + stones[i]];
                }
                if(j - stones[i] >= -totalSum)
                {
                    //lets take ith stone negative
                    neg = next[totalSum + j - stones[i]];    
                }
                //sum + totalSum to map in +ve part of number line
                curr[j + totalSum] = min(pos, neg);
            }
            //shifting
            next = curr;
        }
        //0 is mapped to totalSum
        return next[totalSum];
    }
    
    //Partition pattern.
    //sum is denoting summation of G1 stones.
    int solveRec2(vector<int>& stones, int i , int sum, int& totalSum)
    {
        //base case
        if(i == stones.size())
        {
            //the sum is done for current G1
            int g1Sum = sum;
            int g2Sum = totalSum - sum;
            return abs(g1Sum - g2Sum);
        }
        //in 1 RE case, I will try to incl the ith stone into G1 group and excl
        int incl = solveRec2(stones, i+1, sum + stones[i], totalSum);
        int excl = solveRec2(stones, i+1, sum, totalSum);
        return min(incl, excl);
    }

    int solveRec2Mem(vector<int>& stones, int i , int sum, int& totalSum,vector<vector<int>>& dp)
    {
        //base case
        if(i == stones.size())
        {
            //the sum is done for current G1
            int g1Sum = sum;
            int g2Sum = totalSum - sum;
            return abs(g1Sum - g2Sum);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        //in 1 RE case, I will try to incl the ith stone into G1 group and excl
        int incl = solveRec2Mem(stones, i+1, sum + stones[i], totalSum, dp);
        int excl = solveRec2Mem(stones, i+1, sum, totalSum, dp);
        return dp[i][sum] = min(incl, excl);
    }   

    int solveTab2(vector<int>& stones, int& totalSum)
    {   
        int n = stones.size();
        vector<vector<int>> dp(n+1, vector<int>(totalSum+1, 0));
        //How g1 goup sum vary? 0 -> totalSum
        for(int i=0; i<=totalSum; i++)
        {
            int g1Sum = i;
            int g2Sum = totalSum - i;
            dp[n][i] = abs(g1Sum - g2Sum);
        }
        //Reverse
        for(int i=n-1; i>=0; i--)
        {
            for(int j=totalSum; j>=0; j--)
            {   
                int incl = INT_MAX;
                if(j + stones[i] <= totalSum)
                {
                    incl = dp[i+1][j + stones[i]];    
                }
                int excl = dp[i+1][j];
                dp[i][j] = min(incl, excl);
            }
        }
        return dp[0][0];
    }
    
    int solveTab2SC(vector<int>& stones, int& totalSum)
    {   
        int n = stones.size();

        vector<int>curr(totalSum+1, 0);
        vector<int>next(totalSum+1, 0);

        //How g1 goup sum vary? 0 -> totalSum
        for(int i=0; i<=totalSum; i++)
        {
            int g1Sum = i;
            int g2Sum = totalSum - i;
            next[i] = abs(g1Sum - g2Sum);
        }
        //Reverse
        for(int i=n-1; i>=0; i--)
        {
            for(int j=totalSum; j>=0; j--)
            {   
                int incl = INT_MAX;
                if(j + stones[i] <= totalSum)
                {
                    incl = next[j + stones[i]];    
                }
                int excl = next[j];
                curr[j] = min(incl, excl);
            }
            //shifting
            next = curr;
        }
        return next[0];
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        //as sum can be -ve and +ve so we need to map to 0 -- +ves
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        //vector<vector<int>> dp(n+1, vector<int>(2*totalSum + 1, -1));
        //return solveRec(stones, 0, 0);
        //return solveMem(stones, 0, 0, dp, totalSum);
        //return solveTab(stones);
        //return solveTabSC(stones);
        //return solveRec2(stones, 0, 0, totalSum);
        //vector<vector<int>> dp(n+1, vector<int>(totalSum+1, -1));
        //return solveRec2Mem(stones, 0, 0, totalSum, dp);
        //return solveTab2(stones, totalSum);
        return solveTab2SC(stones, totalSum);
    }
};