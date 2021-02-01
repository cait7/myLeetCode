class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        int numOfCategory = 0;
        for (string &str: strs) {
            string keyValue = convertStr2Anagram(str);
            if (m.find(keyValue) == m.end()) {
                m[keyValue] = numOfCategory;
                vector<string> w;
                w.push_back(str);
                ans.push_back(w);
                numOfCategory++;
            }
            else {
                ans[m[keyValue]].push_back(str);
            }
        }
        return ans;
    }

    string convertStr2Anagram(string &str) {
        string s(26, 0);
        for (char c: str) {
            s[c-'a']++;
        }
        return s;
    }
};
