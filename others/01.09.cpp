class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        bool ans = true;
        for (int i=0; i<s2.size(); i++) {
            ans = true;
            for (int j=0; j<s1.size(); j++) {
                if (s2[(i+j)%s2.size()] != s1[j]) {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                return true;
            }
        }
        return ans;
    }
};
