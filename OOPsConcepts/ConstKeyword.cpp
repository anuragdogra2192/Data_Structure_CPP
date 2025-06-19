/**
 * const keyword:
 * Used to declare that the object, function
 *  or variable is immutable.
 * Declare function as const, which means that
 *  it doesnot modify the state of the object it is called on.
 * Compiler maybe able to store const variables in "read-only" memory,
 *  which can result in faster access time.
 */

 #include<iostream>
 using namespace std;

 int main2()//To run make this main() and below one main2();
 {
    //1. const variables
    const int x = 5; // x is constant.
    //Initialization can be done, but we cannot reassign.(Promise)
    //x = 10;//expression must be modifiable lvalue.
    cout<< x <<endl;
    //Important Concept:
    //lvalue are variables having memory locations
    //lvalue example: int x, char y etc.
    //rvalue are variables having no memory locations
    //rvalue example: constant 5, reference variable int& a=b.

    //In old times with old compiler we can break the promise.
    //Interview question: How to modify the const.
    //int *p = &x;
    //*p = 10;
    //But this used to work with old compiler but this doesnot work with modern compilers.

    //2. const with pointers-----
    int *a = new int;//Dynamic allocated
    *a = 2;
    cout<< *a <<endl;
    int b = 5;
    //But here is a memory leak
    // so we need to delete the a first.
    delete a; //Now there is no memory leak. As we freed the memory of (new int) from line 34.
    a = &b;
    cout<< *a <<endl;

    //Lets get back to const
    cout<<"Topic CONST data NONCONST pointer"<<endl;

    const int *d = new int(2); //CONST data NONCONST pointer
    cout<< *d <<endl;
    /**
     * const int *d
     * Data/content of the pointer is constant.
     * But pointer can be reaasigned. Meaning pointer is not constant, its only pointing to a const data.
    */
    //*d = 20; We cannot change the data/content to the pointed location, like here by deferencing the pointer.
    int e = 20;
    d = &e;// pointer itself can be reassigned.
    //Now pointer d is pointing to e or keeping the address of e.
    cout<< *d <<endl;
    /**
     * Remember:
     * 1) const int *d
     * 2) int const *d
     * 1) and 2) are same, only different way of writing.
     * Takeaway if const keyword is before '*' means CONST DATA, NONCONST POINTER.
    */

    //Lets see.
    cout<<"Topic CONST pointer and NONCONST Data"<<endl;
    //CONST pointer and NONCONST Data
    int *const d1 = new int(10);
    *d1 = 30; //Only changing the data not pointer value.
    int e1 = 50;
    //d1 = &e1 //d1 pointer is CONST, so its value(pointing to address) cannot be changed.

    //Lets see
    cout<<"Topic CONST pointer and CONST Data"<<endl;
    //CONST pointer and CONST Data
    const int* const d2 = new int(10);
    cout<<*d2<<endl;
    //*d2 = 50; //Not possible as Data/Content is CONST
    int e2 = 100;
    //d2 = &e2; //Not possible as CONST pointer.
    return 0;
}

//CONST in Classes and functions
class ABC
{
private:
    int x;
    int *y;
    /**
     * mutable specifier
     * mutable - permits modification of the class member declared mutable
     * even if the containing object is declared const (i.e., the class member is mutable).
     * May appear in the declaration of a non-static class members
     * of non-reference non-const type:
     */
    mutable int z;
    const int z1;
    //mutable const int* p = nullptr; // OK, because NONCONST Pointer and CONST Data.
    //mutable int* const q; // ill-formed, because CONST Pointer
    //mutable int& r; // ill-formed
public:

    //No need of default constructor
    // ABC()
    // {
    //     x=0;
    //     y = new int(0);
    //     z = 0;
    // }

    //_z is with default arg
    //Without intializer list initializing const z1 with z is not possible.
    //as we cannot write z1 = z as z1 is not modifiable;
    ABC(int _x, int _y, int _z = 0)
     : x(_x), y(new int(_y)), z(_z), z1(z)
     {
        //z1 = x; not possbile here
        *y = x+1; 
     };

    ~ABC()
    {
        //Avoid memory leak.
        delete y;//w.r.t y = new int(0);
    }

    int getX() const
    //Const method means this cannot change any of the data member variable.
    //Cannot modify any member.
    {
        //const function
        //int x = 20; not possible
       return x;
    }
    void setX (int _value)
    {
        x = _value;
    }

    int getY() const
    {
        //const function
        //int f = 20; not possible
        //y = &f; not possible
        return *y;
    }
    void setY(int _value)
    {
        *y = _value;
    }

    //Rule:
    //NonConst function cannot be called by const obj.
    // int getZ()// non const
    // {
    //    return z;
    // }
    //Below one will work fine
    int getZ() const
    //Const method means this cannot change any of the data member variable.
    //Cannot modify any member.
    {
        //const function
        //int z = 20; not possible

        //Lets say I still want to change the value of z for debugging purpose or something.
        //Then we have to make z mutable in the decalaration.
        z = 20; //possible with mutable.
        return z;
    }
    void setZ (int _value)
    {
        z = _value;
    }

};

void printABC(const ABC& a)
{
    //Here 'obj a' is const ref, means its read only.
    //This 'obj a' can only call const member functions.
    cout<<a.getX()<<" "<<a.getY()<<" "<<a.getZ()<<endl;
}

int main()
{
    ABC a(1,2);
    printABC(a);
    //cout<<a.getX()<<endl;//0
    //cout<<a.getY()<<endl;//0
    return 0;
}