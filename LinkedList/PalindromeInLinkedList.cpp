/*
 * LC 234. Palindrome Linked List
 
 Time Complexity O(N)
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
    {//TC O(N)
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL)
        {
            fast = fast->next;
            if(fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode* reverseUsingRecur(ListNode* curr, ListNode* prev)
    {
        //BaseCase
        if(curr == NULL)
        {
            return prev;
        }

        //One case we solve
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //Remaining is done by recursion
        return reverseUsingRecur(curr, prev);
    }

    ListNode* reverseList(ListNode* head)
    { //TC O(N)
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reverseUsingRecur(curr, prev);
    }

    bool compareList(ListNode*& head1, ListNode*& head2)
    {//TC O(N)
        while(head2!=NULL && head1!=NULL)
        {
            if(head2->val != head1->val)
            {
                return false;
            }
            head2 = head2->next;
            head1 = head1->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        //Find Mid and break 
        ListNode* midNode = middleNode(head);
        //Now Break
        ListNode* head2 = midNode->next;
        midNode->next = NULL;
        //Reverse the other half
        head2 = reverseList(head2);
        //compare both halves
        return compareList(head, head2);
    }
};