/*
input: 4

1
1 2
1 2 3
1 2 3 4
*/

#include<iostream>

using namespace std;
void printPattern(int n)
{
    for(int r=0; r<n; r++)
    {
        int count = 1;
        for(int c=0; c<2*r+1; c++)
        {
            if(c%2==1)
            {
                cout<<" ";
            }
            else
            {
                cout<<count;
                count++;
            }
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