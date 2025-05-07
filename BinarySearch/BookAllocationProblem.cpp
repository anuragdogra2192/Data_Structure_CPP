/*
Geek for Geeks
Allocate Minimum Pages

You are given an array arr[] of integers, where each element arr[i] 
represents the number of pages in the ith book. 
You also have an integer k representing the number of students. 
The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. 
In other words, out of all possible allocations, 
find the arrangement where the student who receives 
the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, 
and allotment should be in contiguous order 
(see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.
Input: arr[] = [22, 23, 67], k = 1
Output: 112
Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 103
*/
#include<iostream>
#include<vector>
#include<numeric> 
#include<sstream>

using namespace std;

//{ Driver Code Starts
// Initial function template for C++
// } Driver Code Ends

class Solution {
  public:
    bool possibleSoln(vector<int> &arr, int k, int maxPages)
    {   //maxPages -> At most max pages which can be assigned
        //to each student.
        int c = 1; //Counting students
        int n = arr.size(); //number of books
        int pageSum = 0;
        for(int i = 0; i<n; i++)
        {
            if(arr[i] > maxPages)
            {
                return false; //Can't allocate
            }
            
            if(pageSum + arr[i] > maxPages)
            {
                c++; //Moves to next student
                pageSum = arr[i];
                if(c > k)
                {
                    return false; //can't allocate, no more students
                }
            }
            else
            {
                pageSum += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        // Edge case
            // if #Students > #Books --> return -1;
        if(k > arr.size())
        {
            return -1;
        }
        
        int s = 0;
        auto first = arr.begin();
        auto last = arr.end();
        int e = accumulate(first, last, 0);
        
        int mid = s + (e-s)/2; //s + ((e-s)>>1)
        
        int ans = -1;
        while(s<=e)
        {
            if(possibleSoln(arr, k, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1; 
            }
            mid = s + ((e-s)>>1);
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends