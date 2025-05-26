#include<iostream>

using namespace std;

//print from n to 1;
void printReverseCounting(int n)
{
    //base case
    if(n == 0)
        return;

    //Processing
    cout <<n <<" ";
    
    //Recursive relation Call
    printReverseCounting(n-1);

    /* Whenever the Recurrsion Call
    is in the end then it is a 
    Tail Recursion.
    Else Head Recustion 
    */

    //The output for n = 5
    //looks 5, 4, 3, 2, 1 in reverse 
}

//print from 1 to n;
void printCounting(int n)
{
    //base case
    if(n == 0)
        return;
    
    //Recursive relation Call
    printCounting(n-1);

    //Processing
    cout <<n <<" ";
    
    /* Whenever the Recurrsion Call
    is in the end them it is a 
    Tail Recursion.
    Else Head Recustion 
    */
    //This one is HEAD Recursion
    //The output for n = 5
    //looks 1, 2, 3, 4, 5. 
}

int main()
{   
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    //Tail Recursion
    printReverseCounting(n);
    cout<<endl;
    //Head Recursion
    printCounting(n);
}