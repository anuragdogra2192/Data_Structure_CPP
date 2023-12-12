/*
8
**** ****
***   ***
**     **
*       *
*       *
**     **
***   ***
**** ****
*/

#include<iostream>

using namespace std;

void printUpperPattern(int n)
{
    int nrows = n/2;

    for(int r=0; r<nrows; r++)
    {   
        //first half pyramid
        for(int c=0; c<nrows-r; c++){
            cout<<"*";
        }
        //Second Space Pyramid
        for(int c=0; c<2*r+1; c++){
            cout<<" ";
        }

        //third half pyramid
        for(int c=0; c<nrows-r; c++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void printLowerPattern(int n)
{
    int nrows = n/2;

    for(int r=0; r<nrows; r++)
    {   
        //first half pyramid
        for(int c=0; c<r+1; c++){
            cout<<"*";
        }
        //Second Space Pyramid
        for(int c=0; c<(2*nrows-2*r)-1; c++){
            cout<<" ";
        }
        //third half pyramid
        for(int c=0; c<r+1; c++){
            cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    printUpperPattern(n);
    printLowerPattern(n);
    return 0;
}