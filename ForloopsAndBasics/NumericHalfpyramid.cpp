#include<iostream>

using namespace std;

void printNumericHalfPyramid(int nrows)
{
    //r - row 
    //c - col
    for(int r=0; r<nrows; r++)
    {   
        for(int c = 0; c<r+1; c++)
        {
            cout<<c+1;
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    printNumericHalfPyramid(n);
    return 0;
}
