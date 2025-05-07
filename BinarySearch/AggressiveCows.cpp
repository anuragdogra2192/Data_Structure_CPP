/*
Geek for geeks
Aggressive Cows

You are given an array with unique elements 
of stalls[], which denote the position of a stall. 
You are also given an integer k which denotes the number of aggressive cows. 
Your task is to assign stalls to k cows 
such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
2 <= k <= stalls.size()
*/
//{ Driver Code Starts
// Initial function template for C++

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool possibleSoln(vector<int>&stalls, int k, int minDist)
    {
        // minDist between we need to have b/w cows
        // Need to maximize the minDist
        int c = 1; //counter for cows
        int pos = stalls[0]; //first cow is placed at pos 0;
        for(int i=1; i<stalls.size(); i++)
        {
            if(stalls[i] - pos >= minDist)
            {
                c++;
                pos = stalls[i]; //One more cow is placed
            }
            if(c == k) //All cows are placed.
            {
                return true;
            }
        }
        return false;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int s = 0;
        int n = stalls.size();
        int e = stalls[n-1] - stalls[0];
        
        int mid = s + (e-s)/2;
        int ans = -1;
        
        while(s<=e)
        {
            if(possibleSoln(stalls, k, mid))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends