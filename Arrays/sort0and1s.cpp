#include<iostream>
using namespace std;

void sortZeroOne(int arr[], int n)
{
    int zeroCount = 0;
    int oneCount = 0;

    //counting 
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            zeroCount++;
        }
        if(arr[i] == 1)
        {
            oneCount++;
        }
    }

    //Insertion
    int i = 0;
    for(; i<zeroCount; i++)
    {
        arr[i] = 0;
    }
    for(; i<n; i++)
    {
        arr[i] = 1;
    }

}

int main()
{
    int arr[] = {0,1,1,1,0,0,0,1,1};
    int n = 9;
    sortZeroOne(arr, n);
    
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
    
    return 0;
}