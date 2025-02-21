#include<iostream>

using namespace std;

void extremePrinting(int arr[], int size)
{
    int s = 0;
    int e = size-1;

    while(s <= e)
    {
        cout<< arr[s]<<" ";
        s++;
        if(e>s)
        {
            cout<< arr[e]<<" ";
            e--;
        }
    }
}

int main()
{
    int crr[] = {10, 20, 40, 70};
    int size = 4;
    extremePrinting(crr, 4);
    cout<<endl;
    int arr[] = {10, 20, 30, 40, 50};
    extremePrinting(arr, 5);
    return 0;
}