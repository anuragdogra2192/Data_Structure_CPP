/* Geeks for geeks
Painting the Fence
https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more than two consecutive posts have the same colours.
Answers are guaranteed to be fit into a 32 bit integer.

Examples:

Input: n = 3, k = 2 
Output: 6
Explanation: Let the 2 colours be 'R' and 'B'. We have following possible combinations:
1. RRB
2. RBR
3. RBB
4. BRR
5. BRB
6. BBR
Input: n = 2, k = 4 
Output: 16
Explanation: After coloring first post with 4 possible combinations, you can still color next posts with all 4 colors. Total possible combinations will be 4x4=16
Constraints:
1 ≤ n ≤ 300
1 ≤ k ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int getPaintingWays(int n, int k)
    {
        //base case
        if(n==1)
        {
            return k;
        }
        if(n==2)
        {//       same  diff
            return (k + k*(k-1));
        }
        
        //1K case mein karunga 
        int ans = (k-1)*(getPaintingWays((n-2), k) + getPaintingWays((n-1), k));
        
        return ans;
    }
    //Top down approach, 1D - dp
    int getPaintingWaysMem(int n, int k, vector<int>& dp)
    {
        //base case
        if(n==1)
        {
            return k;
        }
        if(n==2)
        {//        same  diff
            return (k + k*(k-1));
        }
        //Step3: check karo ki ans already hai ya nahi
        if(dp[n] != -1)
        {
            return dp[n];
        }
        
        //1K case mein karunga 
        //Step 2: ans stor dp mein karo and return
        dp[n] = (k-1)*(getPaintingWaysMem((n-2), k, dp) + getPaintingWaysMem((n-1), k, dp));//yaha glati karta huin funtion name update. 
        
        return dp[n];
    }
    
    int getPaintingWaysTab(int n, int k)
    {
        //Step 1: Create a 1D dp
        vector<int> dp(n+1, 0);
        //Step2: Analyze the base case of recur approach
        dp[1] = k;
        dp[2] = k + k*(k-1);
        //Step3:
        //Recur: n, n-->1
        //Reverse: n, 2-->n
        for(int i=3; i<=n; i++)
        {
            //n ki jagah i likna bhul jate hai, dp[n] -> dp[i]
            dp[i] = (k-1)*(dp[i-2] + dp[i-1]);
        }
        return dp[n]; 
    }
    
    int getPaintingWaysTabSpaceOptimize(int n, int k)
    {
        //Step2: Analyze the base case of recur approach
        int prev2 = k;//n-2
        int prev1 = k + k*(k-1);//n-1
        
        if(n==1)//yeah bhul jate hai
        {
            return prev2;
        }
        if(n==2)//yeah bhul jate hai 
        {
            return prev1;
        }
     
        //Step3:
        //Recur: n, n-->1
        //Reverse: n, 2-->n
        for(int i=3; i<=n; i++)
        {
            //n ki jagah i likna bhul jate hai, dp[n] -> dp[i]
            int curr = (k-1)*(prev2 + prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1; 
    }
    
    int countWays(int n, int k) {
        // code here
        //int ans = getPaintingWays(n,k);
        //1D dp, ans only n is changing
        //step 1:
        //vector<int> dp(n+1, -1);
        //int ans = getPaintingWaysMem(n, k, dp);
        //int ans = getPaintingWaysTab(n, k);
        int ans = getPaintingWaysTabSpaceOptimize(n, k);
        return ans;
    }
};