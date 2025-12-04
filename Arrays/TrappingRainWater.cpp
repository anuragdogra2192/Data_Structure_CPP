/* Leet Code 42.
42. Trapping Rain Water

Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {

        int i = 0;
        int j = height.size() - 1;
        int max_left = 0;
        int max_right = 0;
        int water = 0;
        while(i<j)
        {
            if(height[i] <= height[j])
            {
                max_left = max(max_left, height[i]);
                water += max_left - height[i];
                i += 1;
            }
            else
            {
                max_right = max(height[j], max_right);
                water += max_right - height[j];
                j -= 1;
            }
        }
        return water;
    }
};