/**
 * STATIC DATA MEMBER:
 *  These variables are going to SHARE MEMORY with all CLASS INSTANCES.
 * STATIC MEMBER FUNCTION:
 *  There is no INSTANCE of that CLASS being passed into that method.  
 *  In short these function have no this pointer.
 * NOTE: const keyword is not allowed in static.
 */

#include<iostream>
using namespace std;

class abc
{
public:
    int a, b;
    abc(int _a=0, int _b=0) : a(_a), b(_b){}

    //x, y These variables are going to SHARE MEMORY with all CLASS INSTANCES.
    static int x, y;
    static void print()
    {   
        //this pointer to current/calledBy obj
        //is always passed in the all non static member functions.
        //this -> is only related to the current instance of the class.
        //Therfore obj1 and obj2 print different values as
        //they are different instances of class.
        cout<<x<<" "<<y<<endl;
        //cout<<a<<" "<<b<<endl;
        //Non static members cannot be used.
    }
};
//Declaring static memebers.
int abc::x;
int abc::y;

int main()
{
    abc obj1;
    obj1.x = 2;
    obj1.y = 3;
    obj1.print();

    abc obj2;
    obj2.x = 40;
    obj2.y = 50;
    
    obj2.print();
    //call again
    obj1.print(); //Shared 
    abc obj3;     //by
    obj3.print(); //all

    //we can write in this way.
    abc::x=100;
    abc::y=200;
    abc::print();

    return 0;
}