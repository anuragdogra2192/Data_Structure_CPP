/* Leet code 213
213. House Robber II

You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int i, int size)
    {
        //Base Case
        if(i >= size)//Out of bound hai
        {
            return 0; 
        }
        
        //Include
        int includeAns = 0;
        //1k Case mein karunga
        includeAns = nums[i]; //Meine ith ghar mein chori kar li hai
        //Baaki recursion sambhalega
        includeAns += solve(nums, i+2, size);
        
        //Exclude
        //1k Case mein karunga
        int excludeAns = 0;
        //Baaki recursion sambhalega
        excludeAns += solve(nums, i+1, size);
        
        return max(excludeAns, includeAns); 
    }
    //Lets try DP
    //top down approach
    //1D dp - 0 - n+1
    int solveRecurMem(vector<int>& nums, int i, int size, vector<int>& dp)
    {
        //Base case
        //index out of bound
        if(i >= size)
        {
            return 0;
        }
        ///Check dp have the ans
        if(dp[i] != -1)
        {//already have an ans
            return dp[i];
        }
        
        //Include Case
        //1k case mein solve karunga
        int includeAns = nums[i];
        //baaki recursion sambhalega
        includeAns += solveRecurMem(nums, i+2, size, dp);

        //Exclude Case
        //1k case mein karrunga
        int excludeAns = 0;
        //baaki recursion sambhalega
        excludeAns += solveRecurMem(nums, i+1, size, dp);
        
        dp[i] = max(includeAns, excludeAns);
        int ans = dp[i];
        return ans;
    }

    // Bottom up approach
    //Recur: 0 --> n
    //Reverse: n --> 0
    int BottomUpApproach(vector<int>& nums, int start, int end)
    {
        int n = end;
        //step 1: create a dp array, type: 1D dp, of size (n+1)
        vector<int> dp(n+2, -1);//n+2 for i+2 and i+1
        //step2: analyse base cases and update dp array
        // Check always dp[i+2] and dp[i+1] are valid or not, after creating dp.
        dp[n] = 0;
        dp[n+1] = 0;
        //step3: check parameter and reverse it and run the loop
        //In recursion, 0 -> n
        //Reverse, n -> 0
        for(int i=end-1; i>=start; i--)
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
        return dp[start];
    }

    int BottomUpApproachOptimize(vector<int>& nums, int start, int end)
    {
        int n = end;
        //step 1: create a dp array, type: 1D dp, of size (n+1)
        //vector<int> dp(n+2, -1);//n+2 for i+2 and i+1
        //step2: analyse base cases and update dp array
        // Check always dp[i+2] and dp[i+1] are valid or not, after creating dp.
        int next1 = 0;
        int next2 = 0;
        //step3: check parameter and reverse it and run the loop
        //In recursion, 0 -> n
        //Reverse, n -> 0
        for(int i=end-1; i>=start; i--)
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
            //Shifting, ye bhul jata huin
            next2 = next1;
            next1 = curr;
        }
        return next1;
    }

    int rob(vector<int>& nums) {
        //For single element we need to hanle the case.
        if(nums.size() == 1)
        {
            return nums[0];
        }
        //int includeFirstHouse = solve(nums, 0, nums.size()-1);
        //int includeLastHouse  = solve(nums, 1, nums.size());
        
        //Top Down
        //1D: 0 - n
        int n = nums.size();
        //vector<int> dp1(n+1, -1);
        //int includeFirstHouse = solveRecurMem(nums, 0, nums.size()-1, dp1);
        //std::fill(dp1.begin(), dp1.end(), -1);
        //int includeLastHouse = solveRecurMem(nums, 1, nums.size(), dp1);

        //Bottom up
        //int includeFirstHouse = BottomUpApproach(nums, 0, nums.size()-1);
        //int includeLastHouse = BottomUpApproach(nums, 1, nums.size());
        
        //return max(includeFirstHouse, includeLastHouse);

        //BottomUpApproachOptimize
        int includeFirstHouse = BottomUpApproachOptimize(nums, 0, nums.size()-1);
        int includeLastHouse = BottomUpApproachOptimize(nums, 1, nums.size());

        return max(includeFirstHouse, includeLastHouse);
    }
};