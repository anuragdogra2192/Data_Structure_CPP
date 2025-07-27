/* Leet code 198.
198. House Robber

You are a professional robber planning to rob 
houses along a street. 
Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each 
of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingRecur(vector<int>& nums, int n, int i)
    {   //base case
        if(i >= n)
        {
            return 0;
        }
        //Include
        //1 case main solve, baaki recursion
        int includeAns = 0;
        includeAns = nums[i]; //Meine ith ghar mein chori kar li hai
        //Baaki recursion sambhalega
        includeAns += solveUsingRecur(nums, n, i+2);

        //Exclude
        //1 case main solve, baaki recursion
        int excludeAns = 0;
        //Baaki recursion sambhalega
        excludeAns += solveUsingRecur(nums, n, i+1);

        int finalAns = max(includeAns, excludeAns);
        return finalAns;
    }
    
    //Top down Approach
    //1D - DP, 
    //Recur n -> 0
    //rec + memoization
    int solveUsingRecurMem(vector<int>& nums, int n, int i, vector<int>& dp)
    {   //base case
        if(i >= n)
        {
            return 0;
        }
        //Step 3: Base case ke baad, check if ans already exist or not.
        if(dp[i] != -1)
        {
            return dp[i];
        }

        //Include
        //1 case main solve, baaki recursion
        int includeAns = 0;
        includeAns = nums[i]; //Meine ith ghar mein chori kar li hai
        //Baaki recursion sambhalega
        includeAns += solveUsingRecurMem(nums, n, i+2, dp);

        //Exclude
        //1 case main solve, baaki recursion
        int excludeAns = 0;
        //Baaki recursion sambhalega
        excludeAns += solveUsingRecurMem(nums, n, i+1, dp);
        
        //Step 2: dp array mein "ans" store karo and return karo
        dp[i] = max(includeAns, excludeAns);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        //int ans = solveUsingRecur(nums, n, index);
        //Step 1: Create 1D - dp
        vector<int> dp(n+1, -1);
        int ans = solveUsingRecurMem(nums, n, index, dp);
        return ans;
    }

        //Bottom-Up Approach
    int solveUsingTab(vector<int>& nums)
    {
        int n = nums.size();
        //step 1: create a dp array, type: 1D dp, of size (n+1)
        vector<int> dp(n+2, -1);//n+2 for i+2 and i+1
        //step2: analyse base cases and update dp array
        // Check always dp[i+2] and dp[i+1] are valid or not, after creating dp.
        dp[n] = 0;
        dp[n+1] = 0;

        //step3: check parameter and reverse it and run the loop
        //In recursion, 0 -> n
        //Reverse, n -> 0
        for(int i=n-1; i>=0; i--)
        {
            //Include
            int includeAns = 0;
            includeAns = nums[i]; //Meine ith ghar mein chori kar li hai
            includeAns += dp[i+2];

            //Exclude
            int excludeAns = 0;
            excludeAns += dp[i+1];
        
            //Step 2: dp array mein "ans" store karo and return karo
            dp[i] = max(includeAns, excludeAns);
        }
        return dp[0];
    }

    //Bottom-Up Approach - Space Optimization
    int solveUsingTabSpaceOptimal(vector<int>& nums)
    {
        int n = nums.size();
        //step 1: create a dp array, type: 1D dp, of size (n+1)
        vector<int> dp(n+2, -1);//n+2 for i+2 and i+1
        //step2: analyse base cases and update dp array
        int next1 = 0;
        int next2 = 0;

        //step3: check parameter and reverse it and run the loop
        //In recursion, 0 -> n
        //Reverse, n -> 0
        for(int i=n-1; i>=0; i--)
        {
            //Include
            int includeAns = 0;
            includeAns = nums[i]; //Meine ith ghar mein chori kar li hai
            includeAns += next2;

            //Exclude
            int excludeAns = 0;
            excludeAns += next1;
        
            //Step 2: dp array mein "ans" store karo and return karo
            int curr = max(includeAns, excludeAns);
            //Shifting -> ye bhul jata huin
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }

    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        //int ans = solveUsingRecur(nums, n, index);
        // Top Down Approach
        //Step 1: Create 1D - dp
        //vector<int> dp(n+1, -1);
        //int ans = solveUsingRecurMem(nums, n, index, dp);
        // Bottom - Up Approach
        //int ans = solveUsingTab(nums);
        int ans = solveUsingTabSpaceOptimal(nums);
        return ans;
    }
    
};