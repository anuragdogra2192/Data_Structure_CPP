//Leet code 206: Reverse a LinkedList

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseUsingRecur(ListNode* prev, ListNode* curr)
    {
        //base case - Stopping case
        if(curr == NULL)
        {
            return prev;
        }
        
        //1 case we need to solve
        ListNode* nextNode = curr->next;
        //Connect to other side
        curr->next = prev;
        
        //Update prev and curr
        prev = curr;
        curr = nextNode;

        //rest will be take care by recur call
        ListNode* recurAns = reverseUsingRecur(prev, curr);
        return recurAns;
    }

    ListNode* reverseList(ListNode* head) {
        //Time Complexity: O(N)
        // //Recursion approach
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        ListNode* recurAns = reverseUsingRecur(prev, curr);
        return recurAns;
    }
};