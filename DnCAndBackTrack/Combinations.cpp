/* Leet code 77.
77. Combinations
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 
Constraints:

1 <= n <= 20
1 <= k <= n

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solve(int start, vector<vector<int>>& ans, vector<int>& curr, int n, int k)
    {
        //base case
        if(k==0)
        {
            ans.push_back(curr);
            return;
        }

        //1k case mein karunga
        //Baaki recursion sambhalega
        for(int i = start; i<=n; i++)
        {
            curr.push_back(i);
            solve(i+1, ans, curr, n, k-1);
            //Backtrack
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        int start = 1;
        vector<vector<int>> ans;
        vector<int>curr;
        solve(start, ans, curr, n, k);
        return ans;
    }
};

/*
Big O
O(n choose k)	
The code uses backtracking to generate 
all possible combinations of k numbers 
from 1 to n.
The number of combinations is given by n 
choose k, which is the binomial coefficient 
and is equal to n! / (k! * (n-k)!).
*/