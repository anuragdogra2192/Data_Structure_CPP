/* Leet Code 215.
215. Kth Largest Element in an Array

Given an integer array nums and an integer k, 
return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, 
not the kth distinct element.

Can you solve it without sorting?

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

Constraints:
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
/*
Time Complexity
Building the initial min-heap of size k: O(k)
For each of the remaining (n - k) elements:
Each comparison and possible pop/push operation: O(log k)
Total time: O(k + (n - k) * log k) = O(n log k)
Space Complexity
The min-heap stores at most k elements: O(k)
No other significant extra space.
Summary:

Time: O(n log k)
Space: O(k)
*/
    //Best way
    int findKthLargestUsingMinHeap(vector<int>& nums, int k) {
        //Min Heap
        priority_queue<int, vector<int>, greater<int> >min_pq;
        //For first k elements
        for(int i = 0; i<k; i++)
        {
            min_pq.push(nums[i]);
        }
        //for remaining n-k Element
        for(int i=k; i<nums.size(); i++)
        {
           int element = nums[i];
           if(element > min_pq.top())
           {
                min_pq.pop();
                min_pq.push(nums[i]);
           }
        }
        return min_pq.top();
    }
/*
Time Complexity of findKthLargestUsingMaxHeap
Building the max-heap with n elements: O(n)
Removing the top element k-1 times: Each pop is O(log n), so total O(k log n)
Total time complexity:
O(n + k log n)
Space Complexity
The max-heap stores all n elements: O(n)
No other significant extra space.
Summary:

Time: O(n + k log n)
Space: O(n)
*/
    int findKthLargestUsingMaxHeap(vector<int>& nums, int k)
    {
        //Max heap, by default its Max
        priority_queue<int> pq;

        for(int i = 0; i<nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        int ans;
        int count = 1;
        while(count<k)
        {
            pq.pop();
            count++;
        }
        return pq.top();//kth element
    }

    int findKthLargest(vector<int>& nums, int k) 
    {
        //return findKthLargestUsingMinHeap(nums, k);
        return findKthLargestUsingMaxHeap(nums, k);
    }
};