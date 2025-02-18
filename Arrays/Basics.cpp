#include<iostream>
using namespace std;

void inputArray(int arr[], int size) //arr[] - array representation, 
//                                     array is always pass by reference.
{
    for(int i=0; i<size; i++)
    {
        cout<<"Enter the value for index: "<<i<<endl;
        cin>>arr[i];
    }
}


void print(int arr[],int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[10];    
    //error - int brr[]; --> not initialized so we don't know the size.
    int crr[] = {10, 20, 40, 70};
    int drr[4] = {0};

    cout<< drr[0] <<endl;
    cout<< drr[2] <<endl;
    cout<< drr[3] <<endl;

    cout<< crr[3] <<endl;

    int trr[4];//Address arr__arr+1__arr+2__arr+3__arr+4
               //Index       0      1      2      3 
    std::fill(arr, arr+4, 23);// filling one value in whole array
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;

    int array1[3];
    inputArray(arr, 3);
    print(arr,3);

//NOTES:
    /*
    arr[i] -> value present at [base address + datatype_size X i]
    */
    //Both are same arr[i] ---- i[arr]
    // From complier
    // arr[i] = *(arr + i)
    // i[arr] = *(i + arr)

    return 0;
}