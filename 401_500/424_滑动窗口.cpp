class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if (votes.size() == 0) {
            return "";
        }
        int teams = votes[0].size();
        string res = votes[0];
        sort(res.begin(), res.end());
        for (int i=teams-1; i>=0; i--) {
            // bucket sort
            vector<vector<char>> buckets(votes.size()+1, vector<char>());
            unordered_map<char, int> m; 
            for (char c: res) {
                m[c] = 0;
            }
            for (auto& v: votes) {
                m[v[i]]++;
            }
            for (char c: res) {
                buckets[m[c]].push_back(c); 
            }
            int index = 0;
            for (int j=votes.size(); j>=0; j--) {
                for (auto c: buckets[j]) {
                    res[index++] = c;
                }
            }
        }
        return res;
    }
};