/*Leet code 300.
300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.
Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4

Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:
1 <= nums.length <= 2500
-104 <= nums[i] <= 104
Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int solveUsingRec(vector<int>&nums, int curr, int prev)
    {
        //base case
        if(curr >= nums.size())
        {
            return 0;
        }

        int inclen = 0;
        if(prev == -1 || nums[curr] > nums[prev])
        {
            //1k case mera 
            inclen = 1;
            //bakki reacursion
            inclen += solveUsingRec(nums, curr+1, curr);
        }
        
        //1k case mera
        int exclen = 0;
        //bakki reacursion
        exclen += solveUsingRec(nums, curr+1, prev);
        int finalAns = max(inclen, exclen);
        return finalAns;
    }

    //Top Down Approach
    int solveUsingRecMem(vector<int>&nums, int curr, int prev,  vector<vector<int>>& dp)
    {
        //base case
        if(curr >= nums.size())
        {
            return 0;
        }
        //Step 3: If ans already exist
        //lets sift the lastIndex to lastIndex+1
        if(dp[curr][prev+1] != -1)
        {
            return dp[curr][prev+1];
        }

        int inclen = 0;
        if(prev == -1 || nums[curr] > nums[prev])
        {
            //1k case mera 
            inclen = 1;
            //bakki reacursion
            inclen += solveUsingRecMem(nums, curr+1, curr, dp);
        }
        //1k case mera
        int exclen = 0;
        //bakki reacursion
        exclen += solveUsingRecMem(nums, curr+1, prev, dp);
        
        //step 2: Store ans in dp and return 
        dp[curr][prev+1] = max(inclen, exclen);
        return dp[curr][prev+1];
    }

    int solveUsingTab(vector<int>&nums, int curr, int prev)
    {
        int n = nums.size();
        //Step1: Create a dp, 2D
        //Step2: analyse the base case and update the dp array, sab 0 se fill kar do.
        vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

        //Recur ranges
        //curr -> 0 to n
        //prev -> -1 to curr //yaha galti hoti hai
        //reverse it and apply loop
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = curr-1; prev>=-1; prev--)
            {
                int inclen = 0;
                if(prev == -1 || nums[curr] > nums[prev])
                {
                    //1k case mera 
                    inclen = 1;
                    //bakki reacursion
                    inclen += dp[curr+1][curr+1];
                }
                //1k case mera
                int exclen = 0;
                //bakki reacursion
                exclen += dp[curr+1][prev+1];

                //step 2: Store ans in dp and return 
                dp[curr][prev+1] = max(inclen, exclen);
            }
        }
        return dp[0][-1+1];//same input as recur ke startintg args ke tarah
    }

    //Dp and binary search - Bottom UP approach
    //time Complexity: O(n log n);
    int solveDPAndBS(vector<int>& nums)
    {
        vector<int>ans;//dp
        ans.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {//find the index of the just >= the ith element.
                auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
                int index = it - ans.begin();
                ans[index] = nums[i]; 
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        int n = nums.size();
        //return solveUsingRec(nums, curr, prev);
        //Step 1: create the dp, 2D (n+1) * (n+1) size
        //Observation jo ham bhul gaye the,  prev hamesha curr se peeche rahne wala hai
        //vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //return solveUsingRecMem(nums, curr, prev, dp);
        //return solveUsingTab(nums, curr, prev);
        return solveDPAndBS(nums);
    }
};