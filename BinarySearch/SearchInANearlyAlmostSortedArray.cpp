/*
Given an array and a target element.
The target can be found in either of the 3 positions
arr[i] or arr[i-1] or arr[i+1]
or we can say element can be found on its position or adjacent positions.
*/

#include<iostream>
using namespace std;

int applyBinarySearch(int arr[], int n, int target)
{
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e)
    {
        if(arr[mid] == target)
        {
            return mid;
        }
        if(arr[mid-1] == target)
        {
            return mid-1;
        }
        if(arr[mid+1] == target)
        {
            return mid+1;
        }
        if(target > arr[mid])
        {//right mein jao
            s = mid+2; //Because m+1 is already checked
        }
        else
        {//left mein jao
            e = mid-2; //Because m-1 is already checked
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int n = 7;
    int target = 40;
    int ans = applyBinarySearch(arr, n, target);
    cout<<"Answer index: "<<ans<<endl;
    return 0;
}