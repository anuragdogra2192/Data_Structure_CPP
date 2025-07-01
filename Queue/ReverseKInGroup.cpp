#include<iostream>
#include<queue>
#include<stack>
using namespace std;
/**]
 * Space Complexity: max(O(k), O(n/k)) or we can say Linear
 * Time Complexity: O(n) linear
 */

void reverseInKGroup(queue<int>& q, int k, int count)
{
    if(count >= k)
    {
        //toh mein pakka reverse karunga.
        stack<int>st;
        //Fetch k elements from queue and insert in stack
        for(int i=0; i<k; i++)
        {
            int element = q.front();
            q.pop();
            st.push(element);
        }
        //Fetch k element from stack and put in queue
        for(int i=0; i<k; i++)
        {
            int element =  st.top();
            st.pop();
            q.push(element);
        }
        //1k case mein solve kar diya hai baaki recursion sambhalega
        reverseInKGroup(q, k, count-k);
    }
    else //count<k
    {   
        //iska matlab as it is, queue ke front se
        //uthakar End mein elements ko insert karunga.
        for(int i = 0; i<count; i++)
        {
            int element = q.front();
            q.pop();
            q.push(element);
        }
        return; 
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);
    int k =3;
    int count = q.size();
    reverseInKGroup(q, k, count);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}