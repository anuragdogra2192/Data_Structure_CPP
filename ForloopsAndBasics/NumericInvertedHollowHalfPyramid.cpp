#include<iostream>
/*
5
12345
2  5
3 5
45
5
*/

using namespace std;

void printPattern(int n)
{
    // LOVE BABBAR's
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {   
            if(j==i+1 || j==n || i==0)
            {
              cout<<j;
            }
            else
            {
                cout<<" ";
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