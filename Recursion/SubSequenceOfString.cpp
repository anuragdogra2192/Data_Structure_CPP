/*
Subsequence of a string. 

Subsequence:
Follow the same sequence

Example:
Subsequences of "abc"
"abc", "ab", "ac", "a", "bc", "b", "c", ""
*/

#include<iostream>
#include<string>
#include <vector>

using namespace std;
//Highly Important Hai
void printSubSequences(string str, int i, string output)
{
    //base case
    if(i == str.length())
    {
        cout<<"\""<<output<<"\""<<" ";
        return;
    }

    //1k case khud solve karunga
    char  ch = str[i];
    //Include case - include ch in output
    //Baaki recursion sambhalega
    printSubSequences(str, i+1, output+ch);
    // ""+"a" = "a"

    //Exclude case - exclude ch in output
    //Baaki recursion sambhalega
    printSubSequences(str, i+1, output);//Excluded
}

/*
How about storing the subsequences in vector
*/
void storeSubSequences(string str, int i, 
    string output, vector<string>&ans)
{
    //Base case
    if(i == str.length())
    {
        ans.push_back(output);
        return;
    }
    //1K Case main solve karunga
    char ch = str[i];
    //Include Case
    storeSubSequences(str, i+1, output+ch, ans);
    //Baaki recursion sambhal lega
    //Exclude Case
    storeSubSequences(str, i+1, output, ans);
    //Baaki recursion sambhal lega
}

int main()
{
    string str = "abc";
    string output = "";
    int index = 0;
    printSubSequences(str, index,output);
    cout<<endl;
    vector<string>ans;
    storeSubSequences(str, index, output, ans);
    for(auto a : ans)
    {
        cout<<"\""<<a<<"\""<<" "; 
    }
    cout<<endl;
    return 0;
}
/*
Time complexity: O(2^n)
*/