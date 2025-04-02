// Leet code Problem: 852. Peak Index in a Mountain Array
// Topics: Binary Search


// Description:
// You are given an integer mountain array `arr` of length `n` where the values 
// increase to a peak element and then decrease. Your task is to return the index 
// of the peak element. Solve it in O(log(n)) time complexity.

// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

// Constraints:
// - 3 <= arr.length <= 10^5
// - 0 <= arr[i] <= 10^6
// - arr is guaranteed to be a mountain array.

class Solution {
public:
    //Better way and easily understandable.
    //Store and compute method.
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;

        int mid = s+(e-s)/2;
        int ansIndex = -1;

        while(s<=e)
        {
            if(arr[mid] < arr[mid+1])
            {//line A - right me jao
                s = mid + 1;
            }
            else
            {   // line B and peak element, means ans exists here 
                //Store. may or may not be the answer.
                ansIndex = mid;
                // and compute.
                e = mid - 1;
            }

            mid = s+(e-s)/2;
        }
        return ansIndex;
    }
    
    // Old way 
    int peakIndexInMountainArray(vector<int>& arr) {
        size_t size = arr.size();
        int s = 0;
        int e = size-1;
        int mid = s + (e-s)/2;

        while(s<e)
        {
            if(arr[mid]<arr[mid+1])
            {
                s = mid+1;
            }
            else
            {
                e = mid;
            }

            mid = s + (e-s)/2;
        }

        return s; //return mid or e or s all lie on the same value in the end.
    }
};