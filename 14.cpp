class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (!strs.size()) return "";

        string res = "";
        
        int i, j;
        for (i=0; i<strs[0].size(); i++) {
            for (j=1; j<strs.size(); j++) {
                if (i>=strs[j].size() || strs[j][i] != strs[0][i]) {
                    break;
                }
            }

            if (j == strs.size()) {
                res += strs[0][i];
            }
            else {
                break;
            }
        }

        return res;
    }
};
