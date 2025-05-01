/*
Search in an infinite array / unbounded array.

Similar to Exponential Search, 
but we don't know the end of the array.

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

int exponentialSearchUnBound(int arr[], int target)
{
    if(arr[0] == target)
        return 0;

    int i = 0;
    int j = 1;
    while(arr[j] < target) //Remember tyo compare with j index, not with i -> leads to out of bound.
    {
        i = j;
        j = j*2;
    }
    //Here we get the window i to j
    std::cout<<"Start: "<<i<<" End: "<<j;
    return binarySearch(arr, i, j, target);
}

int main()
{
    int arr[] = {10, 20, 20, 30 ,40, 50, 60 ,70, 80};
    int target = 50;
    int ans = exponentialSearchUnBound(arr, target);
    cout<<"Answer index " << ans <<endl; 
    return 0; 
}