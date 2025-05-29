#include <iostream> 
#include <vector>

using namespace std;
//Using recurssion.
//Time Complexity: O(N^2)
//Space Complexity: O(N+2) ~ O(N)
void printSubArray(vector<int>& arr);
void printSubArrayUtil(vector<int>& arr, int start, int end);

void printSubArrayUtil(vector<int>& arr, int start, int end)
{
    //base case
    if(end == arr.size())
    {
        return;
    }
    //1K case mein karunga
    for(int i=start; i<=end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Baaki recursion sambhal lega
    printSubArrayUtil(arr, start, end+1);
}

void printSubArray(std::vector<int>& arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        printSubArrayUtil(arr, i, i);
    }
}

int main()
{
    vector<int> arr = {1,2,3,4,5}; 
    printSubArray(arr);
    return 0;
}