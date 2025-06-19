#include<iostream>
using namespace std;

class Base
{
public:
    Base() //Virtual ctor is not allowed.
    {
        cout<<"Base ctor"<<endl;   
    }
    virtual ~Base() //This is a good practice.
    {
        cout<<"Base dtor"<<endl;
    }
};

class Derived : public Base
{
    int *a;
public:
    Derived()
    {
        a = new int[100];// array of int of size 100.
        cout<<"Derived ctor"<<endl;
    }
    ~Derived()
    {
        //we have to delete the array.
        delete[] a;
        cout<<"Derived dtor"<<endl;
    }
};

int main()
{
    Base *b = new Derived();
    delete b;
    /**
     Base ctor
     Derived ctor
     Base dtor
     Quick observation: Derived dtor is not called. This can lead to memory leaks.
     To fix: we have to make dtor virtual.
     */
    
     /**After making virtual dtor
      Base ctor
      Derived ctor
      Derived dtor
      Base dtor
      
      Note: It is really important to handle 
            proper destruction of Derived classes.
      */
    return 0;

}