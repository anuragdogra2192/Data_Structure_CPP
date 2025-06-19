/*
Polymorphism - A phenomenon that allows an object
to have many different forms.

Two types: 
1) Compile Time Polymorphism / Static
2) Runtime Polymorphism / Dynamic

1) Compile Time / Static Polymorphism
Types:
a) Function Overloading
When class contains multiple methods sharing same name
but different argument count or type.

b) Operator Overloading
When operators are overloaded, they execute user-defined functions whenever used,
allowing custom behaviour.
*/

#include<iostream>

using namespace std;

//Compile Time / Static Polymorphism Examples
class Add
{//Function Overloading
//Whats right or wrong decides during compile time
//therfore its compile time polymorphism.
    public:
    //x, y, two int addtion
    int sum(int x, int y)
    {
        cout<<"Sum of two int"<<endl;
        return x+y;
    }

    int sum(int x, int y, int z)
    {   
        cout<<"Sum of 3 int"<<endl;
        return (x+y+z);
    }

    double sum(double x, double y)
    {
        cout<<"Sum of 2 doubles"<<endl;
        return(x + y);
    }  
};

//Operator Overloading Example
class Complex
{
private:
    int real;
    int imag;
public:
    Complex()
    {
        this->real=-1;
        this->imag=-1;
    }

    Complex(int r, int i) : real(r), imag(i) {}

    //Operator Overloading
    /* Syntax
    return_type operator <op> (agrs)
    {
        Function logic ....
        return return_type;
    }
    */
    Complex operator + (const Complex& C)
    //this(calling one) mein add kar raha huin C object
    {   
        Complex C3((this->real + C.real),(this->imag + C.imag));
        return C3;  
    }
    
    Complex operator - (const Complex& C)
    //this(calling one) mein add kar raha huin C object
    {   
        Complex C3((this->real - C.real),(this->imag - C.imag));
        return C3;  
    }

    bool operator == (const Complex& C)
    //this(calling one) mein add kar raha huin C object
    {   
        if((this->real == C.real) && (this->imag == C.imag))
        {
            return true;
        }
        return false;
    }

    void display() const //Preferred if function does not modify members
    {/**
     * const after the function tells the compiler that this member function will not modify the object.
     * This allows you to call display() on const objects and improves code safety.
     */
        printf("[%d + i%d]\n", this->real, this->imag);
    }

};

int main()
{ //Compile Time / Static Polymorphism Init
    //Function Overloading Init
    int x = 10, y = 20;
    int z = 30;
    Add A;

    cout<<A.sum(x,y)<<endl; 
    cout<<A.sum(x,y,z)<<endl;
    cout<<A.sum(1.0, 4.5)<<endl;
    //Function Overloading Finalize.
    
    //Operator Overloading Init
    Complex C1(2, 5);
    C1.display();
    Complex C2(2, 15);
    C2.display();

    Complex C3 = C1 + C2;
    C3.display();

    Complex C4 = C2 - C1;
    C4.display();
    cout<<(C1==C2)<<endl;//false
    Complex C5(2, 5);
    cout<<(C1==C5)<<endl;//true

    //Operator Overloading Finalize
 //Compile Time / Static Polymorphism Finalize

    return 0;
}

