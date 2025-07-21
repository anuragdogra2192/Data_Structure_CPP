/* Geeks for geeks
Merge k Sorted Arrays
https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

Given k sorted arrays arranged in the form of a matrix of size k * k. 
The task is to merge them into one sorted array. 
Return the merged sorted array 
( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).


Examples :

Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
Expected Time Complexity: O(k2*Log(k))
Expected Auxiliary Space: O(k2)

Constraints:
1 <= k <= 100

Time Complexity
Each of the k² elements is inserted and removed from the min-heap once.
Each heap operation (push/pop) takes O(log k) time (since the heap size is at most k).
Total time complexity:
O(k² log k)
Space Complexity
The min-heap stores at most k elements at any time: O(k)
The output array stores k² elements: O(k²) (required for the result)
Auxiliary space (excluding output): O(k)

Time: O(k² log k)
Space: O(k) auxiliary
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Info
{
  public:
  int data;
  int rIndex;
  int cIndex;
  
  Info(int x, int y, int z)
  {
      data = x;
      rIndex = y;
      cIndex = z;
  }
};

class compare
{
  public:
  bool operator()(Info* a, Info* b)
  {
     return a->data > b->data; //Min heap
     //return a->data < b->data; //Max heap
  }
};

class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        priority_queue<Info*, vector<Info*>, compare> pq;
        vector<int> ans;
        int totalRows = arr.size();
        int totalColumns = arr[0].size();
        //process k elements
        //hr array ka first element
        //First element from each row
        for(int row=0; row<totalRows; row++)
        {
            int element = arr[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);
        }
        
        //main logic
        while(!pq.empty())
        {
            Info* front = pq.top();
            pq.pop();
            //include in answer
            int frontdata = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;
            ans.push_back(frontdata);
            
            //check if aage data hai frontelement ke, then push it in the minHeap
            if(front_cIndex+1 < totalColumns)
            {   
                int element = arr[front_rIndex][front_cIndex+1];
                Info* temp = new Info(element, front_rIndex, front_cIndex+1);
                pq.push(temp);
            }
        }
        return ans;
    }
};