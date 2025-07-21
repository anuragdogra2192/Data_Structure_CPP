/* Leet Code 23. 
23. Merge k Sorted Lists
Highly Important, interview

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

Time Complexity
Each node from all k lists is pushed and popped from the min-heap once.
There are N total nodes (sum of all list lengths).
Each heap operation (push/pop) takes O(log k) time (since the heap size is at most k).
Total time complexity:
O(N log k)
Space Complexity
The min-heap stores up to k nodes at a time: O(k)
The output linked list uses O(N) space (but this is required for the result, not extra).
Auxiliary space (excluding output):
O(k)
Summary:

Time: O(N log k)
Space: O(k) auxiliary (O(N) total including output list)
*/

#include<iostream>
#include<queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare
{
    public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> min_pq;
        int totalRows = lists.size();
        
        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(int row=0; row<totalRows; row++)
        {
            ListNode* temp = lists[row];
            if(temp != NULL)
            {
                //if its valid Node
                min_pq.push(temp);
            }
        }

        while(!min_pq.empty())
        {
            //front nikalo
            ListNode* front = min_pq.top(); min_pq.pop();
            //ans mein store karo
            if(head == NULL && tail == NULL)
            {// means first node in LL
                head = front;
                tail = front;
            }
            else
            {   //meann not a first node
                tail->next = front;
                tail = front;
            }
            if(tail->next != nullptr)
            {
                min_pq.push(tail->next);
            }
        } 
        return head;   
    }
};