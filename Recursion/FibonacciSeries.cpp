#include<iostream>
using namespace std;

/*
Fibionacci Series
0 1 1 2 3 5 8 13 21 34 55 . . . . . . 
0 + 1 
    1 + 1 = 2
        1 + 2 = 3 . . . . 
We can say 
nth term = (n-1)th term + (n-2)th term
Recursion relation:
=> fib(n) = fib(n-1) + fib(n-2)

0 - 0th term 
1 - 1th term
Base case:
n == 0 -> returns 0
n == 1 -> returns 1
*/

int fib(int n)
{
    //base case
    //if(n == 0)
    //    return 0;
    //if(n == 1)
    //    return 1;
    if(n == 0 || n == 1)
    {   
        return n;
    }
    //Recursive relation call
    //fib(n) = fib(n-1) + fib(n-2)
    int ans = fib(n-1) + fib(n-2);
    return ans;
    //Processing - optional
}

int main()
{   
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    cout<<"Fibonacci to nth is: "<< fib(n)<<endl;
    return 0;
}
//Time complexity - O(2^N)