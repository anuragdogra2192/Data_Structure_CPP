#include<iostream>
#include<vector>

using namespace std;

void mergeSortedArrays(int arr1[], int m, int arr2[], int n, vector<int>& ans)
{
    int i = 0, j = 0;
    while(i<m && j<n)
    {
        if(arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    //Check for remaining elements in the Array
    for(; i<m; i++)
    {
        ans.push_back(arr1[i]);
    }
    for(; j<n; j++)
    {
        ans.push_back(arr2[j]);
    }
}

int main()
{
    int arr1[] = {10, 20, 30, 40, 50, 60};
    int m = 6;
    int arr2[] = {11, 21, 34, 45, 65, 70};
    int n = 6; 
    vector<int>ans;
    mergeSortedArrays(arr1, m, arr2, n, ans);
    for(auto a : ans)
    {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
