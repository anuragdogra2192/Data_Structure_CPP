/**
 * Leet code 912
912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

Merge Sort inplace has been used.
Time Complexity: O(NLog^2N)
Space Complexity: O(n)
*/

//Merge Sort inplace has been used.
//Using Gap method.
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void mergeInPlace(vector<int>& v, int s, int e, int mid)
    {
        //lets try the gap method.
        int total_len = e - s + 1;
        int gap =  total_len/2 + total_len%2; //this give ceil of (total_len/2)
        while(gap>0)
        {
            int i = s, j = s + gap;
            while(j<=e)
            {
                if(v[i] > v[j])
                {
                    swap(v[i], v[j]);
                }
                i++, j++;
            }
            gap = gap <= 1 ? 0:(gap/2 + gap%2);
        }
    }

    void mergeSort(vector<int>& v, int s, int e)
    {
        //base case
        if(s>=e) //Out of bound and single element array handled
        {
            return;
        }

        int mid = s+((e-s)/2);

        //Sort left part
        mergeSort(v, s, mid);
        //Sort right part
        mergeSort(v, mid+1, e);
        //Merge left and right sorted part 
        mergeInPlace(v, s, e, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        mergeSort(nums, s, e);
        return nums;
    }
};