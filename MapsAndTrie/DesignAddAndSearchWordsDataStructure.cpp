/* Leet Code 211.

211. Design Add and Search Words Data Structure

Design a data structure that supports adding new words and
finding if a string matches any previously added string.

Implement the WordDictionary class:
WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:
1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode
{
    public:
    char data;
    unordered_map<char, TrieNode* > children;
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false){}
};

class Trie
{
    private:

    TrieNode* root;

    void insertUtil(TrieNode* root, string& word, int i = 0)
    {
        if(i == word.size())
        {
            root->isTerminal = true;
            return;
        }
        if(root->children.find(word[i]) == root->children.end())
        {
            root->children[word[i]] = new TrieNode(word[i]);
        }
        insertUtil(root->children[word[i]], word, i+1);
    }

    bool searchUtil(TrieNode* root, string& word, int i = 0)
    {
        if(i == word.size()) return root->isTerminal;
        bool matched = false;
        
        char ch = word[i];
        if(ch == '.')
        {
            // . can be matched to any child of current root TrieNode
            //C++17
            for(auto &[childChar, childNode]: root->children)
            {
                bool recurAns = searchUtil(root->children[childChar], word, i+1);
                if(recurAns)
                {
                    matched = recurAns;
                    break;
                }

                //oneliner of above all
                // matched = matched || searchUtil(root->children[childChar], word, i+1);
            }
        }
        else
        {
            if(root->children.find(word[i]) != root->children.end())
            {//present
                matched = searchUtil(root->children[word[i]], word, i+1);
            }
        }

        return matched;
    }

    public:

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string& word)
    {
        insertUtil(root, word);
    }

    bool search(string& word)
    {
        return searchUtil(root, word);
    }
};

class WordDictionary {
    Trie trie;
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */