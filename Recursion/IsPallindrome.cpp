#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(string& str, int start, int end)
{
    //base case
    if(start > end)
    {
        return true;
    }

    //1K case mein karunga
    if(str[start] != str[end])
    {
        return false;
    }

    //Baaki recursion sambhal lega
    return isPalindrome(str, start+1, end-1);
}
int main()
{   
    string str1 = "NITIN";
    string str2 = "MOM";
    string str3 = "ANURAG";
    cout<<isPalindrome(str1, 0, str1.length()-1)<<endl;
    cout<<isPalindrome(str2, 0, str2.length()-1)<<endl;
    cout<<isPalindrome(str3, 0, str3.length()-1)<<endl;
    return 0;
}