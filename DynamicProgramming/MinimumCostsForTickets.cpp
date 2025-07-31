/* Leet code 983.
983. Minimum Cost For Tickets
You have planned some train traveling one year in advance. 
The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.


Example 1:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.

Example 2:
Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
 
Constraints:
1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000

T.C. O(n)
S.C. O(n)
*/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int solveRec(vector<int>& days, vector<int>& costs, int i)
    {
        //base case
        if(i >= days.size())
        {
            return 0;
        }
        //1K case mein, baaki recursion 
        //For 1 day pass
        int cost1 = costs[0] + solveRec(days, costs, i+1);
        //For 7 days pass
        int passEndDay = days[i] + 7 - 1;
        int j = i; //we need i also for 30 days 
        while(j < days.size() && days[j] <= passEndDay)//<= passEndDay because we need to include the end day.
        {
            j++;
        }
        //At this point j is at passEndDay + 1, means we need to buy pass again
        int cost7 = costs[1] + solveRec(days, costs, j);
        
        //Similarly for 30 days pass
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost30 = costs[2] + solveRec(days, costs, j);
        int ans = min(cost1, min(cost7, cost30));
        return ans;
    }
    //Top Down
    int solveMem(vector<int>& days, vector<int>& costs, int i, vector<int>& dp)
    {
        //base case
        if(i >= days.size())
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        //1K case mein, baaki recursion 
        //For 1 day pass
        int cost1 = costs[0] + solveMem(days, costs, i+1, dp);
        //For 7 days pass
        int passEndDay = days[i] + 7 - 1;
        int j = i; //we need i also for 30 days 
        while(j < days.size() && days[j] <= passEndDay)//<= passEndDay because we need to include the end day.
        {
            j++;
        }
        //At this point j is at passEndDay + 1, means we need to buy pass again
        int cost7 = costs[1] + solveMem(days, costs, j, dp);
        
        //Similarly for 30 days pass
        passEndDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= passEndDay)
        {
            j++;
        }
        int cost30 = costs[2] + solveMem(days, costs, j, dp);
        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }

    //Bottom up 
    int solveTab(vector<int>& days, vector<int>& costs)
    {
        int n = days.size();
        vector<int>dp(n+1, 0);
        for(int i=n-1; i>=0; i--)
        {
            //For 1 day pass
            int cost1 = costs[0] + dp[i+1];
            //For 7 days pass
            int passEndDay = days[i] + 7 - 1;
            int j = i; //we need i also for 30 days 
            while(j < days.size() && days[j] <= passEndDay)//<= passEndDay because we need to include the end day.
            {
                j++;
            }
            //At this point j is at passEndDay + 1, means we need to buy pass again
            int cost7 = costs[1] + dp[j];
            
            //Similarly for 30 days pass
            passEndDay = days[i] + 30 - 1;
            j = i;
            while(j < days.size() && days[j] <= passEndDay)
            {
                j++;
            }
            int cost30 = costs[2] + dp[j];
            dp[i] = min(cost1, min(cost7, cost30));
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //return solveRec(days, costs, 0);
        //1D - dp, only i is changing.
        //int n = days.size();
        //vector<int>dp(n+1, -1);
        //return solveMem(days, costs, 0, dp);
        return solveTab(days, costs);
    }
};

