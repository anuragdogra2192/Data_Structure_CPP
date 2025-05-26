#include<iostream>
using namespace std;
/*
The function is for calculating
the Power of 2
for n = 5 -> 2^n 
2^5 = 2 * 2 * 2 * 2 * 2
pow(5) = 2 * pow(4)
pow(4) = 2 * pow(3);
pow(3) = 2 * pow(2);
pow(2) = 2 * pow(1);
pow(1) = 2 * pow(0); return; base case
2^0 = 1 return.
*/
int pow(int n)
{
    //base case
    if(n == 0)
    {
        return 1;
    }
    //recursive relation
    //pow(n) = 2 * pow(n-1) 
    //Big          small
    int recKaAns = pow(n-1);
    int finalAns = 2 * recKaAns;
    return finalAns;
    //Processing - optional
}

int main()
{
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    cout<<pow(n)<<endl;
    return 0;
}