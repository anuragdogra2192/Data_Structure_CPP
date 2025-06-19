#include<iostream>
#include<string>

using namespace std;

class Vehicle
{
protected:
    string name;
    string model;
    int noOfTyres;
public:
    Vehicle(string _name, string _model, int noOfTyres)
    {
        cout<<"I am inside vehicle"<<endl;
        this->name = _name;
        this->model = _model;
        this->noOfTyres = noOfTyres;
    }

public:
    string getName() const
    {
        return this->name;
    }
    void startEngine()
    {
        cout<<"Engine is starting "<<name<<" "<<model<<endl;
    }
    void stopEngine()
    {
        cout<<"Engine is stopping "<<name<<" "<<model<<endl;   
    }
    ~Vehicle()
    {
        cout<<"The vehicle destructor called."<<endl;
    }
};

class Car : public Vehicle
{
protected:
    int noOfDoors;
    string transmissionType;
public:    
    Car(string _name, string _model, int _noOfTyres, int _noOfDoors, string _transmissionType):
        Vehicle(_name, _model, _noOfTyres), noOfDoors(_noOfDoors), transmissionType(_transmissionType) 
        {
            cout<<"I am inside Car"<<endl;
        }

    void startAC()
    {
        cout<<"The Ac has started "<<name<<endl;
    }

    ~Car()
    {
        cout<<"The Car destructor is called."<<endl;
    }

};

class Motorbike : public Vehicle
{
    protected:
        string handleBarStyle;
        string suspensionType;
    public:
        Motorbike(string _name, string _model, int _noOfTyres, string _handleBarStyle, string _suspensionType):
        Vehicle(_name, _model, _noOfTyres), handleBarStyle(_handleBarStyle), suspensionType(_suspensionType)
        {
            cout<<"I am inside Motorbike"<<endl;
        }

        void wheelie()
        {
            cout<<"Bike is doing Wheelie"<< name <<endl;
        }

        ~Motorbike()
        {
            cout<<"The Motorbike destructor is called."<<endl;
        }
};

int main()
{   
    Car A("BMW 440i", "Gran Coupe", 4, 4,"Manual");
    A.startEngine();
    A.startAC();
    A.stopEngine();
    //remember:  The base class constructor invoked then derived class.
    //Protected: Its like private but make sures that data memeber is inheritable.
    //Private data members are not inheritable.

    Motorbike M("Honda", "CBR", 2, "U", "Hard");
    
    M.startEngine();
    M.wheelie();
    M.stopEngine();

    return 0;
}
/* Note the Constructor Calling Sequence.
I am inside vehicle
I am inside Car
Engine is starting BMW 440i Gran Coupe
The Ac has started BMW 440i
Engine is stopping BMW 440i Gran Coupe
I am inside vehicle
I am inside Motorbike
Engine is starting Honda CBR
Bike is doing WheelieHonda
Engine is stopping Honda CBR
The Motorbike destructor is called.
The vehicle destructor called.
The Car destructor is called.
The vehicle destructor called.
*/


/*
                    MODE OF INHERITANCE
            | Derived Class | Derived Class | Derived Class |
Base class  | Private Mode  | Protected Mode| Public Mode   |
 Private    | Not Inherited | Not Inherited | Not Inherited |
Protected   |   Private     |   Protected   |   Protected   |
  Public    |   Private     |   Protected   |   Public      |
*/