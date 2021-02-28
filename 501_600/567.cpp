class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> letters(26, 0), curr(26, 0);
        for (auto c: s1) {
            letters[c-'a']++;
        }
        for (int i=0; i<s1.size(); i++) {
            curr[ s2[i]-'a' ]++;
        }
        if (curr == letters) {
            return true;
        }
        for(int left = s1.size(); left < s2.size(); left++) {
            curr[ s2[left-s1.size()] - 'a' ]--;
            curr[ s2[left] - 'a' ]++;
            if (curr == letters) {
                return true;
            }
        }
        return false;
    }
};
