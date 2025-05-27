#include<iostream>
using namespace std;
//Linear search in Recursive way.
bool searchInArray(int arr[], int size, int index, int target)
{
    //base case
    //1) Not found, invalid index, our of bound
    if(index ==  size)
    {
        return false;
    }
    //2) Found ya 1k case mein check karunga
    if(arr[index] == target)
    {
        return true;
    }
    //recursive relation
    bool ans = searchInArray(arr, size, index+1, target);
    
    return ans;
    //processing - optional
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int target = 50;
    int size = 6;
    cout<< searchInArray(arr, size, 0, 50)<<endl;
    cout<< searchInArray(arr, size, 0, 100)<<endl;
    return 0;
}