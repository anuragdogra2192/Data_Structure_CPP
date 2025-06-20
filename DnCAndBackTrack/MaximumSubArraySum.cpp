/** Leet Code
 * 53. Maximum Subarray
 * USING DnC (Divide And Conquer.)
 * 
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 * 
 Divide and conquer approach

 Time Complexity:  O(nlogn)
 Space Complexity: O(log n) due to recursion stack.

 For TC - O(n), we can use Kadane's algorithm.
 */

#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArrayHelper(vector<int>& nums, int start, int end)
    {
        //base case
        if(start>end){return 0;}
        if(start==end){return nums[end];}

        int mid = start+((end-start)/2);
        
        int maxLeftSum = maxSubArrayHelper(nums, start, mid);
        int maxRightSum = maxSubArrayHelper(nums, mid+1, end);

        //Max Cross Border Sum
        int maxLeftBorderSum = INT_MIN;
        int maxRightBorderSum = INT_MIN;

        int leftBorderSum = 0;
        int rightBorderSum = 0;
        
        //Left Border Sum
        for(int i=mid; i>=start; i--)
        {
            leftBorderSum += nums[i];
            if(leftBorderSum > maxLeftBorderSum)
            {
                maxLeftBorderSum = leftBorderSum;
            }
        }

        //Right Border Sum
        for(int i=mid+1; i<=end; i++)
        {
            rightBorderSum += nums[i];
            if(rightBorderSum > maxRightBorderSum)
            {
                maxRightBorderSum = rightBorderSum;
            }
        }

        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;

        return max(crossBorderSum, max(maxLeftSum, maxRightSum));
    }
    int maxSubArray(vector<int>& nums) 
    {
        return maxSubArrayHelper(nums, 0, nums.size()-1);   
    }
};