#include<iostream>

using namespace std;

void printEquiTriangle(int nrows)
{
    for(int r=0; r<nrows; r++)
    {
        //Space
        for(int c=0; c<(nrows-1-r); c++)
        {
            cout<<" ";   
        }
        //stars
        for(int c=0; c<r+1;c++)
        {
            if(c==0 || c==r)
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
    printEquiTriangle(n);
    return 0;
}