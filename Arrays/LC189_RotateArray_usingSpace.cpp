/*
189. Rotate Array
Given an integer array nums, 
rotate the array to the right by k steps, 
where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can.
There are at least three different ways to solve 
this problem.
Could you do it in-place with O(1) extra space?
*/
// Time Complexity- O(N)
// Space Complexity - O(N)
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector <int> temp;
        int size = nums.size(); 
        k = k % size; // to handle k > size

        for(int i = size - k; i< size; i++)
        {
            temp.push_back(nums[i]);
        }
        //Traversing from Right to Left
        for(int i = size - 1; i>=0; i--)
        {
            if(i-k>=0)
            {
                nums[i] = nums[i-k];
            }
        }

        for(int i = 0; i<k; i++)
        {
            nums[i] = temp[i];
        }
    }
};