/* Leet code 648. Replace Words

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"

Constraints:
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.

Time complexity: O(n), n is the number of words in the sentence
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

    bool searchUtil(TrieNode* root, string& word, int& i)
    {
        if(root->isTerminal) 
        {
            return true;
        }

        char ch = word[i];
        i = i+1;
        if(root->children.find(ch) != root->children.end())
        {
            return searchUtil(root->children[ch], word, i); 
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

    int search(string& word)
    {
        int i = 0;
        if(searchUtil(root, word, i))
        {
            return i;
        }
        return -1;
    }
};

class Solution {
    Trie trie;
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        //insert dict into root
        for(auto root : dictionary)
        {
            trie.insert(root);
        }

        //pick each word in sentence and find in the trie whether the root is available or not
        int start = 0, end = 0;
        while(end < sentence.size())
        {
            if(sentence[end] == ' ' || end == sentence.size() - 1)
            {
                int len = (end == sentence.size()-1 ? end-start+1 : end - start);
                string word = sentence.substr(start, len);
                int trieMatchIndex = trie.search(word);
                ans += trieMatchIndex != -1 ? word.substr(0, trieMatchIndex) : word;
                if(sentence[end] == ' ')
                {
                    ans += " ";
                }
                start = end + 1;
            }
            end++;
        }
        return ans;
    }
};