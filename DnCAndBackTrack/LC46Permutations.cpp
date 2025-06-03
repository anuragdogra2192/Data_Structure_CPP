/* Leet Code 46
46. Permutations

Given an array nums of distinct integers, 
return all the possible permutations. 
You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/
/*
Time Complexity: O(n * n!)
Space Complexity: O(n * n!) + O(n) ≈ O(n * n!)
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void solve(vector<int>& nums, int i, vector<vector<int>>& ans)
        {
            //base case
            if(i == nums.size())
            {
                ans.push_back(nums);
                return;
            }
    
            for(int j=i; j<nums.size(); j++)
            {
                //1k case mein solve karunga
                swap(nums[i], nums[j]);
                //Baaki recursion sambhalega
                solve(nums, i+1, ans);
                //Backtrack
                swap(nums[i], nums[j]);
            }
        }
    
        vector<vector<int>> permute(vector<int>& nums)
        {
            vector<vector<int>> ans;
            solve(nums, 0, ans);
            return ans;
        }
    };