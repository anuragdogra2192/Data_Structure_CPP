#include<iostream>
#include<stack>
#include<limits.h>

using namespace std;

bool checkSorted(stack<int>&s, int element1)
{
    //base case
    if(s.empty())
    {//Means stack is sorted
        return true;
    }

    //1k case solve karna hai
    int element2 = s.top();
    s.pop();
    if(element2 < element1)
    {//mean check forward
        bool aageKaAns = checkSorted(s, element2);
        //backtrack
        s.push(element2);
        return aageKaAns;

    }
    else
    {//mean not sorted
        //backtrack
        s.push(element2);
        //s.push(-1);//replace the wrong element by -1;
        return false;
    }
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(10);
    s.push(60);
   
    int element = INT_MAX;
    cout<<checkSorted(s, element)<<endl;
    
    //top() is the only way to access the stack
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;
    return 0;
}