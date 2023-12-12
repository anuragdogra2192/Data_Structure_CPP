/*
input: 4

A 
ABA
ABCBA
ABCDCBA
*/

#include<iostream>

using namespace std;
void printPattern(int n)
{
    for(int r=0; r<n; r++)
    {   char ch;
        for(int c=0; c<r+1; c++)
        {
            //Char masking with number;
            // 0 -> 'A'
            // 1 -> 'B'
            // :
            // :
            // 26 -> 'Z'
            ch = c + 1 + 'A' - 1;
            cout<<ch;
        }
        //Jab tak A tak nahi pahunchenge
        //Tab tak print karenge
        for(char alphabet = ch; alphabet>'A';)
        {
            alphabet--;
            cout << alphabet;
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