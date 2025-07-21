/*
basics of trie
*/
#include<iostream>
#include<unordered_map>

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
 
int main()
{
    //humne '-' liya hai root mein
    //aur koi bhi char bhi liya ja sakta hai.
    TrieNode* root = new TrieNode('-');
    
    insertIntoTrie(root, "cover");
    insertIntoTrie(root, "car");
    insertIntoTrie(root, "care");
    insertIntoTrie(root, "snake");
    insertIntoTrie(root, "fivefoot");
    insertIntoTrie(root, "extremelyWell");
    insertIntoTrie(root, "coward");
    insertIntoTrie(root, "selfobessed");
    insertIntoTrie(root, "tag");
    insertIntoTrie(root, "take");
    insertIntoTrie(root, "took");

    bool ans = searchIntoTrie(root, "fivefoot");
    if(ans)
    {
        cout<<"Found "<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }

    removeFromTrie(root, "cover");
    
    ans = searchIntoTrie(root, "cover");
    
    if(ans)
    {
        cout<<"Found "<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    
    return 0;
}
