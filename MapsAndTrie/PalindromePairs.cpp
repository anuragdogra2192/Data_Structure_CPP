/* Leet code 336.
336. Palindrome Pairs

You are given a 0-indexed array of unique strings words.

A palindrome pair is a pair of integers (i, j) such that:

0 <= i, j < words.length,
i != j, and
words[i] + words[j] (the concatenation of the two strings) is a palindrome.
Return an array of all the palindrome pairs of words.

You must write an algorithm with O(sum of words[i].length) runtime complexity.

 

Example 1:

Input: words = ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]]
Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
Example 2:

Input: words = ["bat","tab","cat"]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["battab","tabbat"]
Example 3:

Input: words = ["a",""]
Output: [[0,1],[1,0]]
Explanation: The palindromes are ["a","a"]
 

Constraints:

1 <= words.length <= 5000
0 <= words[i].length <= 300
words[i] consists of lowercase English letters.
Time complexity: O(n*k^2)
n - words array size.
k - length of longest string.

Space complexity: O(n*k)
*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class TrieNode
{
    public:
    char data;
    unordered_map<char, TrieNode* > children;
    //bool isTerminal;
    int stringNumber;//original words array index of that string
    TrieNode(char ch) : data(ch), stringNumber(-1){}
};

class Trie
{
    private:

    TrieNode* root;

    void insertUtil(TrieNode* root, string& word, int i, int& stringNumber)
    {
        if(i >= word.size())
        {
            root->stringNumber = stringNumber;
            return;
        }
        if(root->children.find(word[i]) == root->children.end())
        {
            root->children[word[i]] = new TrieNode(word[i]);
        }
        insertUtil(root->children[word[i]], word, i+1, stringNumber);
    }
    public:

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string& word, int& stringNumber)
    {
        insertUtil(root, word, 0, stringNumber);
    }

    bool isPalindrome(string& s, int low, int high)
    {
        while(low <= high)
        {
            if(s[low] != s[high])
            {
                return false;
            }
            low++, high--;
        }
        return true;
    }

    void searchCase2(TrieNode* root, vector<int>&  myPalindrome, string& s)
    {
        if(root->stringNumber != -1)
        {
            if(isPalindrome(s, 0, s.size()-1))
            {
                 myPalindrome.push_back(root->stringNumber);
            }
        }
         //1k case mein solve kar deta huin
        for(auto& [ch, child] : root->children)
        {
            s.push_back(ch);                     // Backtrack push
            searchCase2(child, myPalindrome, s);
            s.pop_back();                        // Backtrack pop
        }
    }

    void search(string& word, vector<int>& myPalindrome)
    {
        TrieNode* curr = root;
        //Case 1: When prefix of string word, exactly matches with the word in trie.
        for(int i=0; i<word.size(); i++)
        {
            char ch = word[i];
            if(curr->stringNumber != -1)
            {//check rest of the search word is palindrome
                if(isPalindrome(word, i, word.size()-1))
                {
                    myPalindrome.push_back(curr->stringNumber);
                }
            }
            if(curr->children.find(word[i]) != curr->children.end())
            {//present hai
                curr = curr->children[ch];
            }
            else
                return;
        }

        //Case 2: Search-word is a prefix of the word in the trie
        //check remaining subtrees in the trie for the palindrome.
        string s = "";
        searchCase2(curr, myPalindrome, s);
    }
};

class Solution {
    Trie trie;
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        //insert all words in reverse order and mark its stringNumber as index of words.
        for(int i=0; i< words.size(); i++)
        {
            auto reverseword = words[i];
            reverse(reverseword.begin(), reverseword.end());
            trie.insert(reverseword, i);
        }

        //find palindromic pairs of each word
        for(int i=0; i<words.size(); i++)
        {
            vector<int> myPalindrome; //this vector will store the indices of palindromic pairs of ith index word.
            trie.search(words[i], myPalindrome);
            for(auto j:myPalindrome)
            {
                if(i != j)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};