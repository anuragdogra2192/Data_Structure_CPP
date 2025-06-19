/**
 * Interview question: Can we make Constructor private?
 * YES we can make private constructor.
 * Use case: Singleton Design Pattern
 * And when we want only one/friend class
 * to handle the main class things. 
 * Below is the example.
 */

#include<iostream>
using namespace std;

class Box
{
private:
    int width;
    Box(int _w):width(_w){} //We don't want to give access to outside
    //only friend class will access.
public:
    void setWidth(int _w)
    {
        width = _w;
    }
    int getWidth()
    {
        return width;
    }
    friend class BoxFactory;
};

class BoxFactory
{
    int count;
    public:
    Box getABox(int _w)
    {
        ++count;
        return Box(_w);
    }
};

int main()
{
    BoxFactory bfact;
    Box b = bfact.getABox(2);
    cout<<b.getWidth()<<endl;
    b.setWidth(4);
    cout<<b.getWidth()<<endl;
    return 0;
}