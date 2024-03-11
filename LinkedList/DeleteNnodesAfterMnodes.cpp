//Delete N nodes after M nodes of a linked list
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here   
        if(!head) return;//dont forget this. case
        
        Node* MthNode = head;
        
        //Traverse M nodes
        for(int i = 0; i<M-1; i++)
        {
            if(!MthNode) return;// if null then return
            MthNode = MthNode->next; 
        }
        
        //Now delete N nodes
        if(!MthNode) return;
        Node* it = MthNode->next;

        for(int i = 0; i < N; i++)
        {
            if(!it) break;/* if null then break the loop
            And then connect the MthNode->next to it.
            */
            Node* nextNode = it->next;
            delete it;
            it = nextNode;
        }
        
        MthNode->next = it;
        linkdelete(it, M, N);
    }
};