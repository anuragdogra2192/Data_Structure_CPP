/*
U ----> L
CH - 'A' + a --> ch 
L ----> U
ch - 'a' + 'A' --> CH
*/

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

//Time Cmplexity: O(N)
//Space Complexity: O(1)
void toLower(char arr[], int n)
{
    int len = getLength(arr, n);
    
    for(int i=0; i<len; i++)
    {   
        char ch = arr[i];
        //only convert if ch is upper case.
        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
            arr[i] = ch;
        }
    }
}

void toUpper(char arr[], int n)
{   
    int len = getLength(arr, n);
    
    for(int i=0; i<len; i++)
    {   
        char ch = arr[i];
        //only convert if ch is lower case.
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
            arr[i] = ch;
        }
    }
}

int main()
{   
    char arr[100];
    cout<<"Enter a string: "<<endl;
    cin>>arr;
    
    toLower(arr, 100);
    cout<<"Lower case: "<<arr<<endl;
    toUpper(arr, 100);
    cout<<"Upper case: "<<arr<<endl;
    return 0;
}
