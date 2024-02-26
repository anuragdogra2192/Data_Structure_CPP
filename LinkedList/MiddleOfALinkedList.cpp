//Leet Code 876: Middle of a linked list
/*
 * Normal approach
 In this question it is given
 midpos = n/2 + 1

 It works, but here we are making a mistake:
 Here we are doing to 2 passes:
    * first traverse to get the length of LL: len -> O(N)
    * sencond we are traversing to find the mid -> O(N/2)  

 But we do have a approch which can do it in single pass:
    * Slow and Fast approach -- A Tortoise algorithm
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
        size_t length=0;
        ListNode* temp = head;
        while(temp!= NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* middleNode(ListNode* head)
    {
        /* In this question it is given
            midpos = n/2 + 1
        */
        size_t n = getLength(head);
        int position = n/2 + 1;
        int currPos = 1;
        ListNode* temp = head;
        while(currPos != position)
        {
            temp = temp->next;
            currPos++;
        }
        return temp;
    }
};