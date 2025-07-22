/* Geeks for geeks.
Union of Two Linked Lists

Given two linked lists (L1 & L2), your task is to complete the function makeUnion(), which returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

Examples:

Input: L1 = 9->6->4->2->3->8, L2 = 1->2->8->6->2
Output: 1 -> 2 -> 3 -> 4 -> 6 -> 8 -> 9

Explanation: All the distinct numbers from two lists, when sorted form the list in the output. 
Input: L1 = 1->5->1->2->2->5, L2 = 4->5->6->7->1
Output: 1 -> 2 -> 4 -> 5 -> 6 -> 7

Explaination: All the distinct numbers from two lists, when sorted forms the list in the output.
Expected Time Complexity: O((n+m)*Log(n+m))
Expected Space Complexity: O(n+m)

Constraints:
1<=size of both linked lists<=105
1<= data of nodes<=105
*/

#include<iostream>
#include<map>
using namespace std;

// structure of the node is as follows
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        map<int, Node*> UnionMap;
        //LL1 hashed
        Node* curr = head1;
        while(curr != NULL)
        {
            UnionMap[curr->data] = curr;
            curr = curr->next;
        }
        //LL2 hashed
        curr = head2;
        while(curr != NULL)
        {//same data hoga toh overwrite ho jayega 
            UnionMap[curr->data] = curr;
            curr = curr->next;
        }
        Node* UL = NULL;
        curr = NULL;
        //iterate UnionMap and make the UL
        for(auto it = UnionMap.begin(); it != UnionMap.end(); it++)
        {
            if(UL == NULL)
            {
                UL = it->second;
                curr = UL;
            }
            else
            {
                curr->next = it->second;
                curr = curr->next;
            }
        }
        //final node ke next ko NULL kar do.
        curr->next = NULL;
        return UL;
    }
};