/* Leet Code 539.
539. Minimum Time Difference

Given a list of 24-hour clock time points in "HH:MM" format, 
return the minimum minutes difference between any two time-points in the list.
 
Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
        int convertToMins(string time)
        {
            int HH = stoi(time.substr(0, 2)); //0 startindex, 2 #chars
            int MM = stoi(time.substr(3, 2)); //3 startindex, 2 #chars
            return HH*60 + MM;
        }
    
        int findMinDifference(vector<string>& timePoints) {
            vector<int> absMins;
            for(auto time : timePoints)
            {
                absMins.push_back(convertToMins(time));
            }
            sort(absMins.begin(), absMins.end());
            //Diff calculation
            int ans = INT_MAX;
            for(int i=0; i<absMins.size()-1; i++)
            {   
                ans = min(ans, (absMins[i+1] - absMins[i]));
            }
            // Now to complete the circle of time, 1440 == 24:00.
            int lastDiff = absMins[0] + 1440 - absMins[absMins.size()-1];
            return ans > lastDiff ? lastDiff : ans;
        }
    };
/*
Big O - O(n log n)	
The time complexity is O(n log n) because the code involves sorting
the 'absMins' vector which has a size of 'n', and 
the sorting operation has a time complexity of O(n log n).
The rest of the operations are linear in nature, so the overall time complexity is dominated by the sorting operation.
*/