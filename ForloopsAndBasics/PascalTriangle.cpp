/*

5
1 
1 1
1 2 1
1 3 3 1
1 4 6 4 1

Pascal triangle
Binomial Coefficient
Formula:
C = 1 
C = C * (i-j) / j;
i = [1,n];
j = [1, i];
*/

#include<iostream>

using namespace std;

void PascaTriangle(int n)
{
    for(int i=1; i<=n; i++)
    {
        int C=1;
        for(int j=1; j<=i; j++)
        {
            cout<<C<<" ";
            C = C * (i - j)/j;
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    PascaTriangle(n);
    return 0;
}