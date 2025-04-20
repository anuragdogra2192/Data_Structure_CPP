#include<iostream>

using namespace std;

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//Select the minimum element in each iteration
// and put it in the right postion

void selectionSort(int *arr, int n)
{
    //Outer for n-1 iterations
    for(int i = 0; i<n-1; i++)
    {   
        int min_index = i;
        //Find the minimum element
        for(int j = i+1; j<n; j++)
        {   
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        //and swap with ith element
        swap(arr[i], arr[min_index]);
    }
}

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int n = 7;

    selectionSort(arr, n);
    cout<<"Sorted: "<<endl;
    print(arr, n);

    int arr1[] = {10, 16, 25, 14, 23, 12, 7};
    n = 7;

    selectionSort(arr1, n);
    cout<<"Sorted: "<<endl;
    print(arr1, n);
    return 0;
}


