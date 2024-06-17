#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isendofword;
    TrieNode* children[26];

    TrieNode() {
        isendofword = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int len = word.size();
        int k = 0;
        TrieNode* curr = root;

        for(int i = 0; i < len; i++) {
            k = word[i] - 'a';
            if(curr->children[k] == NULL) {
                curr->children[k] = new TrieNode();
            }
            curr = curr->children[k];
        }
        curr->isendofword = true;
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }

private:
    bool searchInNode(string& word, int index, TrieNode* node) {
        TrieNode* curr = node;
        for (int i = index; i < word.size(); i++) {
            char ch = word[i];
            if (ch == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curr->children[j] && searchInNode(word, i + 1, curr->children[j])) {
                        return true;
                    }
                }
                return false;
            } else {
                int k = ch - 'a';
                if (curr->children[k] == NULL) {
                    return false;
                }
                curr = curr->children[k];
            }
        }
        return curr->isendofword;
    }
};

int main(){

    return 0;
}