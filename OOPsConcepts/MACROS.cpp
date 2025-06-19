/**
 * MACROS: In C++ the macros are preprocessor directives
 * that allow you to define constants, functions or code snippets 
 * that can be used through out the code.
 * Using #define directive and are evaluated by preprocessor
 * before the code is compiled.
 * PURPOSES:
 * Defining constants
 * Creatng shorthand for commonly used expressions.
 */

 #include<iostream>
 using namespace std;

 #define PI 3.14159 //Improve readibility and alway in CAPS
 #define MAXX(x, y)(x>y ? x:y)
 float circleArea(float r)
 {
    return PI*r*r;
 } 
 
 float circleParameter(float r)
 {
    return 2*PI*r;
 }

 void func1()
 {
    int a = 6; 
    int b = 100;
    cout<<"Maxx "<<MAXX(a,b)<<endl;
 }
 void func2()
 {
    int a = 61; 
    int b = 0;
    cout<<"Maxx "<<MAXX(a,b)<<endl;
 }
 
 int main()
 {  
    cout<<"Circle Area: "<<circleArea(65.4)<<endl;
    cout<<"Circle Parameter: "<<circleParameter(65.4)<<endl;
    func1();
    func2();
    return 0;
 }