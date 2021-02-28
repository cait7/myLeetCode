struct Treenode {
    Treenode *next[26];
    priority_queue<string, vector<string>, less<string>> q;
    bool exist;
    Treenode() {
        exist = false;
        for (int i=0; i<26; i++) {
            next[i] = NULL;
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Treenode();
        for (auto &str: products) {
            insert(str);
        }
        vector<vector<string>> ans(searchWord.size(), vector<string>());
        int index = 0;
        Treenode *ptr = root;
        for (char c: searchWord) {
            ptr = ptr->next[ c - 'a' ];
            if (ptr == NULL) {
                break;
            }
            priority_queue<string, vector<string>, less<string>> q = ptr->q;
            vector<string> strList, reverseStrList;
            while (!q.empty()) {
                strList.push_back( q.top() );
                q.pop();
            }
            for (int i=strList.size()-1; i>=0; i--) {
                reverseStrList.push_back( strList[i] );
            }
            ans[index++] = reverseStrList;
        }
        return ans;
    }

    void insert(string& str) {
        Treenode *ptr = root;
        for (char c: str) {
            if (ptr->next[ c - 'a' ] == NULL) {
                ptr->next[ c - 'a' ] = new Treenode();
            }
            ptr = ptr->next[ c - 'a' ];
            ptr->q.push(str);
            if (ptr->q.size() > 3) {
                ptr->q.pop();
            }
        }
        ptr->exist = true;
    }


private:
    Treenode *root;
};
