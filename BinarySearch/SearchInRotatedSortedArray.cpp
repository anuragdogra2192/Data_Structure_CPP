/*
Leet code
33. Search in Rotated Sorted Array

There is an integer array `nums` sorted in ascending order (with distinct values).

Before being passed to your function, `nums` may have been rotated at an unknown pivot index `k` 
(1 <= k < nums.length). The resulting array could look like this:
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).

For example:
Original array: [0, 1, 2, 4, 5, 6, 7]
Rotated array:  [4, 5, 6, 7, 0, 1, 2] (rotated at pivot index 3)

Given the rotated array `nums` and an integer `target`, return the index of `target` if it exists in `nums`.
Otherwise, return -1.

You must implement an algorithm with O(log n) runtime complexity.

Examples:

Example 1:
Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
Output: 4

Example 2:
Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Constraints:
1. 1 <= nums.length <= 5000
2. -10^4 <= nums[i] <= 10^4
3. All values of `nums` are unique.
4. `nums` is an ascending array that may be rotated.
5. -10^4 <= target <= 10^4

TIME COMPLEXITY - O(log(n)) + O(log(n))
               Find A Pivot   BinarySearch
*/

#include<iostream>
class Solution {
public:
    //Better Way with store and compute.
    int FindaPivot(vector<int>& nums, int s, int e)
    {
        int mid = s + (e-s)/2;
        int ansIndex = -1;
        
        while(s<=e)
        {
            if(nums[mid]>=nums[0])
            {   // Right mein jao
                // May or may not be an answer
                // Store
                ansIndex = mid;
                //Compute
                s = mid + 1;
            }
            else
            {// Left mein jao
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        cout<<"Pivot Element:"<< nums[ansIndex]<<endl;
        return ansIndex;
    }
    // Old way
    // int FindaPivot(vector<int>& nums, int s, int e)
    // {
    //     int mid = s + (e-s)/2;

    //     while(s<e)
    //     {
    //         if(nums[mid]>=nums[0])
    //         {
    //             s=mid+1;
    //         }
    //         else
    //         {
    //             e=mid;
    //         }

    //         mid=s+(e-s)/2;
    //     }
    //     if((s==e) && (e == nums.size()-1))
    //     {
    //         if(nums[s]>nums[0])
    //             s=0;
    //     }
    //     return s;
    // } 

    int binarySearch(vector<int>& nums, int s, int e, int target)
    {
        int mid = s+(e-s)/2;
        while(s<=e)
        {
            //cout<<s<<e;
            if(nums[mid]==target)
            { 
                return mid;
            }
            else if(target>nums[mid])
            {
                s = mid+1;
            }
            else if (target<nums[mid])
            {
                e = mid-1;
            }

            mid = s + (e-s)/2;

        } 
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        
        int pivot_idx = FindaPivot(nums,s,e);
        cout<<"Pivot Index: "<< pivot_idx <<endl;

        // Step 2: Determine which part of the array to search
        if (target >= nums[0] && target <= nums[pivot_idx]) {
            // Search in the left part (from 0 to pivot_idx)
            return binarySearch(nums, 0, pivot_idx, target);
        } 
        //else if (pivot_idx + 1 < nums.size() && target >= nums[pivot_idx + 1] && target <= nums[e]) {
            // Search in the right part (from pivot_idx + 1 to e)
            return binarySearch(nums, pivot_idx + 1, e, target);
        //}

        //return -1; // Target not found
    }
};