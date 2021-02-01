class Disjoint {
public:
    Disjoint(int size) {
        parent = vector<int>(size, 0);
        for (int i=0; i<size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(vector<int>& pair) {
        int p1 = find(pair[0]), p2 = find(pair[1]);
        parent[p1] = p2;
    }

    vector<vector<int>> getBuckets() {
        unordered_map<int, int> m;
        vector<vector<int>> ans;
        int bid = 0;
        for (int i=0; i<parent.size(); i++) {
            int pid = find(i);
            if (m.find(pid) == m.end()) {
                m[pid] = bid++;
                ans.push_back({i});
            }
            else {
                ans[m[pid]].push_back(i);
            }
        }
        return ans;
    }

private:
    vector<int> parent;
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        Disjoint djoint(s.size());
        for (vector<int>& p: pairs) {
            djoint.merge(p);
        }
        vector<vector<int>> buckets = djoint.getBuckets();
        string ans(s.size(), ' ');
        for (auto& b: buckets) {
            vector<char> cArray(b.size(), ' ');
            for (int i=0; i<b.size(); i++) {
                cArray[i] = s[b[i]];
            }
            sort(cArray.begin(), cArray.end());
            for (int i=0; i<b.size(); i++) {
                ans[b[i]] = cArray[i];
            }
        }
        return ans;
    }
};
