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

int main()
{
    char arr[100] = "Hello World";
    cout<<arr<<endl;
    cout<<"Length is: "<<getLength(arr, 100)<<endl;
    cin>>arr;
    cout<<"Length is: "<<getLength(arr, 100)<<endl;
    return 0;
}
