/* Leet code 123. Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 
Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solveRec(vector<int>& prices, int i, int buy, int limit)
    {
        if(i == prices.size())
        {
            return 0;
        }
        if(limit == 0) return 0;

        int profit = 0;

        if(buy)
        {                     //-Buy
            int buyItProfit = -prices[i] + solveRec(prices, i+1, 0, limit);
            int ignoreProfit = solveRec(prices, i+1, 1, limit);
            profit = max(buyItProfit, ignoreProfit);
        }
        else//sell
        {                      //Sell
            int sellItProfit = prices[i] + solveRec(prices, i+1, 1, limit-1);
            int ignoreProfit = solveRec(prices, i+1, 0, limit);
            profit = max(sellItProfit, ignoreProfit);
        }
        return profit;
    }

    int solveMem(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int>>>& dp)
    {
        if(i == prices.size())
        {
            return 0;
        }
        if(limit == 0) return 0;

        if(dp[i][buy][limit] != -1)
        {
            return dp[i][buy][limit];
        }

        int profit = 0;

        if(buy)
        {                     //-Buy
            int buyItProfit = -prices[i] + solveMem(prices, i+1, 0, limit, dp);
            int ignoreProfit = solveMem(prices, i+1, 1, limit, dp);
            profit = max(buyItProfit, ignoreProfit);
        }
        else//sell
        {                      //Sell
            int sellItProfit = prices[i] + solveMem(prices, i+1, 1, limit-1, dp);
            int ignoreProfit = solveMem(prices, i+1, 0, limit, dp);
            profit = max(sellItProfit, ignoreProfit);
        }
        return dp[i][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0))); 
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int limit=1; limit<3; limit++)
                {
                    int profit = 0;
                    if(buy)
                    {                     //-Buy
                        int buyItProfit = -prices[i] + dp[i+1][0][limit];
                        int ignoreProfit = dp[i+1][1][limit];
                        profit = max(buyItProfit, ignoreProfit);
                    }
                    else//sell
                    {                      //Sell
                        int sellItProfit = prices[i] + dp[i+1][1][limit-1];//limit-1 can be go -ve if start from 
                        int ignoreProfit = dp[i+1][0][limit];
                        profit = max(sellItProfit, ignoreProfit); 
                    }
                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
    
    //S.C. O(2)
    //T.C. ~O(n)
    int solveTabSC(vector<int>& prices)
    {
        int n = prices.size();
        int limit = 2;
        vector<vector<int> > curr(2, vector<int>(limit+1, 0));
        vector<vector<int> > next(2, vector<int>(limit+1, 0));   

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int limit=1; limit<3; limit++)
                {
                    int profit = 0;
                    if(buy)
                    {                     //-Buy
                        int buyItProfit = -prices[i] + next[0][limit];
                        int ignoreProfit = next[1][limit];
                        profit = max(buyItProfit, ignoreProfit);
                    }
                    else//sell
                    {                      //Sell
                        int sellItProfit = prices[i] + next[1][limit-1];//limit-1 can be go -ve if start from 
                        int ignoreProfit = next[0][limit];
                        profit = max(sellItProfit, ignoreProfit); 
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;           
        }
        return next[1][2];
    }

    int maxProfit(vector<int>& prices) {
        int i = 0;
        int buy = 1;
        int limit = 2; // No. of transactions, 2 pairs of buy - Sell
        //return solveRec(prices, i, buy, limit);
        //3D - dp 
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(limit+1, -1))); 
        //return solveMem(prices, i, buy, limit, dp);
        //return solveTab(prices);
        return solveTabSC(prices);
    }
};