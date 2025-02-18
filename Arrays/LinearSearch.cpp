#include<iostream>

using namespace std;

void input(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<"Enter the value: "<<" ";
        cin>>arr[i];
    }
    cout<<endl;
}

bool findTarget(int arr[], int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(target == arr[i])
            return true;
    }
    return false;
}

int main()
{
    int arr[100];
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int target = 100;
    input(arr, size);
    bool found = false;
    found = findTarget(arr, size, target);
    if(found)
    {
        cout<<"Found the target"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    
    target = 200;
    found = findTarget(arr, size, target);

    if(found)
    {
        cout<<"Found the target"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    
}