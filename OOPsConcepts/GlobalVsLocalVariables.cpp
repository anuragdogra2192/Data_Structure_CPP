#include<iostream>
using namespace std;

int x = 2; //Global Variable are accessible to all functions (same copy) 


void fun()
{
    int x = 60;
    cout<<x<<endl;
    cout<<::x<<endl;
}
int main()
{   
    ::x=4; //global x;
    int x = 20; //local x to main();
    cout<< x <<endl; //prints local x
    cout<<::x<<endl;// accessing th global with ::

    //Scoped
    {
        int x = 50;
        cout<< x << endl;
        cout<<::x<<endl; //global x
    }
    cout<<x<<endl; //20
    fun();
    return 0;
}