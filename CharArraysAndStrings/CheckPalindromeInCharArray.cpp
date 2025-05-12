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

bool checkPalindrome(char arr[], int size)
{
    int len = getLength(arr, size);
    cout<<"len: "<<len<<endl;
    int s = 0;
    int e = len - 1; 
    while(s<=e)
    {   
        //Remember about lower case and upper case.
        if(arr[s] == arr[e]) 
        {
            s++;
            e--;
        }
        else
        {   cout<<"Not a palindrome"<<endl;
            return false;
        }
    }
    cout<<"Palindrome"<<endl;
    return true;
}

int main()
{
    char arr[100];
    cin>>arr;
    cout<<checkPalindrome(arr, 100)<<endl;
    cin>>arr;
    cout<<checkPalindrome(arr, 100)<<endl;
    cin>>arr;
    cout<<checkPalindrome(arr, 100)<<endl;
    return 0;
}



