#include<iostream>
#include<string>

using namespace std;

void printPermutation(string& str, int i)
{
    //Base Case:
    if(i == str.length())
    {
        cout<<str<<endl;
        return;
    }
    
    for(int j = i; j<str.length(); j++)
    {   //1k Case mein karunga
        swap(str[i], str[j]);
        //Baaki recursion sambhalega
        printPermutation(str, i+1);
        //Back Tracking
        //restore the swap, 
        //so that the string stays original for the next.
        swap(str[i], str[j]);
    }
}

void permuteWithSTL(string& str) 
{
    //To get all permuations we need a sorted error
    //because nextPermutation_stl function returns
    //the next lexicographically order.
    
    sort(str.begin(), str.end());
    cout<<str<<endl; //Original
    while(next_permutation(str.begin(), str.end())) //returns bool
    {
        cout<<str<<endl;
    }
}

int main()
{
    string str = "abc";
    printPermutation(str, 0);
    string str1 = "xy";
    printPermutation(str1, 0);
    cout<<"The permute stl"<<endl;
    permuteWithSTL(str);
    return 0;
}


