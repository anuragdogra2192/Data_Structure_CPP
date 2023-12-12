/*
5
    1
   121
  12321
 1234321
123454321
*/

#include<iostream>
using namespace std;

void printPattern(int n)
{
    for(int r=0; r<n; r++)
    {
        //Space
        for(int c=0;c<n-r-1;c++)
        {
            cout<<" ";
        }

        int number = 0;
        for(int c=0;c<r+1;c++)
        {   
            number = c+1;
            cout<<number;
        }
        for(int num=number; num>1;)
        {
            num--;
            cout<<num;
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
    return 0;
}