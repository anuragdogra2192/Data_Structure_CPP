#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target, int start, int end)
{   
    int ansIndex = -1;
    //Base Case
    //Base case 1
    if(start > end)
    {
        return -1;
    }

    int mid = start + ((end - start)/2);
    //1k case mein karunga
    if(arr[mid] == target)
    {
        return mid;
    }
    //Baaki case recursion sambhalega
    //arr[mid] < target
    if(target > arr[mid])
    {//Right mein jao
        ansIndex = binarySearch(arr, size, target, mid+1, end);
    }
    else//(target < arr[mid])
    {//left mein jao
        ansIndex = binarySearch(arr, size, target, start, mid-1);
    }
    return ansIndex;
}

int main()
{
    int arr[] = {10, 20 , 30, 45, 50, 67, 78, 89,90};
    int size = 9;
    int target = 50;

    int start = 0;
    int end = size - 1;
    int ansIndex = binarySearch(arr, size, target, start, end);
    cout<<ansIndex<<endl;
    return 0;
}