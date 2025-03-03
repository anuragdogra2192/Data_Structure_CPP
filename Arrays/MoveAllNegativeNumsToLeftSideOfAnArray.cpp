#include<iostream>
using namespace std;

//Time complexity - O(N), Space Complexity - O(1)
//Two pointer methods.
void moveAllNegToLeft(int* a, int n)
{
    int l=0, h=n;

    while(l<h)
    {
        if(a[l] < 0)
        {
            l++;
        }
        else if(a[h] > 0)
        {
            h--;
        }
        else
        {
            swap(a[l], a[h]);
        }
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
    int a[] = {1, 2, -3, 4, -5, 6};
    int n = sizeof(a)/sizeof(int);

    moveAllNegToLeft(a, n);
    print(a, n);
    return 0;
}