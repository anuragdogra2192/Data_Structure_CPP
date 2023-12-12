#include<iostream>

using namespace std;

void printHollowSquare(int nrows)
{
    //r - row 
    //c - col
    for(int r=0; r<nrows; r++)
    {
        for(int c = 0; c<nrows; c++)
        {
            if(r == 0 || r == nrows-1)
                cout<<"* ";
            else
            {
                if(c == 0 || c == nrows-1)
                    cout<<"* ";
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    printHollowSquare(n);
    return 0;
}
