#include<iostream>
#include<stack>

using namespace std;

/**
 * Time complexity: O(n^2)
    O(n) * O(n) - insertAtBottom() takes O(n) too
    ==> O(n^2)
 */

void insertAtBottom(stack<int>& s, int val)
{
    //base case:
    if(s.empty())
    {
        s.push(val);
        return;
    }
    //1k case mein karunga
    int topElement = s.top();
    s.pop();
    //Baaki recursion samlbhalega
    insertAtBottom(s, val);
    //Backtrack 
    s.push(topElement);
}

void reverseAStack(stack<int>&s)
{
    //base case
    if(s.empty())
    {
        return;
    }

    //1K case mein karunga
    int topElement = s.top();
    s.pop();
    //Baaki recursion sambalega
    reverseAStack(s);
    //backTrack
    insertAtBottom(s, topElement);
}   

void printStack(stack<int>& s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    reverseAStack(s);
    printStack(s);
    return 0;
}