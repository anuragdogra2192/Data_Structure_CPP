//Important Concept for Interview.
#include<iostream>
using namespace std;

class abc
{
 public:
    int x;
    int* y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}
    
    //Copy Constructor
    ///Same implementation like default copy constructor.
    //This is called Shallow Copy.
    abc(const abc& obj)
    {
        x = obj.x;
        y = obj.y;
    }

    //Our Custom Implementation of Copy Constructor to have deep copy.
    //Deep Copy
    // abc(const abc& obj)
    // {
    //     x = obj.x;
    //     y = new int (*(obj.y));
    // }

    void print() const
    {
        printf("X: %d\nPtr Y: %d\nContent of Y (*y) %d\n\n", x, y, *y);
    }
    ~abc()
    {
        delete y;
    }
};

int main()
{   
    //SHALLOW COPY: Uncomment the Copy Constructor at line 15.
    //cout<<"Topic: Shallow Copy"<<endl;
    //DEEP COPY: Uncomment the Copy Constructor at line 23
    cout<<"Output for obj1 "<<endl;
    abc obj1(1,2);
    obj1.print();
    cout<<"Output for obj2 "<<endl;
    abc obj2 = obj1;// Default Copy Constructor is called. because we havenot defined our own custom one.
    obj2.print();
    /**
     * SHALLOW COPY and its explaination
     *  In the output, we can see that obj1 is copied to obj2.
     *  But we should note that the Ptr Y value is also same
     *  means both (obj1 pointer y) and (obj2 pointer y) are pointing to the same memory location.
     *  This conclude that we didn't the copy content of y  (*y "deference y") to obj2 properly.
        
        Output for obj1
        X: 1
        Ptr Y: 778067664
        Content of Y (*y) 2
        
        Output for obj2
        X: 1
        Ptr Y: 778067664
        Content of Y (*y) 2 

     * If obj1 free the memory *y then obj2 will not be able to access
     * content *y. 
     *  This is called Shallow Copy.
     */
    
    //Lets play a bit.
    *(obj2.y) = 20;

    cout<<"Output for obj2 "<<endl;
    obj2.print();
    cout<<"Output for obj1 "<<endl;
    obj1.print();//obj1 will also get 20 in case of Shallow Copy
    /**
     * DEEP COPY and its output
     *  Output for obj1 
        X: 1
        Ptr Y: 1173373056
        Content of Y (*y) 2

        Output for obj2 
        X: 1
        Ptr Y: 1173373072
        Content of Y (*y) 2

        Output for obj2 
        X: 1
        Ptr Y: 1173373072
        Content of Y (*y) 20

        Output for obj1 
        X: 1
        Ptr Y: 1173373056
        Content of Y (*y) 2
        Now, the value of Ptr Y is different in obj2 from obj1. 
     */ 

    /**
     * double memory free error 
     * We have added a destructor to delete y from heap.
     * ~abc()
     * {
     *  delete y;
     * }
     * Now let see what happens in Shallow Copy Case
     * and why Deep Copy is so important here.
     */
    //Uncomment the Default Copy Constructor Code and
    //Comment the custom Deep Copy Constructor

    
    abc* a= new abc(1,2);
    abc b = *a;
    cout<<"Output for a: "<<endl;
    a->print();
    delete a;
    cout<<"Output for b: "<<endl;
    b.print();
    cout<<"Now we see tha doulbe free behavior when b's destructor is called"<<endl;
    /**
     *  Output:
     *  Output for a: 
        X: 1
        Ptr Y: 1257259504
        Content of Y (*y) 2
        
        Output for b: 
        X: 1
        Ptr Y: 1257259504
        Content of Y (*y) 0
        
        Now we see tha doulbe free behavior when b's destructor is called.
        
        a.out(77885,0x1f6b87840) malloc: Double free of object 0x14af041f0
     */
    return 0;
}