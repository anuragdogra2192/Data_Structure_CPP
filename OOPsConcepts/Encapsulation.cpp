/*
Perfection Encapsulation
1) If all data members / variables are private.
2) Only memeber functions / behaviors can be public
   so that it allows external communications.
   Controlled access to outside data.

   Only necessary information to be shown,
   using access modifiers.
*/

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
    void setGPA(float gpa)
    {
        //here we can add layer of authentication
        *(this->gpa) = gpa;
    }
    
    float getGPA() const
    {
        return *(this->gpa);
    }
    int getAge() const
    {
        return this->age;
    }
 //Behaviour / Methods / member function
    Student()
    {
        cout<<"Student default constructor called"<<endl;
    }
    //Paramerterized Constructor
    Student(int id, int age, string name, float gpa, string gf) : id(id), age(age), name(name)
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
        this->girlFriend = srcobj.girlFriend;
    }

    void study()
    {
        cout<<this->name<<" student is studying"<<endl;
    }

    void bunk()
    {
        cout<<this->name<<" student is bunking"<<endl;
    }

    void sleep()
    {
        cout<<this->name<<" student is sleeping"<<endl;
    }

    ~Student()
    {   
        delete this->gpa;
        cout<<"Student default destructor called"<<endl;
    }

 private:
 //Attributes
    string name;
    int age;
    int id;
    float* gpa;
    string girlFriend;
 private:
    void gfChatting()
    {
        cout<<this->name<<" student is chatting"<<endl;
    }
};

int main()
{
    Student A(1, 15, "Anurag", 7.9, "Monika");// Defined on Stack.
    Student B;
    A.bunk();
    B.bunk();
    
    //Copy constructor
    Student C = A; // ==> Student C(A);
    C.sleep();
    cout<<endl; 

    //Dynamic Allocation or Student Pointer 
    Student* D = new Student(5, 29, "Bhola", 8.0, "Bholi");
    D->study();
    D->setGPA(10.0);
    cout<<"Bhola new GPA "<<D->getGPA()<<endl;
    cout<<"Bhola's age "<<D->getAge()<<endl;
    delete D;
    cout<<endl;
    return 0;
}