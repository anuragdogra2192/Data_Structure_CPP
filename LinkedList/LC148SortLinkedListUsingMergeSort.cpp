/*
LC 148: Sort List
Given the head of a linked list, return the list after sorting it in ascending order.
Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
    
        while(fast->next!=NULL)
        {
            fast = fast->next;
            if(fast->next!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }   
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        if(left == NULL) return right;
        if(!right) return left;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(left!=NULL && right!=NULL)
        {
            if(left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        if(!left) temp->next = right;
        if(!right) temp->next = left;

        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        //base case 
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        // break LL into two halves
        ListNode* mid = findMid(head);

        //Left part
        ListNode* left = head;
        //right part
        ListNode* right = mid->next;
        mid->next = NULL;

        //recursive calls to both left and right
        left = sortList(left);
        right = sortList(right);
        
        //merge both left and right halves
        ListNode* result = merge(left, right);

        return result;

    }
};