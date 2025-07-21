/*
basics of trie and Auto suggestion 
*/
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class TrieNode
{
    public:
    char value;
    unordered_map<int, TrieNode* > children;
    bool isTerminal;

    TrieNode(char data)
    {
        value = data;
        isTerminal = false;
    }
};
//Time complexity: O(l), l = length of string
bool searchIntoTrie(TrieNode* root, string word)
{
    //base case
    //last character terminal hai ya nahi 
    if(word.length() == 0)
    {
        // if(root->isTerminal == true)
        // {
        //     return true;
        // }
        // return false;
        return root->isTerminal;
    }

    //1k case mein sambhalunga
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end())
    {//present
        child = root->children[ch];
    }
    else
    {//absent
        return false;
    }
    //baaki recursion sambhalega
    bool recAns = searchIntoTrie(child, word.substr(1));
    return recAns;
}

//Time complexity: O(l), l = length of string
void insertIntoTrie(TrieNode* root, string word)
{
    //base case
    //ek time aisa aayega jab aapki word empty ho jayega
    if(word.length() == 0)
    {
        //set terminal
        root->isTerminal = true;
        return;
    }

    //1k case solve karna
    //1k character ko tie mein insert kar deta huin
    char ch = word[0];
    TrieNode* child;
    
    //Check
    if(root->children.count(ch) == 1)
    {//present hai toh waha chale jao
        child  = root->children[ch];
    }
    else
    {//absent hai toh create kardo
        child = new TrieNode(ch);
     //link
        root->children[ch] = child;
    }
    //Baaki recursion sambhalega
    //agli node bhej do, which is child
    //1st char chodke baaki bhejdo
    insertIntoTrie(child, word.substr(1));

}

void removeFromTrie(TrieNode* root, string word)
{
    // Base case
    if(word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    // 1 case mein solve karunga
    char ch = word[0];
    TrieNode* child; 
    if(root->children.find(ch) != root->children.end())
    {//present hai to waha chale jao 
        child = root->children[ch];
    }
    else
    {//absent
        return;
    }
    // Baaki recursion sambhalega
    removeFromTrie(child, word.substr(1));
}

void storeString(TrieNode* root, vector<string>& ans, string output)
{
    //base case
    if(root->isTerminal == true)
    {
        ans.push_back(output);
        //no need to return as we want all the words.
    }

    //1k case mein solve kar deta huin
    for(auto i:root->children)
    {
        char ch = i.first;
        TrieNode* child = i.second;
        output.push_back(ch);
        storeString(child, ans, output);
        //back tracking
        output.pop_back();
    }
}


void findWordsWithPrefix(TrieNode* root, string prefix, vector<string>& ans)
{
    //base case
    if(prefix.length() == 0)
    {//prefix pooora search ho chuka hai
     //And root abhi prefix string k last character ko store kari hogi.
     //ab is last node ke nicche jitni bhi strings ban sakti hai, unko create kar ke store kar lo
     //using below function
     string temp = "";
     storeString(root, ans, temp);
     return;
    }
    //1k case hum karenge
    char ch = prefix[0];
    TrieNode* child;
    
    if(root->children.find(ch) != root->children.end())
    {
        //present
        child = root->children[ch];
    }
    else
    {
        //absent
        return;
    }
    //baki recursion sambhal lega
    findWordsWithPrefix(child, prefix.substr(1), ans);
}

vector<vector<string>> getSuggestions(TrieNode* root, string prefix)
{
    vector<vector<string>> ans;
    string temp = "";
    for(int i=0; i<prefix.length(); i++)
    {
        vector<string> tempAns;
        char curChar = prefix[i];
        temp.push_back(curChar);
        findWordsWithPrefix(root, temp, tempAns);
        //add prefix in tempAns array
        for(int j=0; j<tempAns.size(); j++)
        {
            tempAns[j] = temp + tempAns[j];
        }
        ans.push_back(tempAns);
    }
    return ans;
}

int main()
{
    //humne '-' liya hai root mein
    //aur koi bhi char bhi liya ja sakta hai.
    TrieNode* root = new TrieNode('-');
    
    insertIntoTrie(root, "babbar");
    insertIntoTrie(root, "baba");
    insertIntoTrie(root, "baboo");
    insertIntoTrie(root, "baby");
    insertIntoTrie(root, "bala");

    string prefix = "bab";

    vector<vector<string>> ans = getSuggestions(root, prefix);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<", ";
        }
        cout<<endl;
    }
    // vector<string> ans;
    // findWordsWithPrefix(root, prefix, ans);
    
    // for(int i=0; i<ans.size(); i++)
    // {
    //     string str = prefix + ans[i];
    //     ans[i] = str;
    //     cout<< ans[i] <<" ";
    // }
    // cout<<endl;


    return 0;
}
