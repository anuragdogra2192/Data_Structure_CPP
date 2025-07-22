/* Leet code 1023. Camelcase Matching

Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.

A query word queries[i] matches pattern if you can insert lowercase English letters into the pattern so that it equals the query. You may insert a character at any position in pattern or you may choose not to insert any characters at all.


Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

Constraints:

1 <= pattern.length, queries.length <= 100
1 <= queries[i].length <= 100
queries[i] and pattern consist of English letters.

Time complexity: O(Pl) + O(n*m); pl - size of pattern, n - no of queries
and m is the length of the query.

Space Complexity: O(pl), pl - size of pattern
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

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
        if(i == word.size()) 
        {
            return root->isTerminal;
        }

        char ch = word[i];
        if(root->children.find(ch) != root->children.end())
        {
            if(searchUtil(root->children[ch], word, i+1))
            {
                return true;
            }
        }
        else if(islower(ch))
        {
            return searchUtil(root, word, i+1);
        }
        // here uppercase ch, which is not equal to the pattern
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

class Solution {
    Trie trie;
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        trie.insert(pattern);

        for(auto query : queries)
        {
            ans.push_back(trie.search(query));
        }
        return ans;
    }
};