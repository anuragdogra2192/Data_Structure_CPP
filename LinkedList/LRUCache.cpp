/* Leet code 146.
146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.


Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

#include<iostream>
#include<unordered_map>
using namespace std;
class LRUCache {
public:
    class Node
    {
        public:
            int key;
            int value;
            Node* prev;
            Node* next;

            Node(int k, int v)
            {
                key = k;
                value = v;
                prev = next = NULL;
            }
    };

// LRU -> at end of dll, prev to tail
// MRU -> at the start of DLL, next to head

    //Lest make head and tail and keep them constant
    Node* head = new Node(-1, -1); 
    Node* tail = new Node(-1, -1);

    //unordered map to stack the key and Node*
    unordered_map<int, Node*> hash;
    int limit = 0;
    LRUCache(int capacity) {
        //intial state
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        int ans = -1;
        if(hash.find(key) != hash.end())
        {//found
            Node* ansNode = hash[key];
            ans = ansNode->value;
            hash.erase(key);
            delNode(ansNode);//i.e. why we unlink, not delete.
            // Now make ansNode MRU
            insertNode(ansNode); 
            //update map
            hash[key] = ansNode;
        }
        return ans;
    }

    void put(int key, int value) {

        if(hash.find(key) != hash.end())
        {//found node
            Node* oldNode = hash[key];
            delNode(oldNode);
            hash.erase(key); 
        }

        //If capacity is full
        if(hash.size() == limit)
        {
            hash.erase(tail->prev->key);
            delNode(tail->prev);
        }
        //make new.
        Node* newNode = new Node(key, value);
        insertNode(newNode);
        hash[key] = newNode;
    }
    //Helpers
    void insertNode(Node* newNode)
    {
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;
        
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode(Node* oldNode)// only unlink it
    {   
        if(oldNode == NULL)
        {   return; }
        
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;
        
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */