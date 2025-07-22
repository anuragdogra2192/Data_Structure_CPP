/*Leet code 692. Top K Frequent Words

Given an array of strings words and an integer k, 
return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. 
Sort the words with the same frequency by their lexicographical order.

Example 1:
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:
1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
*/

#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

class comp
{
    public:
    bool operator()(const pair<int, string>& a, const pair<int, string>& b)
    {
       if (a.first == b.first)
            return a.second < b.second; // Lexicographically larger goes out first
        return a.first > b.first;
    }
};

class TrieNode
{
    public:
    char data;
    unordered_map<char, TrieNode* > children;
    bool isTerminal;
    int freq;

    TrieNode(char ch) : data(ch), isTerminal(false), freq(0){}
};

class Trie
{
    private:

    TrieNode* root;

    void insertUtil(TrieNode* root, string& word, int i = 0)
    {
        if(i >= word.size())
        {
            root->isTerminal = true;
            root->freq++;
            return;
        }
        if(root->children.find(word[i]) == root->children.end())
        {
            root->children[word[i]] = new TrieNode(word[i]);
        }
        insertUtil(root->children[word[i]], word, i+1);
    }

    void traverseUtil(TrieNode* root, string& s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int& k)
    {
        if(!root)
        {
            return;
        }

        if(root->isTerminal)
        {
            cout<<s<<" "<<root->freq<<endl;
            if(pq.size() < k)
            {
                pq.push({root->freq, s});
            }
            else if(pq.size() == k)
            {
                auto top = pq.top();
                if(root->freq > top.first ||
                (root->freq == top.first && s < top.second))//yeah bhul jata huin
                {
                    pq.pop();
                    pq.push({root->freq, s});
                }
            }
        }

         //1k case mein solve kar deta huin
        for(auto i : root->children)
        {
            char ch = i.first;
            TrieNode* child = i.second;
            s.push_back(ch);
            traverseUtil(child, s, pq, k);
            //back tracking
            s.pop_back();
        }
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

    void traverse( priority_queue<pair<int, string>, vector<pair<int, string>>, comp>& pq, int& k)
    {
        string s;
        traverseUtil(root, s, pq, k);
    }
};



class Solution {
public:
    Trie trie;
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        for(auto word : words)
        {
            trie.insert(word);
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq; //Min Heap
        trie.traverse(pq, k);

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            cout<<top.second<<" ";
            ans.push_back(top.second);
        }
        cout<<endl;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};