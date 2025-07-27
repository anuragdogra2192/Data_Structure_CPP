/* 322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int solve(vector<int>& coins, int amount)
    {   
        //Base Case:
        if(amount == 0)
        {
            return 0;
        }
        int minCoinsAns = INT_MAX;
        //Haar Amount ke liye coins wale poore array ko 
        //Traverse karenge.
        for(int i=0; i<coins.size(); i++)
        {
            int coin = coins[i];
            //if coin > amount then no need to call recursion
            //if coin < amount ,call recurshion
            if(coin <= amount)
            {   //1 coin is already used of coin[i] type
                //Therefore "amount - coin" must be passed to recursion 
                //Baaki recursion sambhal lega
                int recurAns = solve(coins, amount-coin);
                //recurAns is valid or invalid
                //Invalid if recurAns == INT_MAX;
                //Valid if recurAns != INT_MAX;
                if(recurAns != INT_MAX)
                {
                    int coinUsed = 1 + recurAns;
                            //One coin already used  + recurAns
                    //Kya above coinUsed minimun hai
                    minCoinsAns = min(coinUsed, minCoinsAns);
                }
            }

        }
        return minCoinsAns;// We have to return it to comapre with other recursive calls
                           // which has been called.
    }// 1 D dp, as only the amount is changing.

    int solveMem(vector<int>& coins, int amount, vector<int>& dp)
    {   
        //Base Case:
        if(amount == 0)
        {
            return 0;
        }
        //step 3: check if ans already exists.
        if(dp[amount] != -1)
        {
            return dp[amount];
        }

        int minCoinsAns = INT_MAX;
        //Haar Amount ke liye coins wale poore array ko 
        //Traverse karenge.
        for(int i=0; i<coins.size(); i++)
        {
            int coin = coins[i];
            //if coin > amount then no need to call recursion
            //if coin < amount ,call recurshion
            if(coin <= amount)
            {   //1 coin is already used of coin[i] type
                //Therefore "amount - coin" must be passed to recursion 
                //Baaki recursion sambhal lega
                int recurAns = solveMem(coins, amount-coin, dp);
                //recurAns is valid or invalid
                //Invalid if recurAns == INT_MAX;
                //Valid if recurAns != INT_MAX;
                if(recurAns != INT_MAX)
                {
                    int coinUsed = 1 + recurAns;
                            //One coin already used  + recurAns
                    //Kya above coinUsed minimun hai
                    minCoinsAns = min(coinUsed, minCoinsAns);
                }
            }

        }
        //step 2 mein aap we store the ans to the dp and return
        dp[amount] = minCoinsAns;
        return dp[amount];// We have to return it to comapre with other recursive calls
                           // which has been called.
    }

    //Bottom up dp, Time complexity- O(amount*coins)
    int solveUsingTab(vector<int>& coins, int amount)
    {
        //step 1: Create the dp
        vector<int> dp(amount+1, -1);

        //Base case Anaysis
        dp[0] = 0;
        //Recur - amount --> 0
        //Reverse - 0 ---> amount
        //0 wala case solve kiy ahua hai toh start with 1.
        for(int amt = 1; amt<=amount; amt++)
        {   
            //logix
            int minCoinsAns = INT_MAX;
            //Haar Amount ke liye coins wale poore array ko 
            //Traverse karenge.
            for(int i=0; i<coins.size(); i++)
            {
                int coin = coins[i];
                //if coin > amount then no need to call recursion
                //if coin < amount ,call recurshion
                if(coin <= amt)
                {   //1 coin is already used of coin[i] type
                    //Therefore "amount - coin" must be passed to recursion 
                    //Baaki recursion sambhal lega
                    int recurAns = dp[amt-coin];
                    //recurAns is valid or invalid
                    //Invalid if recurAns == INT_MAX;
                    //Valid if recurAns != INT_MAX;
                    if(recurAns != INT_MAX)
                    {
                        int coinUsed = 1 + recurAns;
                        //One coin already used  + recurAns
                        //Kya above coinUsed minimun hai
                        minCoinsAns = min(coinUsed, minCoinsAns);
                    }
                }
            }
            //step 2 mein aap we store the ans to the dp and return
            dp[amt] = minCoinsAns;
        }
        return dp[amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        //int ans = solve(coins, amount);
        //step 1: Create the dp
        vector<int> dp(amount+1, -1);
        //int ans = solveMem(coins, amount, dp);

        int ans = solveUsingTab(coins, amount);      //No space optimization possible.
        //Below code is important.
        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};