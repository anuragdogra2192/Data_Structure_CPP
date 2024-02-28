/* 141. Linked List Cycle
 * Time complexity: O(N)
 * Space complexity: O(N)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<map>

class Solution {
public:
    bool hasCycle(ListNode *head) {
       std::map<ListNode*, bool> table; //By default bool is false
       ListNode* temp = head;

       while(temp!=NULL)
       {
           if(table[temp] == false)
           {
               table[temp] = true;
           }
           else
           {
               //cycle present
               return true;
           }
           temp = temp->next; //Don't forget it
       }
       //No loop present
       return false;  
    }
};