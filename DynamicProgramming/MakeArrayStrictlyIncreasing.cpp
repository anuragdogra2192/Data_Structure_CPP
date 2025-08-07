/* Leet code 1187.
1187. Make Array Strictly Increasing

Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.

In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].

If there is no way to make arr1 strictly increasing, return -1.

Example 1:
Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

Example 2:
Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

Example 3:
Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
 
Constraints:
1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

#define INF (1e9 + 1)
class Solution {
public:
    int solveRec(vector<int>& arr1, vector<int>& arr2, int prev, int i)
    {
        if(i == arr1.size()) return 0;
        int op1 = INF;
        if(prev <  arr1[i])
        {//.   0 operation
            op1 = 0 + solveRec(arr1, arr2, arr1[i], i+1);
        }
        int op2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if(it != arr2.end())
        {
            int index = it - arr2.begin();
            //arr1[i] = arr2[index];
               //1 operation
            op2 = 1 + solveRec(arr1, arr2, arr2[index], i+1);
        }
        return min(op1, op2);
    }

    int solveMem(vector<int>& arr1, vector<int>& arr2, int prev, int i, map<pair<int, int>, int>& dp)
    {
        if(i == arr1.size()) return 0;
        if(dp.find({prev,i}) != dp.end())
        {
            return dp[{prev, i}];
        }

        int op1 = INF;
        if(prev <  arr1[i])
        {//.   0 operation
            op1 = 0 + solveMem(arr1, arr2, arr1[i], i+1, dp);
        }
        int op2 = INF;
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if(it != arr2.end())
        {
            int index = it - arr2.begin();
            //arr1[i] = arr2[index];
               //1 operation
            op2 = 1 + solveMem(arr1, arr2, arr2[index], i+1, dp);
        }
        return dp[{prev, i}] = min(op1, op2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int prev = -1;
        int i = 0;  
        //int ans = solveRec(arr1, arr2, prev, i);
        //2D - dp, prev and i
        map<pair<int, int>, int> dp;
        int ans = solveMem(arr1, arr2, prev, i, dp);
        return ans == INF ? -1 : ans;
    }
};