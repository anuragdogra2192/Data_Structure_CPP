#include<iostream>

using namespace std;

void printReverseHalfPyramid(int nrows)
{
    //r - row 
    //c - col
    for(int r=0; r<nrows; r++)
    {
        for(int c = 0; c<nrows-r; c++)
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
    printReverseHalfPyramid(n);
    int i = 10;
    if(cout<<i)
        cout<<"Love babbar";

    return 0;
}
