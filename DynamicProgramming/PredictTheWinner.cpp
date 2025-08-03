/*Leet code 486.

486. Predict the Winner

You are given an integer array nums. 
Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.

Example 1:
Input: nums = [1,5,2]
Output: false
Explanation: Initially, player 1 can choose between 1 and 2. 
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
Hence, player 1 will never be the winner and you need to return false.

Example 2:
Input: nums = [1,5,233,7]
Output: true
Explanation: Player 1 first chooses 1. Then player 2 has to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 107
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solveRec(vector<int>& nums, int start, int end)
    {
        if(start == end) return nums[start];
        //diff = SP1 - SP2, increase SP1 and decrease SP2
        int diffByStart = nums[start] - solveRec(nums, start+1, end);
        int diffByEnd = nums[end] - solveRec(nums, start, end-1);
        
        //we need a max difference to win.
        return max(diffByStart, diffByEnd);
    }

    int solveMem(vector<int>& nums, int start, int end, vector<vector<int> >& dp)
    {
        if(start == end) return nums[start];
        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        //diff = SP1 - SP2, increase SP1 and decrease SP2
        int diffByStart = nums[start] - solveRec(nums, start+1, end);
        int diffByEnd = nums[end] - solveRec(nums, start, end-1);
        
        //we need a max difference to win.
        return dp[start][end] = max(diffByStart, diffByEnd);
    }
    
    int solveTab(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
        //Base case analysis
        //When Start == end, then have values, nums[start]
        for(int i=0; i<nums.size(); i++)
        {
            dp[i][i] = nums[i];
        }

        for(int start=n-1; start>=0; start--)
        {
            for(int end = start+1; end<=n-1; end++)
            {//Focus on upper diagonal, as Bottom up approach.
                //diff = SP1 - SP2, increase SP1 and decrease SP2
                int diffByStart = nums[start] - dp[start+1][end];
                int diffByEnd = nums[end] - dp[start][end-1];
                dp[start][end] = max(diffByStart, diffByEnd);
            }
        }
        return dp[0][n-1];
    }

    bool predictTheWinner(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int n = nums.size();
        //Focus on the DIFF of the scores of players.
        //Sp1 - Sp2 >= 0, PlayerI wins.
        //Sp1 - Sp2 < 0, PlayerII wins.
        //return the diff value.
        //return solveRec(nums, start, end) >=0;
        //vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        //return solveMem(nums, start, end, dp)>=0;
        return solveTab(nums)>=0;
    }
};