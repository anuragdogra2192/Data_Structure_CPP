//Time complexity - O(N^2)

#include<iostream>
using namespace std;

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<endl;
}

void bubbleSort(int *arr, int n)
{
    //[0, n - 1), outer loop for iterations
    // After every iteration n-i is sorted
    //innner loop for comparisions n-i-1
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
        //cout<<"Iteration "<<i<<endl;
        //print(arr, n);
    }
    //All sorted.
}

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int n = 7;

    bubbleSort(arr, n);
    cout<<"Sorted: "<<endl;
    print(arr, n);

    int arr1[] = {10, 16, 25, 14, 23, 12, 7};
    n = 7;

    bubbleSort(arr1, n);
    cout<<"Sorted: "<<endl;
    print(arr1, n);

    return 0;
}