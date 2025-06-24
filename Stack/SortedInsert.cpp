/*
Sorted Insert:
Insert a value in a sorted stack
Time Complexity: O(n)
*/

#include<iostream>
#include<stack>

using namespace std;

void sortedInsert(stack<int>& s, int val)
{
    //base case
    if(s.empty())
    {//insert at the bottom
        s.push(val);
        return;
    }

    if(!s.empty() && (s.top() < val))
    {
        s.push(val);
        return;
    }

    //1k case mein solve karunga
    int topElement = s.top();
    s.pop();
    sortedInsert(s, val);
    //backtrack
    s.push(topElement);
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

    int val = 23;
    sortedInsert(s, val);
    printStack(s);
    
    return 0;
}