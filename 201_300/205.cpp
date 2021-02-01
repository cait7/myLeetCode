class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        set<char> values;
        unordered_map<char, char> m;
        for (int i=0; i<s.size(); i++) {
            char c1 = s[i], c2 = t[i];
            if (m.find(c1) == m.end()) {
                if (values.find(c2) != values.end()) {
                    return false;
                }
                m[c1] = c2;
                values.insert(c2);
            }
            else if (m[c1] == c2) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
