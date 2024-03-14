/**
 * Leet code: 61 Rotate List
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
    int getLength(ListNode* head)
    {
        int len = 0;
        while(head!=NULL)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int len = getLength(head);
        int actualrotatek = k % len;
        
        if(actualrotatek == 0) return head;

        int newLastNodePos = len - actualrotatek - 1;
        ListNode* newNodeLast = head;
        
        for(int i =0; i<newLastNodePos; i++)
        {
            newNodeLast = newNodeLast->next;
        }

        ListNode* newHead = newNodeLast->next;
        newNodeLast->next = NULL;

        ListNode* temp = newHead;
        
        while(temp->next)
        {
            temp=temp->next;
        }
        
        temp->next = head;

        return newHead;

    }
};