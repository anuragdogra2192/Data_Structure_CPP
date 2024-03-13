//Leet Code: 21. Merge Two Sorted Lists 
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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        
        if(!left) return right; // Don't forget this case
        //https://www.cs.fsu.edu/~vastola/cop3014/notes/pointers1.html
        if(right==0) return left; // Don't forget this case
        ListNode* ans =  new ListNode(-1);
        ListNode* mptr =  ans;

        while(left && right)
        {
            if(left->val <= right->val)
            {
                mptr->next =  left;
                mptr = left;
                left = left->next;
            }
            else
            {
                mptr->next = right;
                mptr = right;
                right = right->next; 
            }
        }

         //Don't forget these cases
        if(!left) mptr->next = right;
        if(!right) mptr->next = left;
        
        //return the next ptr of ans which holds the starting ptr of list
        return ans->next;
    }
};