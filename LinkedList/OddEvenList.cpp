/*
LC 328. Odd Even Linked List
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, 
and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even 
and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity. 
*/

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *h1 = head; //odd
        ListNode *h2 = head->next; //even
        ListNode* evenHead = h2;

        while(h2 && h2->next)
        {
            h1->next = h1->next->next;
            h2->next = h2->next->next;

            h1 = h1->next;
            h2 = h2->next;
        }

        //Regrouping both the Llists
        h1->next = evenHead;
        return head;
    }
};