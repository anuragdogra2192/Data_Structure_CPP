/* Leet code 179.

179. Largest Number
Given a list of non-negative integers nums, 
arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string 
instead of an integer.

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
    public:
        static bool mycomp(string a , string b)
        {// To handle the edge case like:
         // a = 30, b = 3 -> lexicographically descending sorting.
         // we get a>b ==> 303 but we know 330 > 303
         // To handle this 
         string t1 = a + b; //303 same as normal handling
         string t2  = b + a; // 330 as we need
         return t1>t2;
        }
    
        string largestNumber(vector<int>& nums) {
            vector<string> snums;
            for(int i=0; i<nums.size(); i++)
            {
                snums.push_back(to_string(nums[i]));
            }
            sort(snums.begin(), snums.end(), mycomp);
            // After sorting lexicographically in descending order
            // If  the first element of snums vector is 0 means 
            // all elements are 0; example {0,0,0} or {0} or {0,0}
            // this implies the ans should be "0" only.  
            if(snums[0] == "0")
                return "0";
            
            string ans = "";
            for(int i=0; i<snums.size(); i++)
            {
                ans+=snums[i];
            }
            return ans;
        }
        /*
        Big O - O(n log n)	
        The time complexity is O(n log n) because the code sorts 
        the vector of strings using the custom comparison function 'mycomp', 
        which has a time complexity of O(n log n) due to the sorting algorithm used.
        */
    };