#include<iostream>
#include<limits.h>
//TC O(N)
using namespace std;

int findMin(int arr[], int size)
{
    int minAns = INT_MAX;
    for(int i = 0; i < size; i++)
    {
        minAns = min(arr[i], minAns);
        //Alternative
        // if (arr[i] < minAns)
        // {
        //     minAns = arr[i];
        // }
    }
    return minAns;
}

int main()
{
    int crr[] = {10, 20, 40, 70};
    int size = 4;
    cout<<"Min Value: "<<findMin(crr,4)<<endl;

    int brr[] = {5, 20, 60, 90};
    cout<<"Min Value: "<<findMin(brr,4)<<endl;

    int arr[] = {4, 200, 40, 70};
    cout<<"Min Value: "<<findMin(arr,4)<<endl;
    return 0;
}

