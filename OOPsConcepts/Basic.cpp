/*
Topics:
Default Constructor
Paramerterized Constructor
Copy Constructor
Destructor
Static allocation of object
Dynamic allocation of object
Management of pointer data members/attributes in constructors.
*/
#include<iostream>

using namespace std;

class Student
{
 public:
 //Behaviour / Methods / member function
    Student()
    {
        cout<<"Student default constructor called"<<endl;
    }
    //Paramerterized Constructor
    Student(int id, int age, string name, float gpa) : id(id), age(age), name(name)
    {
        cout<<"Called the parameterized constror"<<endl;
        this->gpa = new float(gpa);
        //this->id = id;
        //this->age = age;
        //this->name = name;
    }

    //Copy Constructor
    Student(const Student& srcobj) //Syntax const and by ref & is important.
    {
        cout<<"Called the Copy constructor"<<endl;
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->name = srcobj.name;
        float gpaValue = *(srcobj.gpa);
        this->gpa = new float(gpaValue);
    }

    void study()
    {
        cout<<this->name<<" student is studying"<<endl;
    }

    void bunk()
    {
        cout<<this->name<<" student is bunking"<<endl;
    }

    ~Student()
    {   
        delete this->gpa;
        cout<<"Student default destructor called"<<endl;
    }

 //private:
 //Attributes
    string name;
    int age;
    int id;
    float* gpa;
};

int main()
{
    Student A(1, 15, "Anurag", 7.9);// Defined on Stack.
    Student B;
    B.name = "Bubu";
    B.id = 2;
    B.age = 30;
    B.gpa = new float(3.9);
    A.bunk();
    B.bunk();
    //Copy constructor
    Student C = A; // ==> Student C(A);
    C.bunk();
    cout<<endl;
    //Dynamic Allocation or Student Pointer 
    Student* D = new Student(5, 29, "Bhola", 8.0);
    D->study();
    cout<<*(D->gpa)<<endl;
    delete D;
    cout<<endl;
    return 0;
}