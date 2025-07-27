/*Leet code 416.
416. Partition Equal Subset Sum

Given an integer array nums, return true 
if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned 
into equal sum subsets.

Constraints:
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool twoSubSets(vector<int>& nums, int index, int target)
    {   
        //Base case
        if(target == 0)
        {
            return true;
        }
        if(target < 0)
        {
            return false;
        }
        if(index == nums.size())
        {
            return false;
        }
        //1k case mein solve karunga
        bool includeAns = false;
        bool excludeAns = false;
        //Include
        //baaki recursion sambhalega
        includeAns = twoSubSets(nums, index+1, target-nums[index]);
        //Exclude
        excludeAns = twoSubSets(nums, index+1, target);

        return includeAns || excludeAns;
    }

    bool solveMem(vector<int>& nums, int index, int target, vector<vector<int>>& dp)
    {
        //Base case
        if(target == 0)
        {
            return true;
        }
        if(target < 0)
        {
            return false;
        }
        if(index == nums.size())
        {
            return false;
        }
        //Step3: check if ans already exists
        if(dp[target][index] != -1)
        {
            return dp[target][index];
        }

        //1k case mein solve karunga
        bool includeAns = false;
        bool excludeAns = false;
        //Include
        //baaki recursion sambhalega
        includeAns = solveMem(nums, index+1, target-nums[index], dp);//Yeah bhul jata huin
        //Exclude
        excludeAns = solveMem(nums, index+1, target, dp);
        //Step 2 ans store and return
        dp[target][index] = includeAns || excludeAns;

        return dp[target][index];
    }

    bool solveUsingTab(vector<int>& nums, int target)
    {
        //Step 1: Create a 
        int n = nums.size();
        vector<vector<bool> > dp(target+1, vector<bool>(n+1, 0));
        //Analyse the base case
        for(int col = 0; col<=n; col++)
        {
            dp[0][col] = true;
        }
        //Step2: Range check
        //Recur
        //target: target --> 0
        //index: 0 --> n
        //Reverse
        //0 -> target
        //n -> 0
        for(int t=1; t<=target; t++)
        {
            for(int i=n-1; i>=0; i--)
            {
                bool includeAns = false;
                if(t - nums[i] >= 0)
                { 
                    includeAns = dp[t-nums[i]][i+1];
                }
                //Exclude
                bool excludeAns = dp[t][i+1];
                dp[t][i] = includeAns || excludeAns;
            }
        }
        return dp[target][0];
    }

    bool solveUsingTabSpaceOptimize(vector<int>& nums, int target)
    {
        //Step 1: Create a 
        int n = nums.size();
        vector<bool> curr(target+1, 0);
        vector<bool> next(target+1, 0);
        //curr[0] = true;
        next[0] = true;
        //Step2: Range check
        //Recur
        //target: target --> 0
        //index: 0 --> n
        //Reverse
        //0 -> target
        //n -> 0
        for(int i=n-1; i>=0; i--)
        {
            for(int t=1; t<=target; t++)
            //for(int t=target; t>=1; t--)
            {
                bool includeAns = false;
                if(t - nums[i] >= 0)
                { 
                    includeAns = next[t-nums[i]];//[i+1];
                }
                //Exclude
                bool excludeAns = next[t];//[i+1];
                curr[t] = includeAns || excludeAns;
            }
            next = curr;
        }
        return next[target];
    }

    bool solveUsingTabSpaceOptimize2(vector<int>& nums, int target)
    {
        //Step 1: Create a 
        int n = nums.size();
        vector<bool> curr(target+1, 0);
        curr[0] = true;
        
        //Step2: Range check
        //Recur
        //target: target --> 0
        //index: 0 --> n
        //Reverse
        //0 -> target
        //n -> 0
        for(int i=n-1; i>=0; i--)
        {
            for(int t=target; t>=1; t--)
            {
                bool includeAns = false;
                if(t - nums[i] >= 0)
                { 
                    includeAns = curr[t-nums[i]];//[i+1];
                }
                //Exclude
                bool excludeAns = curr[t];//[i+1];
                curr[t] = includeAns || excludeAns;
            }
        }
        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
        {
            sum+=i;
        }
        if(sum % 2 == 1)
        {
            return false;
        }
        //return twoSubSets(nums, 0, sum/2);

        //Step1: 2D - dp 
        int target = sum/2;
        //vector<vector<int>> dp(target+1, vector<int>(n+1, -1));
        //return solveMem(nums, 0, target, dp);
        //return solveUsingTab(nums, target);

        //return solveUsingTabSpaceOptimize(nums, target);
        return  solveUsingTabSpaceOptimize2(nums, target);
    }
};