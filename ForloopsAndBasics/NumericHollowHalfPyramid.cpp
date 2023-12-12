#include<iostream>
//#include<>

using namespace std;

void printPattern(int n)
{
    //My method
    // for(int r=0; r<n; r++)
    // {
    //     for(int c=0;  c<r+1; c++)
    //     {
    //         if(r==0 || r==n-1)
    //         {
    //             cout<<c+1<<" ";
    //         }
    //         else
    //         {
    //             if(c==0 || c==r)
    //             {
    //                 cout<<c+1<<" ";
    //             }
    //             else
    //             {
    //                cout<<"  ";
    //             }
    //         }
    //     }
    //     cout<<endl; 
    //}
    // LOVE BABBAR's
    for(int r=0; r<n; r++)
    {
        for(int c=0; c<=r; c++)
        {
             if(c==0 || c==r || r==n-1)
             {
                cout<<c+1;
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