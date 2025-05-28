/* Leet Code:
416. Partition Equal Subset Sum

Given an integer array nums, 
return true if you can partition the array 
into two subsets such that the sum of the elements in both subsets
is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100

Time complexity: O(2^n) exponential
The below solution is done using recursion
and can be improved by using DP.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool twoSubSets(vector<int>& nums, int index, int target)
        {   
            //Base case
            if(target == 0)
            {
                return true;
            }
            if(target < 0)
            {
                return false;
            }
            if(index == nums.size())
            {
                return false;
            }
            //1k case mein solve karunga
            bool includeAns = false;
            bool excludeAns = false;
            //Include
            //baaki recursion sambhalega
            includeAns = twoSubSets(nums, index+1, target-nums[index]);
            //Exclude
            excludeAns = twoSubSets(nums, index+1, target);
    
            return includeAns || excludeAns;
        }
    
        bool canPartition(vector<int>& nums) {
            int sum = 0;
            for(auto i : nums)
            {
                sum+=i;
            }
            if(sum % 2 == 1)
            {
                return false;
            }
            return twoSubSets(nums, 0, sum/2);
        }
    };