#include<iostream>
using namespace std;
/*
Input number - 389
Digits - 3, 8, 9
389 % 10 = 9
| divide by 10
38 % 10 = 8
| divide by 10
3 % 10 = 3
| divide by 1-
0 --> rukh jao or say base case 
when the num  becomes 0 return.
*/
void getDigits(int num)
{
    //base case
    if(num == 0)
    {
        return;
    }
    //1k case mein solve karunga
    int digit =  num % 10;
    //Baaki recursion sambhalega
    getDigits(num/10);
    //Processing - Head recursion 
    cout<<digit<<" ";
    /* Whenever the Recurrsion Call
    is in the end then it is a 
    Tail Recurse
    Else Head Recustion  which is here.
    */
}

int main()
{
    int num;
    cin>>num;
    getDigits(num);
    cout<<endl;
    return 0;
}
