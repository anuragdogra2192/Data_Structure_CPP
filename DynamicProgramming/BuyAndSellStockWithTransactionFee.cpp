/* Leet code 714.

714. Best Time to Buy and Sell Stock with Transaction Fee

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

Constraints:
1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solveRec(vector<int>& prices, int i, int buy, int fee)
    {
        if(i >= prices.size()) return 0;
        int profit = 0;
        
        if(buy)
        {                     //-Buy        //Sell
            int buyItProfit = -prices[i] + solveRec(prices, i+1, 0, fee);
                                //Buy in future, not today
            int ignoreProfit =  solveRec(prices, i+1, 1, fee);
            profit = max(buyItProfit, ignoreProfit);
        }
        else //sell
        {                      //+Sell      //Bought it before (-Buy)
            int sellItProfit = prices[i] + solveRec(prices, i+1, 1, fee) - fee; //One Transaction completed.
                                // Sell it in the future.
            int ignoreProfit =  solveRec(prices, i+1, 0, fee);
            profit = max(sellItProfit, ignoreProfit);
        }
        return profit;
    }

    int solveMem(vector<int>& prices, int i, int buy, vector<vector<int>>&dp, int fee)
    {
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1)
        {
            return dp[i][buy];
        }

        int profit = 0;
        
        if(buy)
        {                     //-Buy        //Sell
            int buyItProfit = -prices[i] + solveMem(prices, i+1, 0, dp, fee);
                                //Buy in future, not today
            int ignoreProfit =  solveMem(prices, i+1, 1, dp, fee);
            profit = max(buyItProfit, ignoreProfit);
        }
        else //sell
        {                      //+Sell      //Bought it before (-Buy)
            int sellItProfit = prices[i] + solveMem(prices, i+1, 1, dp, fee) - fee; //1 transaction
                                // Sell it in the future.
            int ignoreProfit =  solveMem(prices, i+1, 0, dp, fee);
            profit = max(sellItProfit, ignoreProfit);
        }
        return dp[i][buy] = profit;
    }

    int solveTab(vector<int>& prices, int fee)
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
                    int sellItProfit = prices[i] + dp[i+1][1] - fee;// 1 Transaction
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
    int solveTabSC(vector<int>& prices, int fee)
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
                    int sellItProfit = prices[i] + next[1] - fee;//1 Transaction
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
    int maxProfit(vector<int>& prices, int fee) {
        //return solveRec(prices, 0, 1, fee);
        //2D - dp, i and buy
        // int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solveMem(prices, 0, 1, dp, fee);
        //return solveTab(prices, fee);
        return solveTabSC(prices, fee);
    }
};