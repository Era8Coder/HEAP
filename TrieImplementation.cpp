#include<bits/stdc++.h>
using namespace std;

struct trienode{
    bool isendofword;       // it will tell us about node that whether word is ending there or nor
    trienode* children[26];  // 26 characters array

    trienode(){
        isendofword = false;
        for(int i=0; i<26; i++){
            children[i] = nullptr;
        }
    }
};

class Trie {
trienode* root;     // that is root of my trie(prefic tree)

public:
    Trie() {
        root = new trienode();      // i am creating a new node here of trie which we want to make and it will act as my root
    }
    
    void insert(string word) {
        int length = word.size();
        int k = 0;
        trienode* curr = root;

        for(int i=0; i<length; i++){
            k = word[i] - 'a';
            if(curr->children[k] == nullptr){       // that is no character is there
                curr->children[k] = new trienode();
            }

            curr = curr -> children[k];
        }
        curr->isendofword = true;
    }
    
    bool search(string word) {
        int length = word.size();
        int k = 0;
        trienode* curr = root;

        for(int i=0; i<length; i++){
            k = word[i] - 'a';
            curr = curr -> children[k];

            if(curr == NULL){       // agar current pehle hee NULL ho jaye toh 
                return false;
            }
        }

        // agar size tak traverse kar liya phir check karo ko isendofword kya hai ??
        return curr -> isendofword;
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
