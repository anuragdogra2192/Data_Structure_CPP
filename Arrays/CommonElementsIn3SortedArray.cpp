/*
GFG: Common in 3 Sorted Arrays

NOTE: INTERVIEW question

Given three sorted arrays in non-decreasing order, 
print all common elements in non-decreasing order across these arrays. 
If there are no such elements return an empty array. 
In this case, the output will be -1.

Note: can you handle the duplicates without using any additional Data Structure?

Examples :

Input: arr1 = [1, 5, 10, 20, 40, 80] , arr2 = [6, 7, 20, 80, 100] , arr3 = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: 20 and 80 are the only common elements in arr, brr and crr.
Input: arr1 = [1, 2, 3, 4, 5] , arr2 = [6, 7] , arr3 = [8,9,10]
Output: [-1]
Explanation: There are no common elements in arr, brr and crr.
Input: arr1 = [1, 1, 1, 2, 2, 2], B = [1, 1, 2, 2, 2], arr3 = [1, 1, 1, 1, 2, 2, 2, 2]
Output: [1, 2]
Explanation: We do not need to consider duplicates
Constraints:
1 <= arr1.size(), arr2.size(), arr3.size() <= 105
-105 <= arr1i , arr2i , 1arr3i <= 105

*/

//TIME COMPLEXITY:  O(n1 + n2 + n2)
//SPACE COMPLEXTIY: O(n), where n = n1 = n2 = n3

#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        
        vector<int> ans;
        
        int i,j,k;
        i=j=k=0;
        while(i<arr1.size() && j<arr2.size() && k<arr3.size())
        {
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k])
            {
                if(ans.empty() || ans.back()!=arr1[i])
                { 
                    ans.push_back(arr1[i]);
                }
                i++, j++, k++;
            }
            else if(arr1[i] < arr2[j])
            {
                i++;
            }
            else if (arr2[j] < arr3[k])
            {
                j++;
            }
            else //arr3[k] is less
            {
                k++;
            }
            
        }
        
         if(ans.empty()) 
            ans.push_back(-1);
            
        return ans;
    }
};
