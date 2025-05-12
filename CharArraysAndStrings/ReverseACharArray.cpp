#include<iostream>
using namespace std;

int getLength(char arr[], int size)
{   //Time Complexity - O(N)
    //Space Complexity - O(1)
    int length = 0;
    for(int i=0; i<size; i++)
    {
        if(arr[i] == '\0')
        {
            return length;
        }
        length++;
    }
    return length;
}

void reverseACharArray(char arr[], int n)
{
    int len = getLength(arr, n);
    cout<<"length: "<<len<<endl;
    int s = 0;
    int e = len-1;
    while(s<=e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main()
{
    char arr[1000];
    cin>>arr;
    cout<<"String: "<<arr<<endl;
    reverseACharArray(arr, 1000);
    cout<<"Reverse: "<<arr<<endl;
    return 0;
}