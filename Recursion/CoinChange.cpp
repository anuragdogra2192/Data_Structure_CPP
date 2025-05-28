/* Leet code 322.
322. Coin Change
You are given an integer array coins representing
coins of different denominations and an integer amount representing a total amount of money.

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
//Currently used only recursion which leads to TLE
// But this will be improved with DP.

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
                //if coin < amount ,call recursion
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
        }
    
        int coinChange(vector<int>& coins, int amount) {
            int ans = solve(coins, amount);
            if (ans == INT_MAX)
            {
                return -1;
            }
            return ans;
        }
    };

//Time complexity: O(N^Amount) -- Exponential 
