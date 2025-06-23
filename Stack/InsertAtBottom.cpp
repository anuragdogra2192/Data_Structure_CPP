#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>&s, int value)
{
    //base Case
    if(s.empty())
    {
        //insert the value at the bottom
        s.push(value);
        return;
    }
    //1k case hum karenge, baaki recursion sambhgalega
    int topElement = s.top();
    s.pop();
    //baaki recursion ko de diya
    insertAtBottom(s, value);

    //backtrack
    s.push(topElement);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    int value = 13;

    insertAtBottom(s, value);

    //top() is the only way to access the stack
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
}