/**
 * Leet Code: 40 
40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 
Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30   
*/

/* Approach one Using Set
Time Comlexity: O(nlogn) + O(2^T)
Space Complexity: 
TLE: Time Limit Exceeded using due to using Set. 
*/
#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, vector<int>& v, set<vector<int>>& ans)
    {
        //base case
        if(target == 0)
        {   
            //vector<int> temp(v.begin(), v.end());
            //sort(temp.begin(), temp.end());
            //ans.insert(temp);
            //Better is to sort the original array at the begining in one call.
            ans.insert(v);
            return;
        }
        if(target<0)
        {
            return;
        }

        for(int i=index; i<candidates.size(); i++)
        {
            v.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, v, ans);
            //Backtrack
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        set<vector<int>> ans;
        int index = 0;
        solve(candidates, target, index, v, ans);
        vector<vector<int>> vans (ans.begin(), ans.end()); 
        return vans;
    }
};

/**
 * Approach Two: without using set
 * Best appoach Beats 100%
 * 
 */

class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, vector<int>& v, vector<vector<int>>& ans/*set<vector<int>>& ans*/)
    {
        //base case
        if(target == 0)
        {   
            //vector<int> temp(v.begin(), v.end());
            //sort(temp.begin(), temp.end());
            //ans.insert(temp);
            //Better is to sort the original array at the begining in one call.
            //ans.insert(v);//For set
            ans.push_back(v);
            return;
        }
        if(target<0)
        {
            return;
        }

        for(int i=index; i<candidates.size(); i++)
        {
            if(i>index && (candidates[i] == candidates[i-1]))
            {//To skip having similar candidates' combinations.
                continue;
            }
            v.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, v, ans);
            //Backtrack
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        //Lets get rid of set, bit slow.
        //set<vector<int>> ans;
        vector<vector<int>> ans;
        int index = 0;
        solve(candidates, target, index, v, ans);
        //vector<vector<int>> vans (ans.begin(), ans.end()); 
        //return vans;
        return ans;
    }
};
/***
Summary Table
Approach	Time Complexity	Space Complexity
Using Set	O(n log n + 2^n * k)	O(2^n * k)
Without Set	O(n log n + 2^n * k)	O(2^n * k)
n = number of candidates
k = average length of a combination
*/
