#include<iostream>
using namespace std;

void minInArray(int arr[], int size, int index, int& minAns)
{   //int& maxAns, pass by reference is important here.
    //Base Case
    if(index == size)
    {
        //Entire array traversed
        return;
    }
    //Recursion relation
    //1k case mein solve karunga
    minAns = min(minAns, arr[index]);
    //Baaki recursion sambhal lega
    minInArray(arr, size, index+1, minAns);
}

int main()
{
    int arr[] = {10, 120, -1 , -2, 50, 60};
    int size = 6;
    int minAns = INT_MAX;
    minInArray(arr, size, 0, minAns);
    cout<<"Min Ans is "<<minAns<<endl;
    return 0;
}