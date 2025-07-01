/** FIFO :  First In First Out
 * Types:
 * Normal Queue - We can only access the front element.
 * Circle Queue
 * Double-ended Queue
 */

 #include<iostream>
 #include<queue>
 using namespace std;

 int main()
 {
    queue<int> q;
    //insertion
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    //front - only first element can be accessed.
    cout<<q.front()<<endl;
    //removal //front/firstr  element
    q.pop();
    cout<<q.front()<<endl;
    //size
    cout<<q.size()<<endl;
    //empty
    cout<<q.empty()<<endl;

   cout<<"Double-ended Queue"<<endl;
   //Double-ended Queue
   deque<int>dq;
   //Insertion
   dq.push_front(10);// line ke samne
   dq.push_front(30);//  30 line mien 10 ke aage lagaya
   dq.push_front(50);// peeche lagega
   dq.push_back(70);
   dq.push_back(100);

   cout<<dq.size()<<endl;
   cout<<dq.empty()<<endl;
   cout<<dq.front()<<endl;
   cout<<dq.back()<<endl;

   cout<<"After removal:"<<endl;
   //removal
   dq.pop_front();
   cout<<dq.front()<<endl;
   dq.pop_back();
   cout<<dq.back()<<endl;

   return 0;
 }