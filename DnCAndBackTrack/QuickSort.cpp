/* Geek for Geeks
Quick Sort
Difficulty: MediumAccuracy: 55.23%Submissions: 271K+Points: 4Average Time: 15m
Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order. Given an array, arr[], with starting index low and ending index high, complete the functions partition() and quickSort(). Use the last element as the pivot so that all elements less than or equal to the pivot come before it, and elements greater than the pivot follow it.

Note: The low and high are inclusive.

Examples:

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After sorting, all elements are arranged in ascending order.
Input: arr[] = [2, 1, 6, 10, 4, 1, 3, 9, 7]
Output: [1, 1, 2, 3, 4, 6, 7, 9, 10]
Explanation: Duplicate elements (1) are retained in sorted order.
Input: arr[] = [5, 5, 5, 5]
Output: [5, 5, 5, 5]
Explanation: All elements are identical, so the array remains unchanged.
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 105

Time Complexity - avg case, O(nlogn) and best case too
                - worst case O(n^2); decreasing order array
                - Big O(n^2)

*/

#include<vector>
using namespace std;

class Solution {
    public:
      // Function to sort an array using quick sort algorithm.
      void quickSort(vector<int>& arr, int start, int end) {
          // code here
          if(start>=end)
          {
              return;
          }
          int pivot = end;
          int i = start-1;
          int j = start;
          
          while(j < pivot)
          {
              if(arr[j] < arr[pivot])
              {
                  ++i;
                  swap(arr[i], arr[j]);    
              }
              j++;
          }
          i++;
          swap(arr[i], arr[pivot]);
          //left 
          quickSort(arr, start, i-1);
          //Right 
          quickSort(arr, i+1, end);
      }
  
    public:
      // Function that takes last element as pivot, places the pivot element at
      // its correct position in sorted array, and places all smaller elements
      // to left of pivot and all greater elements to right of pivot.
      int partition(vector<int>& arr, int low, int high) {
          
          // Not used
      }
  };