/* Leet code 1130.

1130. Minimum Cost Tree From Leaf Values

Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

Example 1:
Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Example 2:
Input: arr = [4,11]
Output: 44
 

Constraints:
2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int solveUsingRecur(vector<int>& arr, map<pair<int, int>, int>&maxi, int s, int e)
    {   //base case and single element(leaf node)
        if(s >= e)
        {
            return 0;
        }

        //1 case solve, baaki recursion
        int ans = INT_MAX;
        for(int i = s; i < e; i++)
        {
            int leftRangeMax = maxi[{s, i}];
            int rightRangeMax = maxi[{i+1, e}];
            int NonLeafValue = leftRangeMax * rightRangeMax;
            ans = min(ans, (NonLeafValue + solveUsingRecur(arr, maxi, s, i) + solveUsingRecur(arr, maxi, i+1, e)));
        }
        return ans;
    }

    int solveUsingMem(vector<int>& arr, map<pair<int, int>, int>&maxi, int s, int e,  vector<vector<int>>& dp)
    {   //base case and single element(leaf node)
        if(s >= e)
        {
            return 0;
        }

        if(dp[s][e] != -1)
        {
            return dp[s][e];
        }

        //1 case solve, baaki recursion
        int ans = INT_MAX;
        for(int i = s; i < e; i++)
        {
            int leftRangeMax = maxi[{s, i}];
            int rightRangeMax = maxi[{i+1, e}];
            int NonLeafValue = leftRangeMax * rightRangeMax;
            ans = min(ans, (NonLeafValue + solveUsingMem(arr, maxi, s, i, dp) + solveUsingMem(arr, maxi, i+1, e, dp)));
        }
        dp[s][e] = ans;
        return dp[s][e];
    }
    
    int solveUsingTab(vector<int>& arr, map<pair<int, int>, int>&maxi)
    {
        int n = arr.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int s=n-1; s>=0; s--)
        {
            for(int e=0; e<n; e++)
            {
                if(s >= e)
                {
                    continue;
                }

                int ans = INT_MAX;
                for(int i = s; i < e; i++)
                {
                    int leftRangeMax = maxi[{s, i}];
                    int rightRangeMax = maxi[{i+1, e}];
                    int NonLeafValue = leftRangeMax * rightRangeMax;
                    ans = min(ans, (NonLeafValue + dp[s][i] + dp[i+1][e]));
                }
                dp[s][e] = ans;
            }
        }
        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;

        //loop for all the pairs for range
        //T.C. O(n^2)
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(i==j)
                {
                    maxi[{i,j}] = arr[i];
                }
                else
                {
                    maxi[{i,j}] = max(maxi[{i,j-1}], arr[j]);
                }
            }
        }
        
        int s = 0;
        int e = n-1;
        //int ans = solveUsingRecur(arr, maxi, s, e);
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //int ans = solveUsingMem(arr, maxi, s, e, dp);
        int ans = solveUsingTab(arr, maxi);
        return ans;
    }
};