/*Leet code 309.
309. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
Input: prices = [1]
Output: 0

Constraints:
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solveRec(vector<int>& prices, int i, int buy)
    {
        if(i >= prices.size()) return 0;
        int profit = 0;
        
        if(buy)
        {                     //-Buy        //Sell
            int buyItProfit = -prices[i] + solveRec(prices, i+1, 0);
                                //Buy in future, not today
            int ignoreProfit =  solveRec(prices, i+1, 1);
            profit = max(buyItProfit, ignoreProfit);
        }
        else //sell
        {                      //+Sell      //Bought it before (-Buy)
            //i+2 -> as 1 day is a cooldown day.
            int sellItProfit = prices[i] + solveRec(prices, i+2, 1);
                                // Sell it in the future.
            int ignoreProfit =  solveRec(prices, i+1, 0);
            profit = max(sellItProfit, ignoreProfit);
        }
        return profit;
    }

    int solveMem(vector<int>& prices, int i, int buy, vector<vector<int>>&dp)
    {
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1)
        {
            return dp[i][buy];
        }

        int profit = 0;
        
        if(buy)
        {                     //-Buy        //Sell
            int buyItProfit = -prices[i] + solveMem(prices, i+1, 0, dp);
                                //Buy in future, not today
            int ignoreProfit =  solveMem(prices, i+1, 1, dp);
            profit = max(buyItProfit, ignoreProfit);
        }
        else //sell
        {                      //+Sell      //Bought it before (-Buy)
            int sellItProfit = prices[i] + solveMem(prices, i+2, 1, dp);
                                // Sell it in the future.
            int ignoreProfit =  solveMem(prices, i+1, 0, dp);
            profit = max(sellItProfit, ignoreProfit);
        }
        return dp[i][buy] = profit;
    }

    int solveTab(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));//n+2 beacuse we have 1 cooldown day.
        //Reverse
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                int profit = 0;
                if(buy)
                {                     //-Buy        //Sell
                    int buyItProfit = -prices[i] + dp[i+1][0];
                                        //Buy in future, not today
                    int ignoreProfit = dp[i+1][1];
                    profit = max(buyItProfit, ignoreProfit);
                }
                else //sell
                {                      //+Sell      //Bought it before (-Buy)
                    int sellItProfit = prices[i] + dp[i+2][1];
                                        // Sell it in the future.
                    int ignoreProfit =  dp[i+1][0];
                    profit = max(sellItProfit, ignoreProfit);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
    //S.C: O(1)
    //T.C: O(n)
    int solveTabSC(vector<int>& prices)
    {
        int n = prices.size();
        vector<int>curr(2, 0);
        vector<int>next(2,0);
        vector<int>afterCoolDown(2,0);

        //Reverse
        for(int i=n-1; i>=0; i--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                int profit = 0;
                if(buy)
                {                     //-Buy        //Sell
                    int buyItProfit = -prices[i] + next[0];
                                        //Buy in future, not today
                    int ignoreProfit = next[1];
                    profit = max(buyItProfit, ignoreProfit);
                }
                else //sell
                {                      //+Sell      //Bought it before (-Buy)
                    int sellItProfit = prices[i] + afterCoolDown[1];
                                        // Sell it in the future.
                    int ignoreProfit =  next[0];
                    profit = max(sellItProfit, ignoreProfit);
                }
                curr[buy] = profit;
            }
            afterCoolDown = next;
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        //return solveRec(prices, 0, 1);
        //2D - dp, i and buy
        //int n = prices.size();
        //vector<vector<int>> dp(n+1, vector<int>(2, -1));
        //return solveMem(prices, 0, 1, dp);
        //return solveTab(prices);
        return solveTabSC(prices);
    }
};