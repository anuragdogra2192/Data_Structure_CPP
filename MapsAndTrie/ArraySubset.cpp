/* Geeks for geeks:
Array Subset

Given two arrays a[] and b[], your task is to 
determine whether b[] is a subset of a[].

Examples:
Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
Output: true
Explanation: b[] is a subset of a[]
Input: a[] = [1, 2, 3, 4, 4, 5, 6], b[] = [1, 2, 4]
Output: true
Explanation: b[] is a subset of a[]
Input: a[] = [10, 5, 2, 23, 19], b[] = [19, 5, 3]
Output: false
Explanation: b[] is not a subset of a[]
Constraints:
1 <= a.size(), b.size() <= 105
1 <= a[i], b[j] <= 106

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(n)
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int, int> mapFreq;
        //map hashing using a
        for(int i=0; i<a.size(); i++)
        {
            mapFreq[a[i]]++;
        }
        //Check b in mapFreq
        for(auto i : b)
        {
            if(mapFreq.find(i) == mapFreq.end())
            {//absent
                return false;
            }
            else
            {
                if(mapFreq[i] > 0)
                {
                    mapFreq[i]--;
                }
                else
                {//mapFreq[i] == 0
                    // 0 occurence found
                    return false;
                }
            }
        }
        return true;
    }
};