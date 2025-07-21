/* Geeks for geeks

Merge two binary Max heaps

Given two binary max heaps as arrays, 
merge the given heaps to form a new max heap.

Example 1:
Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}
Explanation :
Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function mergeHeaps() 
which takes the array a[], b[], its size n and m, 
as inputs and return the merged max heap. 
Since there can be multiple solutions, therefore, 
to check for the correctness of your solution, 
your answer will be checked by the driver code and
will return 1 if it is correct, else it returns 0.
 
Expected Time Complexity: O(n.Logn)
Expected Auxiliary Space: O(n + m)
Constraints:
1 <= n, m <= 105
1 <= a[i], b[i] <= 2*105
*/

// User function Template for C++
#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void Heapify(vector<int>&c, int i, const int& n)
    {//zero indexed hai remember
        int p = i;
        int left = 2*p+1;
        int right = 2*p+2;
        int largestIndex = p;
        if(left<n && c[left] > c[largestIndex])
        {
            largestIndex = left;
        }
        if(right<n && c[right] > c[largestIndex])
        {
            largestIndex = right;
        }
        if(largestIndex!=p)
        {
            swap(c[p], c[largestIndex]);
            p = largestIndex;
            Heapify(c, p, n);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        //merge a and b vector
        //lets create c and. copy a 
        vector<int>c(a.begin(), a.end());
        
        //now copy b
        c.insert(c.end(), b.begin(), b.end());
        
        int csize = c.size();
        
        //Lets heapify,  zeroindexed
        for(int i=csize/2; i>=0; i--)
        {
            Heapify(c, i, csize);
        }
        
        return c;
    }
};