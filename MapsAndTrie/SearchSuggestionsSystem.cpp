/* Leet code 1268.
1268. Search Suggestions System

Highly important.
Companies - Amazon.

You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products
 after each character of searchWord is typed. 
 Suggested products should have common prefix with searchWord. 
 If there are more than three products with 
 a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

Example 1:
Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
After typing mou, mous and mouse the system suggests ["mouse","mousepad"].

Example 2:
Input: products = ["havana"], searchWord = "havana"
Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
Explanation: The only word "havana" will be always suggested while typing the search word.
 

Constraints:
1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class TrieNode
{
    public:
    char data;
    unordered_map<char, TrieNode* > children;
    bool isTerminal;
    string word;
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
            root->word = word;
            return;
        }
        if(root->children.find(word[i]) == root->children.end())
        {
            root->children[word[i]] = new TrieNode(word[i]);
        }
        insertUtil(root->children[word[i]], word, i+1);
    }

    TrieNode* searchPrefixUtil(TrieNode* root, string& prefix, int i = 0)
    {
        if(i >= prefix.size()) 
        {
            //prefix matching is completed
            //now we have to return all the terminal words
            return root;
        }

        char ch = prefix[i];
        if(root->children.find(ch) != root->children.end())
        {//present
            return searchPrefixUtil(root->children[ch], prefix, i+1);
        }

        return NULL;
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

    void collectAllWords(TrieNode* root, vector<string>& ans)
    {
        if(!root) return;
        if(root->isTerminal)
        {
            ans.push_back(root->word);
        }
        for(auto &[childChar, childNode]:root->children)
        {
            collectAllWords(childNode, ans);    
        }
    }

    vector<string> searchPrefix(string& prefix)
    {
        TrieNode* prefixNode = searchPrefixUtil(root, prefix);
        vector<string> ans;

        if(prefixNode)
        {
            //collect all the words.
            collectAllWords(prefixNode, ans);
        }
        return ans;
    }
};

class Solution {
    Trie trie;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> ans;

        //insert all products.
        for(auto& product : products)
        {
            trie.insert(product);
        }

        //search with searchWord being typed char by char.
        string prefix = "";
        
        //this loop is simulating char by char typing of the searchWord
        for(auto ch : searchWord)
        {
            prefix += ch;
            //get all word with current prefix
            vector<string> suggestions = trie.searchPrefix(prefix);
            sort(suggestions.begin(), suggestions.end());

            if(suggestions.size() > 3)
            {
                suggestions.resize(3);
            }
            ans.push_back(suggestions);
        }
        return ans;
    }
};