/* Leet code 354.

354. Russian Doll Envelopes

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents 
the width and the height of an envelope.

One envelope can fit into another if and only if both the
width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Example 1:
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1

Constraints:
1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isSafeToPlace(vector<int> e1, vector<int> e2)
    {
        if(e1[0] < e2[0] && e1[1] < e2[1])
        {
            return true;
        }
        return false;
    }

    int solve(vector<vector<int>>& env, int prev, int curr)
    {
        if(curr == env.size())
        {
            return 0;
        }

        //include
        int include = INT_MIN;
        //Start case with prev -1 or prev Width & Height < cur Width & height
        if(prev == -1 || isSafeToPlace(env[prev], env[curr]))
        {
            include = 1 + solve(env, curr, curr+1);
        }

        //Exclude, not pick
        int exclude = 0 + solve(env, prev, curr+1);
        return max(include, exclude);
    }
    
    int solveMem(vector<vector<int>>& env, int prev, int curr,vector<vector<int>>& dp)
    {
        if(curr == env.size())
        {
            return 0;
        }
        if(dp[prev+1][curr] != -1)
        {
            return dp[prev+1][curr];
        }
        
        //include
        int include = INT_MIN;
        //Start case with prev -1 or prev Width & Height < cur Width & height
        if(prev == -1 || isSafeToPlace(env[prev], env[curr]))
        {
            include = 1 + solveMem(env, curr, curr+1, dp);
        }

        //Exclude, not pick
        int exclude = 0 + solveMem(env, prev, curr+1, dp);
        dp[prev + 1][curr] = max(include, exclude);//if prev -1, prev + 1
        return dp[prev + 1][curr];
    }

    int solveUsingTabSpaceOptimize(vector<vector<int>>& cuboids)
    {
        int n = cuboids.size();
        vector<int>currRow(n+1, 0); //i
        vector<int>prevRow(n+1, 0); //i+1
        
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = curr-1; prev >= -1; prev--)
            {
                //include
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))
                {//height
                    incl = 1 + prevRow[curr+1];//[curr+1] [-1+1]
                }
                //exclude
                int excl = 0 + prevRow[prev+1];//prev+1 [-1+1]
                currRow[prev+1] = max(incl, excl); //prev + 1, to make prev a valid index.
            }
            //Shifting bhul jate hai
            prevRow = currRow;
        }
        return prevRow[-1+1];
    }

    int solveUsingTabSpaceOptimize2(vector<vector<int>>& cuboids)
    {
        int n = cuboids.size();
        vector<int>currRow(n+1, 0); //i
        //vector<int>prevRow(n+1, 0); //i+1
        
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = -1; prev <= curr-1; prev++)
            {
                //include
                int incl = 0;
                if(prev == -1 || isSafeToPlace(cuboids[prev], cuboids[curr]))
                {//height
                    incl = 1 + currRow[curr+1];//[curr+1] [-1+1]
                }
                //exclude
                int excl = 0 + currRow[prev+1];//prev+1 [-1+1]
                currRow[prev+1] = max(incl, excl); //prev + 1, to make prev a valid index.
            }
            //Shifting bhul jate hai
            //prevRow = currRow;
        }
        return currRow[-1+1];
    }

    static bool comp(vector<int>& a, vector<int> & b)
    {
        if(a[0] == b[0]) return a[1] > b[1];//toh jiski height badi hai wo ana chaihye phele
        return a[0] < b[0]; //increasing order.
    }

    int solveDPAndBS(vector<vector<int>>& env)
    {
        //sorting kardo env ko increasing order mein, width wise
        //if wi = wj, then sort them by dec
        sort(env.begin(), env.end(), comp);
        
        //Run LIS on height
        if(env.size() == 0) return 0;

        vector<int>ans;//dp
        
        ans.push_back(env[0][1]);

        for(int i=1; i<env.size(); i++)
        {
            if(env[i][1] > ans.back())
            {
                ans.push_back(env[i][1]);
            }
            else
            {//find the index of the just >= the ith element.
                auto it = lower_bound(ans.begin(), ans.end(), env[i][1]);
                int index = it - ans.begin();
                ans[index] = env[i][1]; 
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //individual envelope ko sort karne ki zaroorat nahi hai,
        //kynkli que ne rotate karne se mana kiya hai

        //entire array sort kardo, width ke according, increasing order
        //sort(envelopes.begin(), envelopes.end());  
        //int prev = -1;
        //int curr = 0;
        //int ans = solve(envelopes, prev, curr);
        //int n = envelopes.size();
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //int ans = solveMem(envelopes, prev, curr, dp);
        //int ans = solveUsingTabSpaceOptimize2(envelopes);
        //None of the dp method TD and BU worked for TLE.
        //Better method
        //And we sort the heights in decreasing order for same width.
        //For example: 2,3 | 5,4 | 6,7 | 6, 4 // 6,7 and 6,4 7, 4 are decreasing order
        // so that env 2,3 --> 5,4 --> 6,7 --> X 6,4,  total 3 env goes in. 
        //this implies: if wi == wj, then height desc sort.
        //After that we can use Binary Search approach on Heights (used LIS (Largest increasing subsequence))
        //length: 3 : 3, 4, 7 - Ans.
        int ans = solveDPAndBS(envelopes);
        return ans;
    }
};