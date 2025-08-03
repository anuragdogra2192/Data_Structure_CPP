/* Leet code 1140.
1140. Stone Game II

Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.

Alice and Bob take turns, with Alice starting first.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

Example 1:
Input: piles = [2,7,9,4,4]
Output: 10

Explanation:
If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
So we return 10 since it's larger.

Example 2:
Input: piles = [1,2,3,4,5,100]
Output: 104

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solveRec(vector<int>& piles, int i, int M, int alice)
    {
        if(i == piles.size())
        {
            return 0;
        }
        //Alice score, we need to maximize Alice score
        //Bob score, we need to minimize
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0; 
        for(int X=1; X<=2*M; X++)
        {
            //collect X piles.
            if(i+X - 1 >= piles.size()) break;
            total += piles[i+X-1];
            if(alice == 1)
                ans = max(ans, total + solveRec(piles, i+X, max(X, M), 0));
            else
            {//In bob case we minimize and also no need to have total.
                ans = min(ans, solveRec(piles, i+X, max(X, M), 1));
            }
        }
        return ans;
    }
    
    int solveMem(vector<int>& piles, int i, int M, int alice,  vector<vector<vector<int>>>& dp)
    {
        if(i == piles.size())
        {
            return 0;
        }
        if(dp[i][M][alice] != -1)
        {
            return dp[i][M][alice];
        }
        //Alice score, we need to maximize Alice score
        //Bob score, we need to minimize
        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0; 
        for(int X=1; X<=2*M; X++)
        {
            //collect X piles.
            if(i+X - 1 >= piles.size()) break;
            total += piles[i+X-1];
            if(alice == 1)
                ans = max(ans, total + solveMem(piles, i+X, max(X, M), 0, dp));
            else
            {//In bob case we minimize and also no need to have total.
                ans = min(ans, solveMem(piles, i+X, max(X, M), 1, dp));
            }
        }
        return dp[i][M][alice] = ans;
    }

    int solveTab(vector<int>& piles)
    {
        int M = 0;
        int alice = 1;
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

        for(int i=n-1; i>=0; i--)
        {
            for(int M=n; M>=1; M--)
            {
                for(int alice=0; alice<=1; alice++)
                {
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0; 
                    for(int X=1; X<=2*M; X++)
                    {
                        //collect X piles.
                        if(i+X - 1 >= piles.size()) break;
                        total += piles[i+X-1];
                        if(alice == 1)
                            ans = max(ans, total + dp[i+X][max(X, M)][0]);
                        else
                        {//In bob case we minimize and also no need to have total.
                            ans = min(ans, dp[i+X][max(X, M)][1]);
                        }
                    }
                    dp[i][M][alice] = ans;
                }
            }
        }
        return dp[0][1][1];
    }
    int stoneGameII(vector<int>& piles) {
        //int M = 1;
        //int i = 0;
        //int n = piles.size();
        //return solveRec(piles, i, M, true);
        //3D - dp 
        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        //return solveMem(piles, i, M, true, dp);
        return solveTab(piles);
    }
};