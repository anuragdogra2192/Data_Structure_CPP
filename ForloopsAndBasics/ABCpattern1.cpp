/*
input: 4

A 
AB
ABC
ABCD
*/

#include<iostream>

using namespace std;
void printPattern(int n)
{
    for(int r=0; r<n; r++)
    {
        for(int c=0; c<r+1; c++)
        {
            //Char masking with number;
            // 0 -> 'A'
            // 1 -> 'B'
            // :
            // :
            // 26 -> 'Z'
            char ch = c + 1 + 'A' - 1;
            cout<<ch;
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    printPattern(n);
    return 0;
}