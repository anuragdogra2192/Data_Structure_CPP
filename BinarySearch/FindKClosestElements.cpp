/* Leet Code: 658
658. Find K Closest Elements

Given a sorted integer array arr, two integers k and x, 
return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]

 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104
*/
class Solution {
public:
    int lowerBound(vector<int>& arr, int x)
    {
        int s = 0;
        int e = arr.size()-1;
        int ans = e;//if end is less than x. Yeah edge case bhule sakte hai.
        int mid = s + (e-s) / 2;
        while(s<=e)
        {
            if(x == arr[mid])
            {
                //May more occuences of the same number exists.
                //Store
                ans = mid;
                //Compute
                e = mid - 1;
            }
            else if(x > arr[mid])
            {
                s = mid + 1;
            }
            else
            {//x < arr[mid]
             //Store - may be an ans. 
                ans = mid;
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

    vector<int> binarySearchMethod(vector<int>& arr, int k, int x) 
    {   
        //Time Complexity O(log(n)) + O(k)
        //Space Complexity O(k)
        int index = lowerBound(arr, x);
        //Now we form window [L, H] and expand it to k size.
        int l = index - 1;
        int h = index;
        while(k>0)
        {   //Edge case
            if(l<0)// Expand to the right if left index is out of bounds
            {
                h++;
            }
            else if(h>=arr.size())// Expand to the left if right index is out of bounds
            {
                l--;
            }
            else if(abs(arr[h] - x) < abs(x - arr[l]))
            {//expanding on the right
                h++;
            }
            else {//(arr[h] - x) >= (x - arr[l]), arr[l]<arr[h]
            //Expanding on the left
                l--;
            }
            k--;
        }
        // Ensure indices are within bounds
        //l = max(l, -1); // l + 1 must be >= 0
        //h = min(h, (int)arr.size()); // h must be <= arr.size()
        //Our subvector is in [l+1, h)
        return vector<int>(arr.begin()+l+1, arr.begin()+h);
    }

    vector<int> TwoPointers(vector<int>& arr, int k, int x) 
    {
        //Two pointer approach
        //Time Complexity O(n)
        //Sapce Complexity O(k)
        int low = 0;
        int high = arr.size()-1;

        while((high - low) >= k)
        {
            if((x-arr[low]) > (arr[high]-x))
            {
                low++;
            }
            else //(arr[low]-x) <= (arr[high]-x), arr[low] < arr[high]
            {
                high--;
            }
        }

        return vector<int>(arr.begin() + low, arr.begin() + high + 1);
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        //return TwoPointers(arr, k, x);
        return binarySearchMethod(arr, k, x);
    }
};