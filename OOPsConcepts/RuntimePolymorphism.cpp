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

Lets see now 
2) Runtime Polymorphism / Dynamic
Types:
a) Function overriding - makes function polymorphic
b) Early vs late binding
c) Virtual Keyword - way to achieve polymorphism 
    by deferring binding decision to runtime.
d) Override keyword - Helps to make the intention clear 
    and allows the compiler to enforce the overriding rules, 
    making your code safer and easier to understand.
e) Upcasting / Downcasting - 
        Behaviour: Without virtual function
                   With virtual function 
f) Final keyword - 
    1) the final specifier is used in two context,
       class and virtual functions.
    2) Prevents class Inheritance : If a class is declare as 'final', it means
       that no other class can inherit from it.
    3) Preventing virtual function overriding: 
       The 'final' specifier can also be used with virtual functions
       to prevent them from being overridden by the derived classes.

g) Override keyword
    Explanation
    In a member function declaration or definition, 
    override specifier ensures that the function is virtual 
    and is overriding a virtual function from a base class. 
    The program is ill-formed (a compile-time error is generated) if this is not true.
    override is an identifier with a special meaning 
    when used after member function declarators; 
    it is not a reserved keyword otherwise.
*/

#include<iostream>
using namespace std;

class Shape
//class Shape final //means Shape cannot be inherited by dervied/child classes
{
public:
    //With final it cannot be overridden by the derived classes
    // virtual void Draw() final
    // {
    //     cout<<"Generic shape is drawing"<<endl;
    // }
    virtual void Draw() 
    {
        cout<<"Generic shape is drawing"<<endl;
    }
};

class Circle : public Shape
{
public:
    void Draw() override
    {
        cout<<"Circle shape drawing"<<endl;
    }
};

class Rectangle : public Shape
{
public:
    void Draw() override
    {
        cout<<"Rectangle shape drawing"<<endl;
    }
};

class Triangle : public Shape
{
public:
    void Draw() override
    {
        cout<<"Triangle shape drawing"<<endl;
    }
};

void shapeDraw(Shape* s)
{
    s->Draw();// Draw is polymorphic
}

int main()
{
    Circle C;
    //C.Draw();
    Rectangle R;
    //R.Draw();
    /* Not bad till now.
    There is design choice where we want to handle
    everything with base class pointer or reference.
    */
    //Before Adding Virtual Keyword in base class.
    //Shape *s = &C;//Upcasting - Child clase to Parent clase.
    //Upcasting Parent class pointer holds the child class obj.
    //Shape *s = &C 
    //s->draw() --> Early binding is happening here by the compiler during compile time.
    //Shape *s = &C or Shape *s = new Circle();
    //shapeDraw(&C);//It calls the Draw() of base class. Upcasting. Due to early binding it call the Draw() of Shape not Circle.
    
    /*
    We want to make sure that 
    when: 
    Shape* s = &C; 
    s->Draw();
    Then Draw() of Circle should be called not of base class.
    And to acheive this there is Runtime Polymorphism.

    IMPORTANT NOTE
    We use virtual keyword which will delay 
    the binding decison to runtime and
    call the correct Draw() function.
    With Virtual keword in base case draw method.
    virtual Draw() -> in the base class.
    This tells the compiler not to take seriously and delay the binding.
    the Draw method in base class. As this will be resolved
    during the runtime.

    Shape* s = &C; 
    s->Draw();// This will call the Draw() of Circle class.
    As it is resolved during runtime.
    */
    //After adding virtual keyword in the base class
    //This avoids Early Binding.
    shapeDraw(&C);// On Stack 
    shapeDraw(&R);// On Stack 
    Triangle* T = new Triangle(); //On Heap
    shapeDraw(T);

    
    //Without Virtual Keyword
    cout<<"Without Virtual Keyword"<<endl;
    cout<<"Upcasting..."<<endl;

    //Normal S1 pointer to Shape obj.
    Shape* S1 = new Shape();
    S1->Draw();

    //UPCASTING:
    //Pointer of base class stores obj of derived class
    Circle* C1 = new Circle();
    Shape* S2 = C1; //== (Shape*)C1;
    S2->Draw();
    
    cout<<"Downcasting..."<<endl;
    //Normal C2 pointer to Circle obj.
    Circle* C2 = new Circle();
    C2->Draw(); 
    //DOWNCASTING:
    //Pointer of dervied class stores the obj of base class 
    Shape* S3 = new Shape();
    Circle* C3 = (Circle*)S3;
    C3->Draw();

    /*In short, without virtual, unexpected results.
    Left mein jo bhi likha hai or jiske obj mein actual obj store ho raha hai
    Wo hi print hoga jo left mein hai.
    */

    /*
    But when we make virtual it works as expected.
    Its prints the actual obj method.
    */


    return 0;
}
