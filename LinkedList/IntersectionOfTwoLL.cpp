/**
 * LC 160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while(a!=NULL && b!=NULL)
        {
            if(a == b)
            {
                return a;
            }
            a = a->next;
            b = b->next;
        }    

        //when B is larger than or equal A
        if(a==0)
        {
            //Now we need to find the diff 
            int blen = 0;
            while(b)
            {
                blen++;
                b = b->next;
            }

            //Now we move headB to that blen dist
            while(blen!=0)
            {
                blen--;
                headB = headB->next;
            }
        }

        else
        {
            //when A is larger than or equal B
            //Now we need to find the diff 
            int alen = 0;
            while(a)
            {
                alen++;
                a = a->next;
            }

            //Now we move headB to that blen dist
            while(alen!=0)
            {
                alen--;
                headA = headA->next;
            }
        }

        while(headA!=headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;

    }
};