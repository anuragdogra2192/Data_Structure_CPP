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
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    printReverseHalfPyramid(n);
    return 0;
}
