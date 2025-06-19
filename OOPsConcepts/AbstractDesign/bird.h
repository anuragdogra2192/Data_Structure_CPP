#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

class Bird //Interface
{
    public:
        virtual void eat() = 0;//Pure virual function, which makes this class an Interface.
        virtual void fly() = 0;//Pure virual function, which makes this class an Interface.
    //Classes that inherits this class must have to implement these above functions.

};

class Sparrow : public Bird //Implementation
{
    private:
        void eat()
        {
            std::cout<<"Sparrow is eating"<<std::endl;
        }
        void fly()
        {
            std::cout<<"Sparrow is flying"<<std::endl;
        }
};

class Eagle : public Bird //Implementation
{
    private:
        void eat()
        {
            std::cout<<"Eagle is eating"<<std::endl;
        }
        void fly()
        {
            std::cout<<"Eagle is flying"<<std::endl;
        }
};

class Pigeon : public Bird //Implementation
{
    private:
        void eat()
        {
            std::cout<<"Pigeon is eating fast."<<std::endl;
        }
        void fly()
        {
            std::cout<<"Pigeon is flying fast."<<std::endl;
        }
};
#endif //BIRD_H
