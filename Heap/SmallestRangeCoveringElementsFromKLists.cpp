/* Leet code 632.
632. Smallest Range Covering Elements from K Lists

Important Interview : highly important, amzn asked.

You have k lists of sorted integers in non-decreasing order. 
Find the smallest range that includes at least one number 
from each of the k lists.

We define the range [a, b] is smaller than range [c, d] 
if b - a < d - c or a < c if b - a == d - c.

Example 1:
Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]

Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Example 2:
Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

Constraints:
nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.

Time Complexity
Each element from all k lists is pushed and popped from the min-heap at most once.
Let N be the total number of elements across all lists.
Each heap operation (push/pop) takes O(log k) time (since the heap size is at most k).
Total time complexity:
O(N log k)
Space Complexity
The min-heap stores up to k elements at a time: O(k)
No other significant extra space is used.
Total space complexity:
O(k)
Summary:

Time: O(N log k)
Space: O(k)
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Info
{
    public:
    int data;
    int rIndex;
    int cIndex;

    Info(int a, int b, int c)
    {
        this->data = a;
        this->rIndex = b;
        this->cIndex = c; 
    }
};

class compare
{
    public:
    bool operator()(Info* a, Info* b)
    {
        return (a->data > b->data);
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> min_pq;
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        int rowTotal = nums.size();
        
        //proces first k elements
        for(int row =0; row < rowTotal; row++)
        {
            int element = nums[row][0];
            Info* temp = new Info(element, row, 0);
            min_pq.push(temp);
            mini = min(mini, element);
            maxi = max(maxi, element);
        }

        int ans_start = mini;
        int ans_end = maxi;

        //main iogic
        while(!min_pq.empty())
        {
            //front nikalo
            Info* front = min_pq.top();
            min_pq.pop();

            int frontData = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;
            
            //Ye bhul jata huin
            mini = frontData; //mini update karo

            //ans update
            if((maxi - mini) < (ans_end - ans_start))
            {//found new small diff
                ans_start = mini;
                ans_end = maxi;
            }

            //aage ke element insert karo
            if((front_cIndex + 1) < nums[front_rIndex].size())//col sizes are diff.
            {
                int element = nums[front_rIndex][front_cIndex + 1];
                Info* temp = new Info(element, front_rIndex, front_cIndex + 1);
                min_pq.push(temp);
                maxi = max(maxi, element);
            }
            else
            {//row mein element nai hai toh break karo
             //kynki condition says, at least one number from each of the k lists.
                break;
            }
        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
    }
};