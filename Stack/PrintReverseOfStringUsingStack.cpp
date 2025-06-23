#include<iostream>
#include<stack>
#include<string>

using namespace std;

void printReverse(string str)
{
    stack<char> s;
    //Insert each char in stack
    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);    
    }

    //Retrival of char from stack.
    //And print
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }

    cout<<endl;
}

int main()
{
    printReverse("HelloJee");
    printReverse("Anurag");
    printReverse("Olaf");
    return 0;
}
