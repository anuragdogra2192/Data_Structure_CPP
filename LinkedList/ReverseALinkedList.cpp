//Leet code: 206 Reverse A Linked List:
#include<iostream>
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
    ListNode* reverseList(ListNode* head) {
        //TC O(N)
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            //Move
            prev = curr;
            curr = nextNode; 
        }

        head = prev;
        return head;
    }
};