/* Leet code 213.
213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

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
    
        int rob(vector<int>& nums) {
            //For single element we need to hanle the case.
            if(nums.size() == 1)
            {
                return nums[0];
            }
    
            int includeFirstHouse = solve(nums, 0, nums.size()-1);
            //T.C: O(2^n)
            int includeLastHouse  = solve(nums, 1, nums.size());
            //T.C: O(2^n)
            return max(includeFirstHouse, includeLastHouse);
            //Time Complexity O(2^n + 2^n) = O(2^n)
        }
    };