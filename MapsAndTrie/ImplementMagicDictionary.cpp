/* Leet code 676.

676. Implement Magic Dictionary

Design a data structure that is initialized with a list of different words. 
Provided a string, you should determine if you can change exactly one character
in this string to match any word in the data structure.

Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.
 

Example 1:

Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False
 

Constraints:

1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case English letters.
All the strings in dictionary are distinct.
1 <= searchWord.length <= 100
searchWord consists of only lower-case English letters.
buildDict will be called only once before search.
At most 100 calls will be made to search.
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

    bool searchUtil(TrieNode* root, string& word, int i = 0, bool misMatch = false)
    {
        if(i == word.size()) 
        {
            return misMatch && root->isTerminal;
        }

        char ch = word[i];
        if(root->children.find(ch) != root->children.end())
        {//match till you can
            if(searchUtil(root->children[ch], word, i+1, misMatch))
            {
                return true;
            }
        }

        //if I am here means there is a misMatch
        if(!misMatch)
        {
            for(auto &[childChar, childNode]: root->children)//check all children
            {   //ch != childChar yeah bhul jata huin,
                if((ch != childChar) && searchUtil(childNode, word, i+1, true))
                {
                    return true;
                }
            }
        }
        return false;
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

class MagicDictionary {
    Trie trie;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& word : dictionary)
        {
            trie.insert(word);
        }
    }
    
    bool search(string searchWord) {
        return trie.search(searchWord);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */