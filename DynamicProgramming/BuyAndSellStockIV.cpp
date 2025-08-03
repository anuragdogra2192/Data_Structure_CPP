/*Leet code 188. Best Time to Buy and Sell Stock IV
188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 
Constraints:
1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
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

    int solveTab(vector<int>& prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0))); 
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int limit=1; limit<k+1; limit++)
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
        return dp[0][1][k];
    }
    
    //S.C. O(k)
    //T.C. ~O(n)
    int solveTabSC(vector<int>& prices, int k)
    {
        int n = prices.size();
        vector<vector<int> > curr(2, vector<int>(k+1, 0));
        vector<vector<int> > next(2, vector<int>(k+1, 0));   

        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int limit=1; limit<k+1; limit++)
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
        return next[1][k];
    }

    int maxProfit(int k, vector<int>& prices) {
        int i = 0;
        int buy = 1;
        int limit = k; // No. of transactions, 2 pairs of buy - Sell
        //return solveRec(prices, i, buy, k);
        //3D - dp 
        //int n = prices.size();
        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(limit+1, -1))); 
        //return solveMem(prices, i, buy, limit, dp);
        //return solveTab(prices, k);
        return solveTabSC(prices, k);
    }
};