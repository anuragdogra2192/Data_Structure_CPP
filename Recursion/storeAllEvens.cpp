#include<iostream>
#include<vector>
using namespace std;

void storeAllEvens(int arr[], int size, int index, vector<int>& store)
{
    //base case
    if(index == size)
    {//All traversed
        return;
    }
    //1k case mein solve karunga
    if(arr[index]%2 == 0) //true means its even
    {
        store.push_back(arr[index]);
    }
    //Baaki recursion sambhal lega
    storeAllEvens(arr, size, index+1, store);
}

int main()
{
    int arr[] = {10, 15, 17, 40, 53, 61, 10};
    int size = 7;
    vector<int> store;
    storeAllEvens(arr, size, 0, store);
    for(auto i : store)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}