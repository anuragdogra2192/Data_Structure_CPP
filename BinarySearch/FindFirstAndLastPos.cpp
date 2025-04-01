/* Leet Code 34.

Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/

class Solution {
public:
    void firstOccurence(vector<int>&nums,int target, int& firstIndex)
    {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s+(e-s)/2;

        while(s<=e)
        {    //cout<< "Target" << target<<endl; 
                //cout<<"arr val: "<<arr[mid];
                if(target == nums[mid])
                {
                    //store karo
                    firstIndex = mid;
                    //cout<<"arr val: "<<arr[mid];
                    //Compute karo
                    //Further first occurence left mein hi milega.
                    e = mid-1; 
                }
                if(target > nums[mid])
                {// right me jao
                    s = mid + 1;
                }
                if(target < nums[mid])
                {// left mein jao
                    e = mid - 1;
                }

                mid = s + (e - s)/2;
        } 
    }
    void lastOccurence(vector<int> nums, int& lastIndex, int target)
    {
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;

        while(s<=e)
        {
            if(target == nums[mid])
            {
                //Store
                lastIndex = mid;
                //Right mein last occurence hoi sakti hai
                s = mid+1;
            }
            if(target > nums[mid])
            {
                //right side 
                s = mid + 1;
            }
            if(target < nums[mid])
            {
                //left side
                e = mid -1;
            }

            mid = s + (e-s)/2;

        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int firstIndex = -1;
        int lastIndex = -1;
        
        firstOccurence(nums, target, firstIndex);
        lastOccurence(nums, lastIndex, target);
        
        vector<int> pos{firstIndex, lastIndex};
        return pos;
    }
};