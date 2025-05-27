#include<iostream>

using namespace std;

void printAllOdds(int arr[], int size, int index)
{
    //base case
    if(index == size)
    {//All traversed
        return;
    }
    //1k case mein solve karunga
    if(arr[index] & 1) //true means its odd
    {
        cout<< arr[index] <<" ";
    }
    //Baaki recursion sambhal lega
    printAllOdds(arr, size, index+1);
}

int main()
{
    int arr[] = {10, 15, 17, 40, 53, 61, 10};
    int size = 7;
    printAllOdds(arr, size, 0);
    cout<<endl;
    return 0;
}
