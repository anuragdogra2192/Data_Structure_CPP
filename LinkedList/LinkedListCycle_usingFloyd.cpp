/*
 * 141. Linked List Cycle Using Floyd
 * TC:  O(N)
 * SC:  O(1) 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //TC - O(N)
        //SC - O(N)
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL)
        {
            fast =  fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            if(slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};