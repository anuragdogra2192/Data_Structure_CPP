/** Geeks for Geeks
 * https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
 * Flattening a Linked List 
 * Highly important: Double recursion :)
*/
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* merge(Node *a, Node* b)
{
    if(!a) return b;
    if(!b) return a;
    Node* ans = NULL;
    if(a->data < b->data)
    {
        ans = a;
        a->bottom = merge(a->bottom, b);
    }
    else
    {
        ans = b;
        b->bottom = merge(a, b->bottom);
    }
    return ans;
}

Node *flatten(Node *root)
{
   // Your code here
   if(!root) return NULL;
   Node* mergedLL = merge(root, flatten(root->next));
   return mergedLL;
}