#include<iostream> 
using namespace std;
//Time Complexity: O(N/2) -> O(N)
//Space Complexity: O(N/2 + 1) -> O(N)


void reverseString(string& str, int start, int end)
{
    //Base case
    if(start >= end)
    {
        return;
    }   
    //1K Case mein solve karunga 
    swap(str[start], str[end]);
    
    //baaki recursion sambhal lega.
    reverseString(str, start+1, end-1);
}

int main()
{
    string s = "Anurag";
    reverseString(s, 0, s.length()-1);
    cout<<"Reverse: "<<s<<endl;
    return 0;
}