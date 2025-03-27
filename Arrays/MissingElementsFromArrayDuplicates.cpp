/*
Question: Missing elements from an array with duplicates.
i/p: [1, 3, 5, 3, 4] 
n - size of array
a[i] belongs to [1, n]
*/

#include<iostream>

using namespace std;

void missingElements(int *a, int n)
//Method 1: visited method
//T.C: O(N)
//S.C: O(1)
{
    for(int i=0; i<n; i++)
    {
        int index = abs(a[i]);
        if(a[index - 1] > 0)
        {
            a[index - 1] *= -1;
        }
    }

    //Lets print the current state
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    //print positive integers which are missing 
    for(int i=0; i<n; i++)
    {
        if(a[i] > 0)
            cout<< i+1 <<" ";
    }
    cout<<endl;
}

//Method - 2
// Sorting + Swapping method
//T.C: O(N)
//S.C: O(1)
void missingElementsSortSwap(int *a, int n)
{
    int i=0;
    while(i<n)
    {
        int index = a[i] - 1;
        if(a[i] != a[index])
        {
            //swap(a[i], a[index]);
            a[i] =  a[i] + a[index];
            a[index] = a[i] - a[index];
            a[i] = a[i] - a[index];
        }
        else
        {
            ++i;
        }
    }

    cout<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    //Print missing elements
    for(int i=0; i<n; i++)
    {
        if(a[i]!=i+1)
        {
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
}


int main()
{
    int a[] = {1,3,5,3,4,1};
    missingElements(a, 6);
    int a1[] = {1,2,2};
    missingElements(a1, 3);

    missingElementsSortSwap(a, 6);
    missingElementsSortSwap(a1, 3);
    return 0;

}