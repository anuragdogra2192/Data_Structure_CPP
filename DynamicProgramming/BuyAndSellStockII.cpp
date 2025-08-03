/* Leet code 122.
122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

Constraints:
1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
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
            int sellItProfit = prices[i] + solveRec(prices, i+1, 1);
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
            int sellItProfit = prices[i] + solveMem(prices, i+1, 1, dp);
                                // Sell it in the future.
            int ignoreProfit =  solveMem(prices, i+1, 0, dp);
            profit = max(sellItProfit, ignoreProfit);
        }
        return dp[i][buy] = profit;
    }

    int solveTab(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
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
                    int sellItProfit = prices[i] + dp[i+1][1];
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
                    int sellItProfit = prices[i] + next[1];
                                        // Sell it in the future.
                    int ignoreProfit =  next[0];
                    profit = max(sellItProfit, ignoreProfit);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        //return solveRec(prices, 0, 1);
        //2D - dp, i and buy
        // int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solveMem(prices, 0, 1, dp);
        //return solveTab(prices);
        return solveTabSC(prices);
    }
};