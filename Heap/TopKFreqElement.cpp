/*
347. Top K Frequent Elements
Given an integer array nums and an integer k,
return the k most frequent elements. 
You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


Example 2:
Input: nums = [1], k = 1
Output: [1]
 

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Time Complexity: O(n log k)
Space Complexity: O(n + k) 
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
//Highly used in Social media. Get top k viewed videos.
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        //Get the frequency of element
        unordered_map<int, int> freqMap;
        for(auto num:nums)
        {
            freqMap[num]++;
        }
        //pair<int, int> shows, {freq, num}
        //lets use minHeap to get size k
        //greater of pair uses the first for comparison
        priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int> > >minHeap;
        
        //iterate over the frequency map and we want to maintain the heap of size k (mainting top k freq. elements)
        for(auto entry: freqMap)
        {
            minHeap.push({entry.second, entry.first}); //heap has pair
            if(minHeap.size() > k)
            {
                minHeap.pop(); //we are removing the least frequent element
            }
        }
        //Now we have top k freq. elements
        while(!minHeap.empty())
        {
            //auto element = minHeap.top().second;
            //minHeap.pop();
            //ans.push_back(element);
            //C++17 below:
            auto [freq, num] = minHeap.top();
            minHeap.pop();
            ans.push_back(num);
        }
        return ans;
    }
};