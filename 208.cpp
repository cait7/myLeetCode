struct TrieNode {
    bool valid;
    TrieNode* next[26];
    TrieNode(): valid(false) {
        for (int i=0; i<26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ptr = root;
        for (int i=0; i<word.size(); i++) {
            char c = word[i];

            if (ptr->next[c-'a'] == NULL) {
                ptr->next[c-'a'] = new TrieNode();
            }

            ptr = ptr->next[c-'a'];

            if (i==word.size()-1) {
                ptr->valid = true;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ptr = root;
        for (int i=0; i<word.size(); i++) {
            char c = word[i];

            if (ptr->next[c-'a'] == NULL) {
                return false;
            }

            ptr = ptr->next[c-'a'];
        }

        return ptr->valid;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        for (int i=0; i<prefix.size(); i++) {
            char c = prefix[i];

            if (ptr->next[c-'a'] == NULL) {
                return false;
            }

            ptr = ptr->next[c-'a'];
        }

        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
