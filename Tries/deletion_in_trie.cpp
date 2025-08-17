#include<iostream>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){  
        data = ch;
        for(int i =0; i<26 ;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode* root ;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root , string word)
    {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] !=NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child , word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root , word);
    }


    bool searchUtil(TrieNode* root , string word)
    {
        if(word.length() == 0){
            return root->isTerminal ;
        }

        int index = word[0] - 'A' ;
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child , word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root , word);
    }

    //function to check if a node has any children
    bool hasChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL) {
                return true;
            }
        }
        return false;
    }

    bool deleteUtil(TrieNode* root, string word, int depth = 0) {
        if (root == NULL) return false; // Agar root hi null hai to return false

        // Base Case: Agar pura word traverse ho gaya
        if (depth == word.size()) {
            if (!root->isTerminal) return false; // Word exist nahi karta
            root->isTerminal = false; // Word ko non-terminal mark karna

            // Agar koi aur child nahi hai to node delete ho sakti hai
            return !hasChildren(root);
        }

        int index = word[depth] - 'A';
        TrieNode* child = root->children[index];

        if (!deleteUtil(child, word, depth + 1)) return false; // Recursive delete call

        // Agar child delete ho chuka hai, to current node ko bhi check karo
        delete child;
        root->children[index] = NULL;

        // Agar current node bhi empty hai to delete ho sakta hai
        return !hasChildren(root) && !root->isTerminal;
    }

    void deleteWord(string word) {
        deleteUtil(root, word);
    }
};

int main()
{
    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("ARROW");

    string word = "ARM";

    cout << "Before Deletion: " << endl;
    if (t->searchWord(word)) {
        cout << "Word '" << word << "' is Present." << endl;
    } else {
        cout << "Word '" << word << "' is Not Present." << endl;
    }

    t->deleteWord(word);

    cout << "After Deletion: " << endl;
    if (t->searchWord(word)) {
        cout << "Word '" << word << "' is Present." << endl;
    } else {
        cout << "Word '" << word << "' is Not Present." << endl;
    }

    return 0;
}
