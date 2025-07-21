/* Leet code 2163.
2163. Minimum Difference in Sums After Removal of Elements

Highly important 

You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:

The first n elements belonging to the first part and their sum is sumfirst.
The next n elements belonging to the second part and their sum is sumsecond.
The difference in sums of the two parts is denoted as sumfirst - sumsecond.

For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
Return the minimum difference possible between the sums of the two parts after the removal of n elements.


Example 1:
Input: nums = [3,1,2]
Output: -1
Explanation: Here, nums has 3 elements, so n = 1. 
Thus we have to remove 1 element from nums and divide the array into two equal parts.
- If we remove nums[0] = 3, the array will be [1,2]. The difference in sums of the two parts will be 1 - 2 = -1.
- If we remove nums[1] = 1, the array will be [3,2]. The difference in sums of the two parts will be 3 - 2 = 1.
- If we remove nums[2] = 2, the array will be [3,1]. The difference in sums of the two parts will be 3 - 1 = 2.
The minimum difference between sums of the two parts is min(-1,1,2) = -1. 

Example 2:
Input: nums = [7,9,5,8,1,3]
Output: 1
Explanation: Here n = 2. So we must remove 2 elements and divide the remaining array into two parts containing two elements each.
If we remove nums[2] = 5 and nums[3] = 8, the resultant array will be [7,9,1,3]. The difference in sums will be (7+9) - (1+3) = 12.
To obtain the minimum difference, we should remove nums[1] = 9 and nums[4] = 1. The resultant array becomes [7,5,8,3]. The difference in sums of the two parts is (7+5) - (8+3) = 1.
It can be shown that it is not possible to obtain a difference smaller than 1.
 
Constraints:
nums.length == 3 * n
1 <= n <= 105
1 <= nums[i] <= 105

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include<iostream>
#include<vector>
#include<queue>
#include <climits>//LLVM

using namespace std;

class Solution {
public:
#define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        //prefix[i] = sum of first n elements from left side.
        //suffix[i] = sum of first n elements from right side.
        vector<ll> prefix(nums.size(), -1);
        vector<ll> suffix(nums.size(), -1);

        ll sum = 0; //min element sum
        priority_queue<ll>maxHeap;//maxheap
        
        for(int i=0; i<nums.size(); ++i)
        {
            sum = sum + nums[i];
            maxHeap.push(nums[i]);
            //pop out max elements
            if(maxHeap.size() > n)
            {
                sum = sum - maxHeap.top();
                maxHeap.pop();
            }
            if(maxHeap.size() == n)
            {
                prefix[i] = sum;
            }
        }

        sum = 0; //now max element sum
        priority_queue<ll, vector<ll>, greater<ll> > minHeap;

        for(int j = nums.size()-1; j>=0; j--)
        {
            sum += nums[j];
            minHeap.push(nums[j]);
            //pop out min elements 
            if(minHeap.size() > n)
            {
                sum = sum - minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == n)
            {
                suffix[j] = sum;
            }
        }
        // we have both suffix and prefix
        ll ans = LLONG_MAX;
        for(int i = n-1; i<2*n; i++)
        {
            ans = min(ans, (prefix[i] - suffix[i+1]));
        }
        
        return ans;
    }
};