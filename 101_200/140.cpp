struct letterNode {
    letterNode **nextPtr;
    bool valid;
    letterNode() {
        valid = false;
        nextPtr = new letterNode* [26];
        for (int i=0; i<26; i++) {
            nextPtr[i] = nullptr;
        }
    }
    ~letterNode() {
        delete [] nextPtr;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new letterNode();
        for (string& str: wordDict) {
            addWord(str);
        }
        vector<string> res;
        res = buildSentence(s, 0);
        return res;
    }

    vector<string> buildSentence(string &s, int begin) {
        letterNode *ptr = root;
        vector<string> res;
        string prefix = "";
        if (begin >= s.size()) {
            return vector<string>(1, "");
        }
        for (int i=begin; i<s.size(); i++) {
            if (ptr->nextPtr[s[i]-'a'] != nullptr) {
                prefix += s[i];
                ptr = ptr->nextPtr[s[i]-'a'];
                if (ptr->valid) {
                    vector<string> sList;
                    sList = buildSentence(s, i+1);
                    for (string &str: sList) {
                        if (str == "") {
                            res.push_back(prefix);
                        }
                        else {
                            res.push_back(prefix + " " + str);
                        }
                    }
                }
            }
            else {
                break;
            }
        }
        return res;
    }

    void addWord(string &str) {
        letterNode *ptr = root;
        for (char& c: str) {
            if (ptr->nextPtr[c-'a'] == nullptr) {
                ptr->nextPtr[c-'a'] = new letterNode ();
            }
            ptr = ptr->nextPtr[c-'a'];
        }
        ptr->valid = true;
    }

private:
    letterNode *root;
};
