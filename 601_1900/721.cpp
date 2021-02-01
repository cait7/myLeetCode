class Disjoint {
public:
    Disjoint(int num) {
        parents = vector<int>(num, 0);
        for (int i=0; i<num; i++) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    void merge(int x, int y) {
        parents[find(x)] = parents[find(y)];
    }

private:
    vector<int> parents;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        Disjoint djoint(accounts.size());
        unordered_map<string, int> m;
        string address;
        for (int i=0; i<accounts.size(); i++) {
            for (int j=1; j<accounts[i].size(); j++) {
                address = accounts[i][j];
                if (m.find(address) == m.end()) {
                    m[address] = i;
                }
                else {
                    djoint.merge(i, m[address]);
                }
            }
        }
        unordered_map<int, int> m2;
        int uid = 0, index;
        vector<vector<string>> ans;
        for (int i=0; i<accounts.size(); i++) {
            if (m2.find(djoint.find(i)) == m2.end()) {
               m2[djoint.find(i)] = uid++;
               ans.push_back({accounts[i][0]});
            }
        }
        for (auto& iter: m) {
            address = iter.first;
            index = m2[djoint.find(iter.second)];
            ans[index].push_back(address);
        }
        for (int i=0; i<ans.size(); i++) {
            sort(ans[i].begin()+1, ans[i].end());
        }
        return ans;
    }
};
