class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> m;
        set<char> values;
        vector<string> words = mySplit(s, ' ');
        if (words.size() != pattern.size()) {
            return false;
        }
        for (int i=0; i<pattern.size(); i++) {
            if (m.find( words[i] ) == m.end() && values.find(pattern[i]) == values.end()) {
                m[ words[i] ] = pattern[i];
                values.insert(pattern[i]);
            }
            else if (m[ words[i] ] == pattern[i]) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }

    vector<string> mySplit(string &s, char splitChar) {
        vector<string> ans;
        string aStr;
        for (char c: s) {
            if (c == splitChar) {
                ans.push_back(aStr);
                aStr = "";
                continue;
            }
            aStr += c;
        }
        ans.push_back(aStr);
        return ans;
    }
};
