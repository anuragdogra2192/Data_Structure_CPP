/* 
Geeks for Geeks

Interleave the First Half of the Queue with Second Half

Difficulty: MediumAccuracy: 62.41%Submissions: 14K+Points: 4Average Time: 20m

Given a Queue of even size . Your task is to rearrange the queue by interleaving its first half with the second half.
Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.
In other words, Interleaving means place the first element from the first half and then first element from the 2nd half and again 2nd element from the first half and then second element from the 2nd half and so on....

Examples:

Input: q = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
Explanation: we place the first element of the first half 2 and after that place the first element of second half 3 and after that repeat
the same process one more time so the resulting queue will be [2, 3, 4, 1]
Input: q = [3, 5]
Output: [3, 5]
Explanation: We place the first element of the first half 3 and first element of the second half 5 so the resulting queue is [3, 5]

Constraints:
1 <=queue.size()<= 5*105
1 <=queue[i]<= 5*105

Time Complexity
Splitting the queue into two halves: O(n/2)
Interleaving both halves: O(n)
Each queue operation (push/pop/front) is O(1), and every element is processed a constant number of times.
Total Time Complexity:
O(n)

Space Complexity
An extra queue (q2) is used to store half the elements: O(n/2)
The original queue uses O(n) space (but this is not extra).
No other significant space is used.
Total Space Complexity:
O(n)

Summary:
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include<iostream>
#include<queue>
using namespace std;

class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
        //vector<int>ans;
        queue<int> q2;
        
        int n = q.size();
        int half = n/2;
        
        while(half--)
        {
            int element = q.front();
            q.pop();
            q2.push(element);
        }
        //first half -> q2
        //second half -> remaining q
        //Given a Queue of even size, both half has a same size.
        int size = q.size();//remaining q size == q2 size
        while(size--)
        {
            int element = q2.front();
            q2.pop();
            q.push(element);
            element = q.front();
            q.pop();
            q.push(element);
        }
        return q;
    }
};