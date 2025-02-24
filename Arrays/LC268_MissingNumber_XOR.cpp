/*
268. Missing Number

Given an array nums containing n distinct numbers
in the range [0, n], 
return the only number in the range 
that is missing from the array.

Example 1:
Input: nums = [3,0,1]

Output: 2
Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]

Output: 2

Explanation:

n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]

Output: 8

Explanation:

n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
 */

// Time Complexity O(N)
// Space Complexity O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
    // XOR is our friend here
    // n is size
    //Step 1: XOR all nums values
    //Step 2: XOR with all range values [0-n]
    // XOR rule: A^A = 0 
    int n = nums.size();
    int ans = 0; 
    for(int i=0; i<n; i++)
    {
        ans = ans^nums[i]; //Step1
        ans = ans^i; // Step2
    }       
        ans = ans^n; //XOR with n was missing above.

        return ans; // missing number.
    }
};