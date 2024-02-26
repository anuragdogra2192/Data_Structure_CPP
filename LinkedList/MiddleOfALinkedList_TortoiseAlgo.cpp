/* Floyd's Tortoise and Hare Algorithm
 * Slow and Fast approach -- A Tortoise algorithm
 This algorithm suggests that 
 * A slow pointer moves 1 step
 * A fast pointer moves 2 steps
 * Rule:
    *  Slow pointer moves 1 step only when fast pointer moves 2 steps
    *  if(fast pointers moves 2 steps)
    *   then slow pointer moves 1 step
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
    ListNode* middleNode(ListNode* head)
    {
        /* In this question it is given
            midpos = n/2 + 1
        */
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL)
        {
            //Fast moves step by step: really important to remember
            //there is a possibility that fast jumps to NULL, if we jump it
            fast = fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
                //Now we can say that fast is moved by 2 steps
                //so we can move slow pointer by 1 step
                slow = slow->next;
            }
        }
        //slow is in the mid position:
        return slow;
    }
};

/*
What IF:
 * mid = n/2 : was given in the question then the code changes as follows:
 
 ListNode* middleNode(ListNode* head)
    {
        //In this question it is given
          //  midpos = n/2
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!=NULL)
        {
            //Fast moves step by step: really important to remember
            //there is a possibility that fast jumps to NULL, if we jump it
            fast = fast->next;
            if(fast->next!=NULL)
            {
                fast = fast->next;
                //Now we can say that fast is moved by 2 steps
                //so we can move slow pointer by 1 step
                slow = slow->next;
            }
        }
        //slow is in the mid position:
        return slow;
    }
*/