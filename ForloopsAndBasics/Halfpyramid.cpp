#include<iostream>

using namespace std;

void printHalfPyramid(int nrows)
{
    //r - row 
    //c - col
    for(int r=0; r<nrows; r++)
    {
        for(int c = 0; c<r+1; c++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    printHalfPyramid(n);
    return 0;
}
