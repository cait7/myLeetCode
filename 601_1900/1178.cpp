class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<string, int> m;
        // 状态压缩-迷底
        for (auto& str: words) {
            string s = str2State(str);
            if (m.find(s) == m.end()) {
                m[s] = 1;
            }
            else {
                m[s] += 1;
            }
        }
        vector<int> ans(puzzles.size(), 0);
        // subset 的 0-1 编码
        vector<vector<int>> status( {vector<int>({1})} );
        for (int i=0; i<6; i++) {
            int size = status.size();
            for (int j=0; j<size; j++) {
                vector<int> subset = status[j];
                subset.push_back(1);
                status[j].push_back(0);
                status.push_back(subset);
            }
        }
        // 遍历 puzzles
        for (int i=0; i<puzzles.size(); i++) {
            for (auto& s: status) {
                string substring = str2State_v2(puzzles[i], s);
                if (m.find(substring) != m.end()) {
                    ans[i] += m[substring];
                }
            }
        }
        return ans;
    }

    string str2State(string &str) {
        string s(26, 0);
        for (auto c: str) {
            s[c-'a'] = 1;
        }
        return s;
    }

    string str2State_v2(string &str, vector<int> &state) {
        string s(26, 0);
        for (int i=0; i<str.size(); i++) {
            if (state[i]) {
                s[ str[i] - 'a' ] = 1;
            }
        }
        return s;
    }
};
