#include<iostream>

using namespace std;

void insertSort(int *arr, int n)
{
    for(int i=1; i<n; i++)
    {   
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int n = 7;

    insertSort(arr, n);
    cout<<"Sorted: "<<endl;
    print(arr, n);

    int arr1[] = {10, 16, 25, 14, 23, 12, 7};
    n = 7;

    insertSort(arr1, n);
    cout<<"Sorted: "<<endl;
    print(arr1, n);
    return 0;
}