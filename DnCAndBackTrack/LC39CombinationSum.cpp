/**
 * Leet Code: 39
39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

Time Complexity: O(2^T)
Space Complexity: O(T) (recursion stack) + O(output size)
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, vector<int>& v, vector<vector<int>>& ans)
    {
        //base case
        if(target == 0)
        {
            ans.push_back(v);
            return;
        }
        if(target < 0)
        {
            return;
        }

        for(int i = index; i<candidates.size(); i++)
        {
            v.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i, v, ans);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        int index = 0;
        solve(candidates, target, index, v, ans);
        return ans;
    }
};