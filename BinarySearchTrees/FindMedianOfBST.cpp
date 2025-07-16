/** Geeks for geeks.
Median of BST
Given a Binary Search Tree, find the Median of its Node values.

Examples:

Input: root = [6, 3, 8, 1, 4, 7, 9]
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be: 1, 3, 4, 6, 7, 8, 9. So, here median will 6.
Input: root = [6, 3, 8, 1, 4, 7, N]
       6
     /   \
   3      8   
 /   \    /   
1    4   7   
Output: 5
Explanation:Inorder of Given BST will be: 1, 3, 4, 6, 7, 8. So, here median will (4 + 6)/2 = 10/2 = 5.
Input: root = [18, 16, 20, 7]
Output: 17

Constraints:
1<=n<=105

 * Median
 * Key Takeaways of Median
 * The median is the middle number in a sorted list of numbers and can be more descriptive of that dataset than the average.
 * The median is sometimes used rather than the mean when there are outliers in the sequence that might skew the average of the values.
 * If there is an ODD amount of numbers, 
        the median value is the number 
        that is in the middle, with the same amount of numbers below and above.
 * If there is an EVEN amount of numbers in the list,
        the middle pair must be determined, added together, and divided by two to find the median value.

        For odd n, median = ((n+1)/2)th term
        For even n, median = (((n/2)th term + ((n/2)+1 th term) / 2
*/

#include<iostream>
using namespace std;

//Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// your task is to complete the Function
//Using Morris traversal 2 times 
int findCountNode(Node* root) {
        int count = 0;
        Node* curr = root;
        while(curr)
        {
            //L left is null
            if(curr->left == nullptr)
            {   //N 
                count++;
                //R mein jao
                curr = curr->right;
            }
            else
            {//agar left hai toh
                //Step1: Find the predecessor, ek baar LEFT jao 
                //then RIGHT jate jao till null mil jaye.
                Node* predecessor = curr->left;
                while(predecessor->right != curr && predecessor->right)
                {
                    predecessor = predecessor->right;
                }
                //Step2: If Right node of predecessor is null then
                //establish the link FROM predecessor TO curr Node.
                //Finally curr go left.
                if(predecessor->right == nullptr)
                {
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else //agar Right node is not null
                {
                    //left is already visited, go right after visiting the curr and remove the Link.
                    predecessor->right = nullptr;//remove link
                    count++;
                    curr = curr->right;
                }
            }
        }
        return count;
    }
    
    float findActualMedian(Node* root, int n) {
        int i = 0;
        int odd1 = (n+1)/2, odd1Term = -1;
        int even1 = n/2, even1Term = -1;
        int even2 = n/2 + 1, even2Term = -1; 
        
        Node* curr = root;
        while(curr)
        {
            //L left is null
            if(curr->left == nullptr)
            {   //N
                i++;
                if(i == odd1) odd1Term = curr->data;
                if(i == even1) even1Term = curr->data;
                if(i == even2) even2Term = curr->data;
                //R mein jao
                curr = curr->right;
            }
            else
            {//agar left hai toh
                //Step1: Find the predecessor, ek baar LEFT jao 
                //then RIGHT jate jao till null mil jaye.
                Node* predecessor = curr->left;
                while(predecessor->right != curr && predecessor->right)
                {
                    predecessor = predecessor->right;
                }
                //Step2: If Right node of predecessor is null then
                //establish the link FROM predecessor TO curr Node.
                //Finally curr go left.
                if(predecessor->right == nullptr)
                {
                    predecessor->right = curr;
                    curr = curr->left;
                }
                else //agar Right node is not null
                {
                    //left is already visited, go right after visiting the curr and remove the Link.
                    predecessor->right = nullptr;//remove link
                    i++;
                    if(i == odd1) odd1Term = curr->data;
                    if(i == even1) even1Term = curr->data;
                    if(i == even2) even2Term = curr->data;
                    curr = curr->right;
                }
            }
        }
        float median = 0.0;
        if((n&1) == 0)
        {
            //even
            median = (even1Term + even2Term) / 2.0; 
        }
        else
        {//odd
            median = odd1Term;
        }
        return median;
    }
// Function should return median of the BST
float findMedian(struct Node *root) {
    // Code here
    int n = findCountNode(root);
    //cout<<n<<" \n";
    return findActualMedian(root, n);
}