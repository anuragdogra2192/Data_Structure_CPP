/*
------
4
*
* *
* * *
* * * *
* * *
* *
*
------
*/
#include<iostream>

using namespace std;

void printPattern(int n)
{   
    for(int r=0; r<=2*(n-1); r++)
    {   
        if(r<n)
        {
            for(int c=0; c<r+1; c++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
        else
        {
            for(int c=0; c<2*(n-1)-r+1; c++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    printPattern(n);
    return 0;
}