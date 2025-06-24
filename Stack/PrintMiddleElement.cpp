#include<iostream>
#include<stack>

using namespace std;

//Time Complexity: O(n)
void printMiddle(stack<int>&s, int count)
{
    //base case
    if(count == 0)
    {
        cout<<s.top()<<endl;
        return;
    }

    //1k case mein karunga
    int topElement = s.top();
    s.pop();
    count--;
    
    //baaki recursion sambhalega
    printMiddle(s, count);

    //BackTrack
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
    s.push(60);
    s.push(70);

    int count = s.size()/2;
    printMiddle(s, count);
    return 0;
} 