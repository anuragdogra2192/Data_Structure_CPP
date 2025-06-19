/** GFG Count Inversions
 * Link: https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
 * Really important from Interview Perspective.
 * Based on Merge Sort Approach
 * Count Inversions
Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:
Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104

Time complexity: O(nlogn)
Space complexity: O(n) 
*/
//The merge sort way.
#include<iostream>
using namespace std;

class Solution {
  public:
    
    void merge(vector<int>&arr, int s, int e, int mid, int& count)
    {
        int leftLength = mid - s + 1;
        int rightLength = e - mid;
        
        //create left array
        int* leftArr = new int[leftLength];
        //create right array
        int* rightArr = new int[rightLength];
        
        int index = s; //main arr index
        //Fill the arr
        for(int i=0; i<leftLength; i++)
        {
            leftArr[i] = arr[index];
            index++;
        }
        for(int i=0; i<rightLength; i++)
        {
            rightArr[i] = arr[index];
            index++;
        }
        
        //Now we need to merge them
        int leftIndex = 0;
        int rightIndex = 0;
        int mainArrIndex = s;
        while((leftIndex<leftLength) && (rightIndex<rightLength))
        {
            if(leftArr[leftIndex] <= rightArr[rightIndex])
            {
                arr[mainArrIndex++] = leftArr[leftIndex++];
            }
            else //if(leftArr[leftIndex] > rightArr[rightIndex])
            {
                arr[mainArrIndex++] = rightArr[rightIndex++];
                count = count + (leftLength - leftIndex);
                //cout<<count<<" ";
            }
        }
        
         while(leftIndex < leftLength)
        {
            arr[mainArrIndex] = leftArr[leftIndex];
            mainArrIndex++;
            leftIndex++;
        }

        while(rightIndex < rightLength)
        {
            arr[mainArrIndex] = rightArr[rightIndex];
            mainArrIndex++;
            rightIndex++;
        }
        delete[] rightArr;
        delete[] leftArr;
    }
    
    void mergeSort(vector<int>&arr, int s, int e, int& count)
    {
        //base case
        if(s>=e) //Outbound and single element handled
        {//Single element array is always a sorted one
            return;
        }
        
        int mid = s+(e-s)/2;
        
        //Leftpart
        mergeSort(arr, s, mid, count);
        //Rightpart
        mergeSort(arr, mid+1, e, count);
        
        //merge left and right
        merge(arr, s, e, mid, count);
    }
    
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int s = 0;
        int e = arr.size()-1;
        int count = 0;
        mergeSort(arr, s, e, count);
        return count;
    }
};
