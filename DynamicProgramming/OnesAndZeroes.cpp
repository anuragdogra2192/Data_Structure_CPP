/* Leet code
474. Ones and Zeroes

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Example 2:
Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 
Constraints:
1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void convertStrToNumStrs(vector<string>& strs, vector<pair<int, int>>& numStrs){
        for(auto str:strs)
        {
            int zeros = 0, ones = 0;
            for(auto ch:str)
            {
                if(ch == '0') ++zeros;
                else ++ones;
            }
            numStrs.push_back({zeros, ones});
        }
    }
    
    int solve(vector<pair<int, int>>& numStrs, int i, int m, int n)
    {
        if(i == numStrs.size()) return 0;
        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;

        if(m - zeros >= 0 && n - ones >= 0)
        {
            include = 1 + solve(numStrs, i+1, m - zeros, n - ones);
        } 
        exclude = solve(numStrs, i+1, m, n);
        return max(include, exclude);
    }
    
    int solveTD(vector<pair<int, int>>& numStrs, int i, int m, int n, vector<vector<vector<int>>>& dp)
    {
        if(i == numStrs.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int zeros = numStrs[i].first;
        int ones = numStrs[i].second;
        int include = 0, exclude = 0;

        if(m - zeros >= 0 && n - ones >= 0)
        {
            include = 1 + solveTD(numStrs, i+1, m - zeros, n - ones, dp);
        } 
        exclude = solveTD(numStrs, i+1, m, n, dp);
        return dp[i][m][n] = max(include, exclude);
    }


    int solveBU(vector<pair<int, int>>& numStrs, int m, int n)
    {
        vector<vector<vector<int>>> dp(numStrs.size() + 1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        for(int i = numStrs.size() - 1; i>=0; i--)
        {
            for(int j = 0; j<=m; j++)
            {
                for(int k = 0; k<=n; k++)
                {
                    int zeros = numStrs[i].first;
                    int ones = numStrs[i].second;
                    int include = 0, exclude = 0;
                    if(j - zeros >= 0 && k - ones >= 0)
                    {
                        include = 1 + dp[i+1][j-zeros][k-ones];//solveTD(numStrs, i+1, m - zeros, n - ones, dp);
                    } 
                    exclude = dp[i+1][j][k];//solveTD(numStrs, i+1, m, n, dp);
                    dp[i][j][k] = max(include, exclude);
                }
            }
        }
        return dp[0][m][n];
    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> numStrs; // {no. of 0's, no. of 1's};
        convertStrToNumStrs(strs, numStrs);
        //return solve(numStrs, 0, m, n);  
        //vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        //return solveTD(numStrs, 0, m, n, dp);  
        return solveBU(numStrs, m, n);
    }
};