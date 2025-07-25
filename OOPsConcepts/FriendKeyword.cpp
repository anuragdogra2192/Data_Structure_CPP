/**
 * Friend keyword
 * A Friend class has the access to private data members.
 * Below: 
 *  class B is a Friend of class A
 *  void print(const A& a) is Friend function
 * It is not encouraged to use friend alot.
 */

#include<iostream>
using namespace std;

class A
{
 private:
    int x;
 public:
    A(int _val):x(_val){}
    
    int getX()const
    {
        return x; 
    }
    
    void setX(int _val)
    {
        x = _val;
    }
    friend class B;//Friend Class
    friend void print(const A& a);//Friend Function
};

class B
{
    public:
    void print(const A& a)
    {
        //cout<<a.getX()<<endl;
        //Now we want to print x directly.
        cout<<a.x<<endl;
    }
};

void print(const A& a)
{
    cout<<a.x<<endl;
} 

int main()
{
    A a(5);
    B b;
    b.print(a);
    print(a);
    return 0;
}
