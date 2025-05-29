/* Leet Code
55. Jump Game

You are given an integer array nums. 
You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    //Time complexity - Exponential.
        bool solve(vector<int>& nums, int index)
        {   
            //base case:
            if(index == nums.size()-1)
            {
                return true;
            }
            //if((index < nums.size()-1) && nums[index] == 0)
            //{
            //    return false;
            //}
            //if(index >= nums.size())
            //{//Out of bound 
            //    return false;
            //}
            bool ans = false;
            for(int jump=1; jump<=nums[index]; jump++)
            {  //Start Jump = 1, we need it to start.
    
                //Update ans, either is true then true
                //ans = (ans || solve(nums, index+jump)); not required. 
                ans = solve(nums, jump + index);
                if(ans) return ans;// return true
            }
            return ans;
        }
    
        bool canJump(vector<int>& nums) {
            return solve(nums, 0);    
        }
    };