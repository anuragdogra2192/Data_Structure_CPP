/* Leet code
540. Single Element in a Sorted Array
Solved
Medium
Topics
Companies
You are given a sorted array consisting of only integers 
where every element appears exactly twice, except for one element 
which appears exactly once.
Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        int mid = s+(e-s)/2;

        while(s<=e)
        {
            //Case 1: Single element;
            if (s==e)
            {
                return nums[s];
            }
            
            int leftValue = -1;
            int rightValue = -1;
            int curValue = nums[mid];

            //If Edge contains the ans;
            if(mid-1>=0)
            {
                leftValue = nums[mid-1];
            }
            if(mid+1<n)
            {
                rightValue = nums[mid+1];
            }

            if(curValue != leftValue && curValue != rightValue)
            {
                return curValue;
            }

            //Case 3: left mein duplicate mila 
            if(curValue == leftValue && curValue != rightValue)
            {
                int pairStartIndex = mid-1;
                if(pairStartIndex %2 == 1)
                {//pairStartIndex & 1
                    //Odd hai toh left mein jao
                    e = mid - 1;
                }
                else
                {//move to right
                    s = mid + 1;
                }
            }
            // Case 4: right mein duplicate mila 
            if(curValue == rightValue && curValue != leftValue)
            {
                int pairStartIndex = mid;
                if(pairStartIndex %2 == 1)
                {//pairStartIndex & 1
                    //Odd hai toh left mein jao
                    e = mid - 1;
                }
                else
                {//move to right
                    s = mid + 1;
                }
            }

            mid = s + (e-s)/2;

        }
        return -1;
    }
};