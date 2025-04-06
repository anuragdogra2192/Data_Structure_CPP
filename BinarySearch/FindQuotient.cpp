/*
Given two integers dividend and divisor, 
divide two integers without using division "/", and mod "%" operators.

The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor. 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
*/

#include<iostream>

using namespace std;

int getQuotient(int dividend, int divisor)
{
    //Search Space --> (+ve dividend) -> (-ve dividend)
    int s = 0;
    int e = dividend;
    //>>1 one se right shift karne se 2 se divide ho jata hai
    int mid = s + ((e-s)>>1); // equivalent to s + (e-s)/2
    int ans = -1;

    while(s<=e)
    {
        if((divisor * mid) == dividend)
        {
            return mid;
        }
        if((divisor * mid) < dividend)
        {   
            //Store
            ans = mid;
            //Compute
            s = mid+1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + ((e-s)>>1);
    }
    return 0;
}

int main()
{
    int dividend = 16;
    int divisor = -4;

    //Positive value hio bhejna hai
    int ans = getQuotient(abs(dividend), abs(divisor));
    if((dividend < 0 && divisor > 0)|| (dividend > 0 && divisor < 0))
    {
        ans*=-1; 
    }
    cout<<"Quotient: "<<ans<<endl;
    return 0;
}