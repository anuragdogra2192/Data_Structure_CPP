/** Leet Code 47.
 * 47. Permutations II
 * 
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>&ans, int start)
    {
        //base case:
        if(start == nums.size())//Out of bound
        {
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;
        for(int i=start; i<nums.size(); i++)
        {   
            if(visited.find(nums[i]) != visited.end())
            {//already visited
                continue;
            }
            visited[nums[i]] = true;
            swap(nums[i], nums[start]);
            solve(nums, ans, start+1);
            //Backtrack, put back in order
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int start = 0;
        solve(nums, ans, start);
        return ans;
    }
};
