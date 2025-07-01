/* Leet Code 239.
239. Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/
//Time Complexity: O(N)
//Space Complexity: O(k) (auxiliary)

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans; 
        
        //process first window.
        for(int i=0; i<k; i++)
        {
            int element = nums[i];
            //The above element we have to insert in the queue,
            //But now we can remove the non-required elements from the queue if its not empty.
            //non-required: elements that are less than the current element. (chote elements ko hata do.)
            //Remember dq contains the index of the element
            while(!dq.empty() && nums[dq.back()] < element)//Yaha galti hui thi, back se pop karna hai
            {
                dq.pop_back();
            }
            //current element toh insert karna hi hai. Insert its index.
            dq.push_back(i);
        }
        
        //processing the remaining window -> ans/removal/addition
        for(int i=k; i<nums.size(); i++)
        {
            //Ans Store of window
            int index = dq.front();
            int element = nums[index];
            ans.push_back(element);
            
            //removal and window shifting
            if(!dq.empty() && (i - dq.front() >= k))
            {
                dq.pop_front();
            }

            //Addition
            element = nums[i];
            //The above element we have to insert in the queue,
            //But now we can remove the non-required elements from the queue if its not empty.
            //non-required: elements that are less than the current element. (chote elements ko hata do.)
            //Remember dq contains the index of the element
            while(!dq.empty() && nums[dq.back()] < element)//Yaha galti hui thi, back se pop karna hai
            {
                dq.pop_back();
            }
            //current element toh insert karna hi hai, insert its index.
            dq.push_back(i);
        }
        //Get the Answer of the last window
        int index = dq.front();
        int element = nums[index];
        ans.push_back(element);

        return ans;
    }
};