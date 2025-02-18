/*
Reverse an array at a after a given index, if index is 0 then reverse all elements
*/

#include<iostream>
#include<vector>

using namespace std;

void reversed(vector<int>& arr, int m=0)
{
    int s = 0;
    if(m!=0) { s = m+1;}

    int e = arr.size()-1;
    
    while(s<=e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void print(const vector<int>& v)
{
    int s = 0;
    int e = v.size() - 1;

    while(s<=e)
    {
        cout<< v[s] << " ";
        s++;
    }
    cout<<endl;
}

int main()
{
    vector<int> v1 = {11, 7, 5, 4, 12};
    int m = 0;

    reversed(v1, m);
    print(v1);
    
    vector<int> v2 = {11, 7, 5, 4, 12};
    int n = 1;

    reversed(v2, n);
    print(v2);

    return 0;
}