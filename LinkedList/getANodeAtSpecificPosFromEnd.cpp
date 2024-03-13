/**
 * Hacker rank
 * https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem?isFullScreen=true
*/
/*
 * Complete the 'getNode' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER positionFromTail
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void getThePositionData(SinglyLinkedListNode* head, int &ans, int &positionFromTail)
{
    if(head == 0)
        return;
    getThePositionData(head->next, ans, positionFromTail);
    //
    if(positionFromTail == 0)
    {
        ans = head->data;
    }
    positionFromTail--;
}
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int ans = -1;
    getThePositionData(llist, ans, positionFromTail);
    return ans;
}