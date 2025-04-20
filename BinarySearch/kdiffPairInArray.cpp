/* Leet Code
532. K-diff Pairs in an Array
Given an array of integers nums and an integer k, 
return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), 
where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only 
return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
 

Constraints:

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107

*/


class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int x) {
        int e = nums.size()-1;
        int mid = s + (e-s)/2;

        while(s<=e)
        {
            if(nums[mid] == x)
            {
                return mid;
            }
            else if(x > nums[mid])
            {
                s = mid + 1;
            }
            else
            {// x < nums[mid]
               e = mid - 1; 
            }
            mid = s + (e-s)/2;
        }
        return -1;        
    }
    int findPairs(vector<int>& nums, int k) {
        //Binary Search approach
        //Time Complexity O(nlogn) + O(nlog(n))
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<pair<int, int>> collector;

        for(int i=0; i<n; i++)
        {
            if(binarySearch(nums, i+1, nums[i]+k) != -1)
            {//Found an element
                collector.insert(make_pair(nums[i], nums[i]+k));
            }
        }
        
        return collector.size();
        //Better one
        //Two pointer approach
        //Time Complexity O(nlogn) + O(n)
        //Space Complexity: O(n)
        // sort(nums.begin(), nums.end());
        // int i = 0;
        // int j = 1;
        // int n = nums.size();
        // int counter = 0;
        // set<pair<int,int>> ans;
        // while(j<n && i<j)
        // {
        //     int diff = nums[j]-nums[i];
        //     if(diff==k)
        //     {
        //         ans.insert(make_pair(nums[i], nums[j]));
        //         i++, j++;
        //     }
        //     else if(diff<k)
        //     {
        //         j++;
        //     }
        //     else//(diff>k)
        //     {
        //         i++;
        //     }
        //     if(i==j) j++;
        // } 
        // return ans.size();
    }
};