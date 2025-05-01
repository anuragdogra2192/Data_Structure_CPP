/*
Exponential Search 
also called as:
* Doubling Search or Golloping Search or Stranlic Search
Applicaltions:
1) Search in unbounded array or infinite array
2) Better than Binary Search if target is near beginning.

Time Complexity:
1) Finding an end index - m
   O(log_base2_m) 
   For example: m = 16
   => Time complexity O(log16) = log_base_2(2^4) = 4 steps.
2) Binary Search on subarray. 
   From previous example m = 16
   - previous step 8
   16 - 8 = 2^4 - 2^3 => 2^(log m) - 2^(log(m) - 1)
   => 2^(log m) - 2^(log m).2^(-1)
   => 2^(log m)(1 - 2^(-1))
   => 2^log(m)/2
   => 2^(log(m)-1) ---> time complexity
   => 2^(log(16)-1) => 2^(4-1) => 2^3
*/
#include<iostream>
using namespace std;
int binarySearch(int arr[], int s, int e, int target)
{
    int mid = s + (e-s)/2; 
    while(s<=e)
    {
        if(target == arr[mid])
        {
            return mid;
        }
        else if(target > arr[mid])
        {
            s = mid+1;
        }
        else//target <  arr[mid]
        {
            e = mid-1;
        }
        mid =  s + (e-s)/2; 
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int target)
{
    if(arr[0]==target)
        return 0;

    int i = 1;
    while(i<n && arr[i]<=target)
    {
        if(arr[i] == target)
        {
            return i;
        }
        else
        {
            i*=2;// i = i << 1 // i = i*2; 
        }
    }
    return binarySearch(arr, i/2, min(i, n-1), target);
}

int main()
{
    int arr[] = {10, 20, 20, 30 ,40, 50, 60 ,70, 80};
    int n = 9;
    int target = 50;
    int ans = exponentialSearch(arr, n, target);
    cout<<"Answer index " << ans <<endl; 
    return 0; 
}