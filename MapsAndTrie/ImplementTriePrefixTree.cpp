/* Leet code 208.
208. Implement Trie (Prefix Tree)

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store
and retrieve keys in a dataset of strings. There are various applications of this data structure,
such as autocomplete and spellchecker.

Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

//Time complexity: O(l), l = length of string

*/

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class TrieNode
{
public:

    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

public:

    TrieNode(char val)
    {
        data = val;
        isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //1k case mein karunga
        char ch = word[0];
        TrieNode* child;
        if(root->children.find(ch) != root->children.end())
        {//present
            child = root->children[ch];
        }
        else
        {//Absent
            child = new TrieNode(ch);
            //link
            root->children[ch] = child;
        }
        //Baaki recursion sambhalega
        insertWord(child, word.substr(1));
    }

    bool searchWord(TrieNode* root, string word)
    {
        //base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        //1k case mein karunga
        char ch = word[0];
        TrieNode* child;
        if(root->children.find(ch) != root->children.end())
        {//present
            child = root->children[ch];
        }
        else
        {//Absent
            return false;
        }
        //Baaki recursion sambhalega
        bool recurAns = searchWord(child, word.substr(1));
        return recurAns;
    }

    bool searchPrefix(TrieNode* root, string prefix)
    {
        //base case
        if(prefix.length() == 0)
        {
            return true;
        }

        //1k case mein karunga
        char ch = prefix[0];
        TrieNode* child;
        if(root->children.find(ch) != root->children.end())
        {//present
            child = root->children[ch];
        }
        else
        {//Absent
            return false;
        }
        //Baaki recursion sambhalega
        bool recurAns = searchPrefix(child, prefix.substr(1));
        return recurAns;
    }

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('-');
    }
    
    void insert(string word) {
        insertWord(root, word);
    }
    
    bool search(string word) {
        return searchWord(root, word);
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */