/*Geeks For Geeks.
Pairs of equals Sum

Given an array arr. Find if there are two pairs 
(a, b) and (c, d) such that a+b = c+d.

Examples:
Input: arr[] = [3, 4, 7, 1, 2, 9, 8] 
Output: true
Explanation: (3, 7) and (9, 1) are the pairs whosesum are equal.  
Input: arr[] = [65, 30, 7, 90, 1, 9, 8]
Output: false
Explanation: There is no pair.
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 104

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(n^2)
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        // code here.
        unordered_map<int, bool> sumMap;
        
        for(int i=0; i<arr.size(); i++)
        {
            for(int j=i+1; j<arr.size(); j++)
            {
                int sum = arr[i] + arr[j];
                //map mein store kara do
                if(sumMap.find(sum) != sumMap.end())
                {
                    return true;
                }
                else
                {
                    sumMap[sum] = true;
                }
            }
            
        }
        return false;
    }
};