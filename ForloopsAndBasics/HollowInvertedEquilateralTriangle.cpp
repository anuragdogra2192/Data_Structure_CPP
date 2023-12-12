#include<iostream>

using namespace std;

void printInvertedEquiTriangle(int nrows)
{
    for(int r=0; r<nrows; r++)
    {
        //Space
        for(int c=0; c<r; c++)
        {
            cout<<" ";   
        }
        //stars
        for(int c=0; c<nrows-r;c++)
        {   
            if(c==0 || c==nrows-r-1)
                cout<<"* ";
            else
                cout<<"  ";
        }
        cout<<endl;
   }
}

int main()
{
    int n;
    cin>>n;
    printInvertedEquiTriangle(n);
    return 0;
}