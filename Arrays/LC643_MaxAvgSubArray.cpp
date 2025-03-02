/*
643. Maximum Average Subarray I
Solved
Easy
Topics
Companies
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104

Time Complexity - O(n)
Space Complexity - O(1)
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double sum = 0;
        double maxSum = 0;
        //Get initial array sum        
        for(int i=0; i<k; i++)
        {
            sum += nums[i];
        }
        maxSum = sum;

        //Now introducing sliding window
        int startIndex = 0;
        int endIndex = k - 1;
        int lastIndex = nums.size() - 1;

        while(endIndex < lastIndex)
        {
            //Removing old
            sum -= nums[startIndex];
            //Sliding 
            startIndex++;
            endIndex++;
            //Adding new
            sum += nums[endIndex];
            maxSum = max(maxSum, sum);
        }
        return maxSum/k;
    }
};