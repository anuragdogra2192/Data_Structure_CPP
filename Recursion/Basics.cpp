#include<iostream>
/*
Recursion components:
1) Base case/condition - Rukna kab hai, Mandatory
2) Recursive call , Mandatory (if we manage this then everything is easy)
3) Processing,  Optional.
*/

/*
lets understand this with factorial problem
n! = n * (n-1) * (n-2) * (n-3) * (n-4) * ...* 2 * 1.
n!= n * (n-1)!
fact(n) = n * fact(n-1) --> Relation
  Big           Small

To stop we need to find the base case
Base case means jiska ans hume pata hai
Here we have 0! == 1
fact(0) is 1; once n == 0 then we stop.

If recursion will not have base case then there
will be Stack overflow.

*/
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
/*Call stack during run for n = 5
|
|
|getFactorial(1) -- return 1
|getFactorial(2)    
|getFactorial(3) 
|getFactorial(4)
|getFactorial(5)
|main()

After return 1 
we come back.
*/