#include<iostream>

using namespace std;

/*
Assumption it is strictly increasingly order
To check
a[i+1] > arr[i];

//base case - ruk jao condition
if index+1 == size
//recursive relation
*/

bool checkSorted(int arr[], int size, int index)
{  
    //base case
    if(index == size-1)
    {//already traversed, and all are sorted.
     //Also handled the single element situation.
        return true;
    }
    bool currAns = false;
    bool recurAns = false;

    //1K case mein solve karunga 
    if(arr[index + 1] > arr[index])
    {
        currAns = true;
    }
    
    //baaki recursion sambhal lega
    recurAns = checkSorted(arr, size, index+1);
//     if(currAns == true && recurAns == true)
//     {
//         return true;
//     }
//     else
//         return false;
//  Above commented code can be written in one line.
    return (recurAns && currAns);
}

int main()
{
    int arr[] = {10, 20, 40, 45, 50, 60};//true
    //int arr[] = {10, 0, 40, 45, 50, 60};//false
    int size = 6;
    cout<<checkSorted(arr, size, 0)<<endl;
    return 0;
}