/*
Input: 5
    Butterfly
*                 * 
* *             * *
* * *         * * *
* * * *     * * * *
* * * * * * * * * *
* * * * * * * * * *
* * * *     * * * *
* * *         * * *
* *             * *
*                 *
*/

#include<iostream>
using namespace std;

void printPattern(int n)
{
    for(int r=0; r<2*n;r++)
    {
        for(int c=0; c<2*n; c++)
        {
            if(r<n)
            {
                if(c<r+1 || c>=2*n-r-1)
                {
                    cout<<"* ";
                }
                else
                {
                    cout<<"  ";
                }
            }
            else
            {
                if(c<2*n-r || c>=r)
                {
                    cout<<"* ";
                }
                else
                {
                    cout<<"  ";    
                }
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