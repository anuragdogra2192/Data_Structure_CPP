/* Leet code 14. Longest Common Prefix

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

Time complexity: O(nl)
n - length of vector
l - size of string
*/

#include<iostream>
#include<string>
#include<unordered_map>

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

void findlcp(TrieNode* root, string& ans)
{
    //base case
    if(root->isTerminal == true)
    {
        return;
    }

    //1 case mein solve 
    TrieNode* child;
    if(root->children.size() == 1)
    { //1k hi child hai
        for(auto i : root->children)
        {
            char ch = i.first;
            child = i.second;

            ans.push_back(ch);
        }
    }
    else
    {//multiple children or no children
        return;
    }
    findlcp(child, ans);
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        //insert all word into Trei
        for(auto str : strs)
        {
            insertWord(root, str);
        }

        //main logic
        string ans = "";
        findlcp(root, ans);
        return ans;
    }
};