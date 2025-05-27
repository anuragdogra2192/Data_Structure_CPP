#include<iostream>
using namespace std;

void maxInArray(int arr[], int size, int index, int& maxAns)
{   //int& maxAns, pass by reference is important here.
    //Base Case
    if(index == size)
    {
        //Entire array traversed
        return;
    }
    //Recursion relation
    //1k case mein solve karunga
    maxAns = max(maxAns, arr[index]);
    //Baaki recursion sambhal lega
    maxInArray(arr, size, index+1, maxAns);
}

int main()
{
    int arr[] = {10, 120, 30 , 40, 50, 60};
    int size = 6;
    int maxAns = INT_MIN;
    maxInArray(arr, size, 0, maxAns);
    cout<<"Max Ans is "<<maxAns<<endl;
    return 0;
}