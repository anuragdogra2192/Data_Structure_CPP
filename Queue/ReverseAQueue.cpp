#include<iostream>
#include<queue>
#include<stack>

using namespace std;
/*
 * Time Complexity - O(N)
 * Space Complexity - O(N)
 */

void reverseQueue(queue<int>& q)
{
    std::stack<int> st;
    while(!q.empty())
    {
        int element = q.front();
        q.pop();
        st.push(element);
    }
    //Here the tack has all the values
    while(!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(100);
    q.push(50);
    q.push(60);
    q.push(80);
    
    reverseQueue(q);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
