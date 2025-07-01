#include<iostream>
#include<queue>
#include<stack>

using namespace std;

/*
 * Time Complexity - O(N)
 * Space Complexity - O(N)
 */
//Recursion
void reverseQueueRecursion(queue<int>& q)
{
    //base case
    if(q.empty())
    {
        return;
    }
    //!k Case meinm slove karunga  
    int element = q.front();
    q.pop();
    //baaki recursion sambhalega
    reverseQueueRecursion(q);
    //backTrack
    q.push(element);
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
    
    reverseQueueRecursion(q);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    return 0;
}
