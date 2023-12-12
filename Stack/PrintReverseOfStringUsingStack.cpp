#include<iostream>
#include<stack>
#include<string>

void printReverse(std::string s)
{
    std::stack<char> st;
    
    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        st.push(ch);
    }

    std::cout<<"Reverse of the given string "<<std::endl;
    while(!st.empty())
    {
        std::cout<<st.top();
        st.pop();
    }
    std::cout<<std::endl;
}

int main()
{
    printReverse("HelloJee");
    printReverse("Anurag");
    printReverse("Olaf");
    return 0;
}
