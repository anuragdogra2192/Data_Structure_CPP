/*
2816. Double a Number Represented as a Linked List
You are given the head of a non-empty linked list representing a non-negative integer 
without leading zeroes.

Return the head of the linked list after doubling it.
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
    void solveIt(ListNode* head, int& carry)
    {
        if(!head) return;
        solveIt(head->next, carry);

        //1 case solve
        int prod = head->val * 2 + carry;
        head->val = prod % 10;
        carry = prod / 10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solveIt(head, carry);
        if(carry)//not equal to 0
        {
            ListNode* temp = new ListNode(carry);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};