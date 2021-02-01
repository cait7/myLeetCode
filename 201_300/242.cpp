class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> letters(26, 0);
        if (s.size() != t.size()) return false;
        for (int i=0; i<s.size(); i++) {
            letters[s[i]-'a']++;
            letters[t[i]-'a']--;
        }
        for (int i=0; i<26; i++) {
            if (letters[i]) {
                return false;
            }
        }
        return true;
    }
};
