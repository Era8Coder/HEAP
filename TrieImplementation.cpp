#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    // Pointer Array for child of each Nodes
    TrieNode* childNode[26];                // 26 block of memory <<--          // Here we are creating pointers in each of the index 
    // Basically the array of pointers to next Triennode
    bool isWordEnd;

    TrieNode(){             // Constructor of Class
        isWordEnd = false;
        for(int i=0; i<26; i++){
            childNode[i] = NULL;
        }
    }
};

// Insertion Time Complexity
/*
    Time Complexity = O(Number of Words * Max Length of Words)
    SpaceComplexity = O(Number of Words * Max Length of Words)
*/
void insert_key(TrieNode* root, string &key){
    // Initialise the Root Pointer with Root Node
    TrieNode* curr_node = root;             // Initialising the root as current Node

    // Iterating over the String
    for(int i=0; i<key.size(); i++){
        // Check that we can insert or Not
        if(curr_node->childNode[key[i]-'a'] == NULL){        // Checking that already a node exist for character or not
            TrieNode* new_node = new TrieNode();
            curr_node->childNode[key[i]-'a'] = new_node;     // Making it the new node <<--||-->>
        }
        curr_node = curr_node->childNode[key[i] - 'a'];      // Now move the curr pointer to the newly Made Node
    }

    curr_node->isWordEnd = true;
}

// Search Time Complexity 
/*
    Time Complexity = O(n)
    SpaceComplexity = O(1);
*/
bool search_key(TrieNode* root, string &key){
    // Initialise the current pointer as root
    TrieNode* curr = root;

    // Iterate over the string
    for(int i=0; i<key.size(); i++){
        if(curr->childNode[key[i] - 'a'] == NULL){
            return false;           // Given word doesn't exist in Trie since we had traversed the whole key
        }
        curr = curr->childNode[key[i] - 'a'];
    }

    return (curr -> isWordEnd == true);         // If end of word is true then return true else return false
}

bool startsWith(string prefix) {
    int length = prefix.size();
    int k = 0;
    trienode* curr = root;
    for(int i=0; i<length; i++){
        k = prefix[i] - 'a';
        curr = curr -> children[k];
        if(curr ==  nullptr){
            return false;
        }
    }
    return true;
}

int main(){
    // Make a root Node for Trie
    TrieNode* root = new TrieNode();
    vector<string> input = {"and", "ant", "do", "geek", "dad", "ball"};         // We have to insert these Strings

    // Number of INSERT OPERATIONS 
    int n = input.size();
    for(int i=0; i<n; i++){
        insert_key(root, input[i]);         // Inserting of String
    }
    
    vector<string> search_query = {"do", "geek", "bat"};
    int k = search_query.size();

    for(int i=0; i<k; i++){
        cout << search_query[i] << endl;
        if(search_key(root, search_query[i])){
            cout << "Yes it's Present." << endl;
        }else{
            cout << "No, it's Not Present." << endl;
        }
    }
    return 0;
}
