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
//With pure recursion  it ends in TLE whicj we will fix with DP later.
    int solve(vector<int>& nums, int n, int i)
        {
            //Base Case
            if(i >= n)//Out of bound hai
            {
                return 0; 
            }
            //Include
            int includeAns = 0;
            //1k Case mein karunga
            includeAns = nums[i]; //Meine ith ghar mein chori kar li hai
            //Baaki recursion sambhalega
            includeAns += solve(nums, n, i+2);
            //Exclude
            //1k Case mein karunga
            int excludeAns = 0;
            //Baaki recursion sambhalega
            excludeAns += solve(nums, n, i+1);
            
            return max(excludeAns, includeAns); 
        }
    
        int rob(vector<int>& nums) {
            int index = 0;
            int ans = solve(nums, nums.size(), index);
            return ans;
        }
    };
/* Time Complexity
O(2^n)	The code uses recursion to explore all 
possible combinations of including and excluding 
houses for robbery. 
At each step, it makes two recursive calls, 
one including the current house and 
the other excluding it. 
This results in a binary tree of recursive calls 
with a branching factor of 2 at each level. 
Therefore, the time complexity is exponential,
O(2^n), where n is the number of houses.
*/