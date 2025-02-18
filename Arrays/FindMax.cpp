#include<iostream>
#include<limits.h>

using namespace std;

int findMax(int arr[], int size)
{
    int maxAns = INT_MIN;
    for(int i = 0; i < size; i++)
    {
        maxAns = max(arr[i], maxAns);

        //Alternative
        // if (arr[i] > maxAns)
        // {
        //     maxAns = arr[i];
        // }
    }
    return maxAns;
}

int main()
{
    int crr[] = {10, 20, 40, 70};
    int size = 4;
    cout<<"Max Value: "<<findMax(crr,4)<<endl;

    int brr[] = {10, 20, 60, 90};
    cout<<"Max Value: "<<findMax(brr,4)<<endl;

    int arr[] = {10, 200, 40, 70};
    cout<<"Max Value: "<<findMax(arr,4)<<endl;
    return 0;
}