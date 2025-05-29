/* Leet code
45. Jump Game II
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        void solve(vector<int>& nums, int index, int& ans, int steps)
        {
            //Base case
            if(index == nums.size()-1)
            {
                ans = min(ans, steps);
                return;
            }
            if(index >= nums.size())
            {//Out of bound case.
                return;
            }
            for(int jump=1; jump<=nums[index]; jump++)
            {
                solve(nums, index + jump, ans, steps+1);
            }
        }
    
        int solve2(vector<int>& nums, int index, int steps)
            {
                //Base case
                if(index == nums.size()-1)
                {
                    return steps;
                }
                int minAns = INT_MAX;
                if(index < nums.size())//index should not go out of bound
                {
                    for(int jump=1; jump<=nums[index]; jump++)
                    {
                        minAns = min(minAns, solve2(nums, index + jump, steps+1));
                    }
                }
                return minAns;
            }
    
        int jump(vector<int>& nums) {
            //int ans = INT_MAX;
            //solve(nums, 0, ans, 0);
            //return ans;
            return solve2(nums, 0, 0);
        }
    };