/* Leet code.
1402. Reducing Dishes

A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].

Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

Example 1:
Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14).
Each dish is prepared in one unit of time.

Example 2:
Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)

Example 3:
Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People do not like the dishes. No dish is prepared.
 
Constraints:
n == satisfaction.length
1 <= n <= 500
-1000 <= satisfaction[i] <= 1000
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int solveRec(vector<int>& satisfaction, int i, int time)
    {
        //base case
        if(i == satisfaction.size()) return 0;
        //Include
        int includeLikeTimeCoeff = 0;
        includeLikeTimeCoeff = time * satisfaction[i] + solveRec(satisfaction, i+1, time+1);
        //Exclude
        int excludeLikeTimeCoeff = 0 + solveRec(satisfaction, i+1, time);// yaha galti hui thi meian time + 1 lar diya tha. 

        return max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
    }

    int solveMem(vector<int>& satisfaction, int i, int time, vector<vector<int>>& dp)
    {
        //base case
        if(i == satisfaction.size()) return 0;
        if(dp[i][time] != -1)
        {
            return dp[i][time];
        }
        //Include
        int includeLikeTimeCoeff = 0;
        includeLikeTimeCoeff = time * satisfaction[i] + solveMem(satisfaction, i+1, time+1, dp);
        //Exclude
        int excludeLikeTimeCoeff = 0 + solveMem(satisfaction, i+1, time, dp);// yaha galti hui thi meian time + 1 lar diya tha. 

        return dp[i][time] = max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
    }

    int solveTab(vector<int>& satisfaction)
    {
        int n = satisfaction.size();
        //2D - dp, i and time
        vector<vector<int>> dp(n+1, vector<int>(n+2, 0));

        for(int i = n-1; i >= 0; i--)
        {
            for(int time = n; time >= 1; time--)
            {
                //Include
                int includeLikeTimeCoeff = 0;
                includeLikeTimeCoeff = time * satisfaction[i] + dp[i+1][time+1];
                //Exclude
                int excludeLikeTimeCoeff = 0 + dp[i+1][time];// yaha galti hui thi meian time + 1 lar diya tha. 
                dp[i][time] = max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
            }
        }
        return dp[0][1];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int i = 0;
        int time = 1;
        int n = satisfaction.size();
        //return solveRec(satisfaction, i, time);
        //2D - dp, i and time
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //return solveMem(satisfaction, i, time, dp);
        return solveTab(satisfaction);
    }
};