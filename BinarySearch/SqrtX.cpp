/*
69. Sqrt(x)
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

Used the Sample space pattern for ans with BS + Store and compute.
Time comlexity - O(LogN) 
*/

#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long int mid = s+(e-s)/2;
        int ans = -1;

        while(s<=e)
        {
            long long int sqre = mid*mid; 
            if(sqre == x)
            {
                return mid;
            }
            if(sqre < x)
            {
                //May or may not be ans
                ans = mid; //Storage
                s = mid + 1; //Compute: Right jao   
            }
            else
            {// left jao
             // sqre>x
             e = mid -1;
            }
            //yeah bhul jata huin
            mid = s+(e-s)/2;
        }
        return ans;
    }
};

//Trying to get the ans in 2 precision.
double myDoubleSqrt(int x) 
{
        int s = 0;
        int e = x;
        long long int mid = s+(e-s)/2;
        int ans = -1;

        while(s<=e)
        {
            long long int sqre = mid*mid; 
            if(sqre == x)
            {
                return mid;
            }
            if(sqre < x)
            {
                //May or may not be ans
                ans = mid; //Storage
                s = mid + 1; //Compute: Right jao   
            }
            else
            {// left jao
             // sqre>x
             e = mid -1;
            }
            //yeah bhul jata huin
            mid = s+(e-s)/2;
        }
        //return ans;

        double sqrt = (double) ans;
        int precision; // up to how many digits
        cout<<"Enter the precision for decimal: "<<endl;
        cin >> precision;
        double factor = 1;
        double Finalsqrt = sqrt;

        for(int i=0; i<precision; i++)
        {
            factor = factor/10.0;
            //cout<<"factor: "<<factor<<endl;

            for(int n=0; n<=9; n++)
            {
                double toAdd = n*factor;
                //cout<<"toAdd: "<<toAdd<<endl;
                double temp = sqrt + toAdd;
                if((temp*temp) < x)
                {
                    Finalsqrt = sqrt + toAdd;
                    //cout<<Finalsqrt<<endl;
                }
                else
                {break;}
            }
            sqrt = Finalsqrt;
        }
        return Finalsqrt;
}

int main()
{
    int x = 54;
    cout<<myDoubleSqrt(x)<<endl;
    return 0;
}