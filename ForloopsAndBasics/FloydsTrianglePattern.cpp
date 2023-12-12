/*
Input: 7

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21
22 23 24 25 26 27 28

*/
#include<iostream>
using namespace std;
void FloydsTriangle(int n)
{
    int id=0;
    for(int r=0; r<n; r++)
    {
        for(int c=0; c<r+1; c++)
        {   
            id++;
            cout<<id<<" ";
        }
        cout<<endl;
        //id++;
    }
}

int main()
{
    int n;
    cin>>n;
    FloydsTriangle(n);
    return 0;
}