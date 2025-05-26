/*
Get the sum of input n.
n = 5;
sum = 1+2+3+4+5
Recursive relation
getSum(n) =  getSum(n-1)      + n
             Recursion karega   Ye mein karunga
Sum(5) = Sum(4) + 5
Sum(4) = Sum(3) + 4
Sum(3) = Sum(2) + 3
Sum(2) = Sum(1) + 2
Sum(1) = Sum(0) + 1

Base case:
if n == 0 
Sum(0) = 0
return 0;
or
n == 1
Sum(1) = 1
retuen 1;
*/
#include<iostream>
using namespace std;

int getSum(int n)
{   
    //base case:
    if(n == 1)
    {
        return 1;
    }
    //Recursive relation call:
    int ans = getSum(n-1) + n;
    //Processing - optional
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the n: "<<endl;
    cin>>n;
    cout<<getSum(n)<<endl;
    return 0;
}