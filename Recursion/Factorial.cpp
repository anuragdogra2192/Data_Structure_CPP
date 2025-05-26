#include<iostream>
using namespace std;

int getFactorial(int n)
{
    //Base case
    if(n == 0 || n == 1)
    {
        return 1;
    }
    //Recursive relation call
    //Big problem fact(n)
    //Chotti problem fact(n-1)
    int recursionAns = getFactorial(n-1);
    int finalAns = n * recursionAns;
    return finalAns;
    //Processing - optional
}

int main()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    cout<<"Factorial of n is: "<< getFactorial(n)<<endl;
    return 0;
}