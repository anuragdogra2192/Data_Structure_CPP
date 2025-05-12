#include<iostream> 
using namespace std;

void replaceCharacter(char originalChar, char newChar, char arr[], int size)
{   //Linear Traverse
    //Time Complexity - O(N)
    //Space Complexity - O(1)
    for(int i=0; i<size; i++)
    {
        if(arr[i] == originalChar)
        {
            arr[i] = newChar;
        }
    }
}

int main()
{
    char arr[100];
    cin>>arr;
    cout<<arr<<endl;
    replaceCharacter('@', ' ', arr, 100);
    cout<<arr<<endl;
    return 0;
}