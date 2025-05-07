/* Geeks for geeks
The Painter's Partition Problem-II
Dilpreet wants to paint his dog's home that 
has n boards with different lengths. 
The length of ith board is given by arr[i] 
where arr[] is an array of n integers.
He hired k painters for this work and 
each painter takes 1 unit time to paint 1 unit 
of the board.

Return the minimum time to get this job done 
if all painters start together with the constraint
that any painter will only paint continuous boards, 
say boards numbered [2,3,4] or only board [1] or
nothing but not boards [2,4,5].

Examples:

Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The most optimal way will be: Painter 1 allocation : [5,10], Painter 2 allocation : [30], Painter 3 allocation : [20,15], Job will be done when all painters finish i.e. at time = max(5+10, 30, 20+15) = 35
Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: The most optimal way to paint: Painter 1 allocation : [10,20,30], Painter 2 allocation : [40], Job will be complete at time = 60
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 1000
Explanation: There is only one painter, so the painter must paint 
all boards sequentially. 
The total time taken will be the sum of all 
board lengths, i.e., 100 + 200 + 300 + 400 = 1000.
*/

//{ Driver Code Starts

#include<iostream>
#include<vector>
#include<numeric>
#include<sstream>

using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool possibleSoln(vector<int>& arr, int k, int maxTime)
    {
        //maxTime - max time it will take to finish painting
        //          which we need to minimize
        int timeSum = 0;
        int c = 1; //count painters
        long long n = arr.size(); 
        for(auto i=0; i<n; i++)
        {
            if(arr[i]>maxTime)
            {
                return false;
            }
            if(timeSum + arr[i] > maxTime)
            {
                c++;
                timeSum = arr[i];
                if(c > k)
                {
                    return false;
                }
            }
            else
            {
                timeSum += arr[i];
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        long long s = 0;
        auto first = arr.begin();
        auto last = arr.end();
        long long e = accumulate(first, last, 0);
        
        long long mid = s + (e-s)/2;
        long long ans = -1;
        
        while(s<=e)
        {
            if(possibleSoln(arr, k, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        
        return ans;
        // return minimum time
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends