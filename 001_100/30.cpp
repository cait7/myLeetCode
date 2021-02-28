class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // words 的去重
        unordered_map<string, int> str2Int;
        for (auto& str: words) {
            if (str2Int.find(str) == str2Int.end()) {
                str2Int[str] = 1;
            }
            else {
                str2Int[str]++;
            }
        }
        vector<string> wordsWithNoDuplicate;
        vector<int> contains;
        for (auto& ele: str2Int) {
            wordsWithNoDuplicate.push_back(ele.first);
            contains.push_back(ele.second);
        }
        int total = words.size();
        words = wordsWithNoDuplicate;
        // 建立 table
        vector<int> m(s.size(), -1);
        for (int i=0; i<s.size(); i++) {
            for (int j=0; j<words.size(); j++) {
                if (isMatching(words[j], s, i)) {
                    m[i] = j;
                    break;
                }
            }
        }
        // search
        vector<int> ans;
        int count, index;
        for (int i=0; i<s.size(); i++) {
            vector<int> visited = contains;
            count = total;
            index = i;
            while(count && index < s.size()) {
                if (m[index] != -1 && visited[ m[index] ]) {
                    visited[ m[index] ]--;
                    count--;
                    index += words[0].size();
                }
                else {
                    break;
                }
            }
            if (!count) {
                ans.push_back(i);
            }
        }
        return ans;
    }

    bool isMatching(string& str, string& s, int index) {
        for (int i=0; i<str.size(); i++) {
            if (i+index >= s.size() || str[i] != s[i+index]) {
                return false;
            }
        }
        return true;
    }
};
