/*Leet code 494. Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int target, int i)
    {   
        //base case
        if(i == nums.size()) 
        {
            return target == 0 ? 1 : 0;
        }

        int plus = solve(nums, target - nums[i], i + 1);
        int minus = solve(nums, target + nums[i], i + 1);

        return minus + plus;
    }

    int solveMem(vector<int>& nums, int target, int i, map<pair<int, int>, int>& dp)
    {   
        //base case
        if(i == nums.size()) 
        {
            return target == 0 ? 1 : 0;
        }

        if(dp.find({i, target}) != dp.end()) return dp[{i, target}];

        int plus = solveMem(nums, target - nums[i], i + 1, dp);
        int minus = solveMem(nums, target + nums[i], i + 1, dp);

        return dp[{i, target}] = minus + plus;
    }

    int solveBU(vector<int>& nums, int target)
    {   
        map<pair<int, int>, int> dp;
        //handle base cases
        dp[{nums.size(), 0}] = 1;
        
        int total = 0;
        for(auto num : nums) total += num;

        //recur i : 0 -> nums.size
        //loop nums.size -> 0
        for(int i = nums.size() - 1; i>=0; i--)
        {
            //Now target loop
            for(int sum = -total; sum <= total; sum++)
            {
                int plus = dp.find({i+1, sum - nums[i]}) != dp.end() ? dp[{i+1, sum - nums[i]}] : 0;//solveMem(nums, target - nums[i], i + 1, dp);
                int minus = dp.find({i+1, sum + nums[i]}) != dp.end() ? dp[{i+1, sum + nums[i]}] : 0; //solveMem(nums, target + nums[i], i + 1, dp);
                dp[{i, sum}] = minus + plus;
            }
        }
        return dp[{0, target}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        //return solve(nums, target, 0);     
        
        //map<pair<int, int>, int> dp; //{i, target} -> no. of ways
        //return solveMem(nums, target, 0, dp); 

        return solveBU(nums, target);
    }
};