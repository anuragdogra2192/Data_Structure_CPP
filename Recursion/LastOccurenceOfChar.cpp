/*
string s = "abcddefdg";
find last occurence of char = 'd'
"a b c d d e f d g"
 0 1 2 3 4 5 6 7 8

 Ans of 'd' = 7

Method 1 - Iterate from left to right and updateAns index;
//We traverse all for sure all the time

Method 2 - Better to iterate from right to left (reversely)
           and return index for first occurence of char
Method 3 - Recursion

Time complexity: O(N) 
Space Complexity in Recursion only: O(N)
*/

#include<iostream>
#include<string>

using namespace std;

int lastOccCharIterative(string str, char ch)
{   //Right to Left
    //Reverse traverse
    for(int i = str.length(); i >= 0; i--)
    {
        if(str[i] == ch)
            return i;
    }
    return -1;
}

void LeftToRightRecursion(string& str, char& ch, int i, int& ans)
{
    //Base case
    if(i == str.length())
    {
        return;
    }
    //1K case mein karuna
    if(str[i] == ch)
    {   
        ans =  i;
    }
    //baaki recursion Sambhalega
    LeftToRightRecursion(str, ch, i+1, ans);
}

void RightToLeftRecursion(string& str, char& ch, int i, int& ans)
{
    //Base case
    if(i < 0)
    {
        return;
    }

    if(str[i] == ch)
    {
        ans = i;
        return;
    }
    
    //baaki recursion Sambhalega
    RightToLeftRecursion(str, ch, i-1, ans);
}

int main()
{   
    string s = "abcddefdg";
    char ch = 'd';
    int occ = lastOccCharIterative(s, ch);
    if(occ != -1)
        cout<<"Last occurence: "<<occ<<endl;
    
    int ans1;
    LeftToRightRecursion(s, ch, 0, ans1);
    cout<<"Last occurence: "<<ans1<<endl;
    
    int ans2;
    RightToLeftRecursion(s, ch, s.length()-1, ans2);
    cout<<"Last occurence: "<<ans2<<endl;
    return 0;
}