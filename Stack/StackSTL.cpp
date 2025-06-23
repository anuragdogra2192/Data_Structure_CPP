#include<iostream>
#include<stack>

using namespace std;

int main()
{
    //Creation:
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);//--> top

    //Size
    cout<<s.size()<<endl;
    //Check Empty or not
    cout << s.empty()<<endl;
    //Peek, to access the top element
    cout<<s.top()<<endl;

    //Removal
    //In Stack, element removes from top.
    s.pop();
    cout<<s.top()<<endl;
}