/*
Abstraction:
It is a design and programming method that 
separates the interface from the implementation.

Abstract Class:
1) Class that contains at least one pure virtual function (interface) 
   and these classes cannot be instantiated.
2) It has come from idea of Abstraction
3) 
*/

#include<iostream>
#include "bird.h"

using namespace std;

void birdDoesSomething(Bird*& bird)
{
   bird->eat();
   bird->fly();
   bird->eat();
}
 
int main()
{
   Bird* bird1 = new Sparrow();
   birdDoesSomething(bird1);
   bird1 = new Eagle();
   birdDoesSomething(bird1);
   Bird* bird2 = new Pigeon();
   birdDoesSomething(bird2);
   //Bird b2; //not possible as it is an interface, so it can't be instantiated.  
   return 0;
}