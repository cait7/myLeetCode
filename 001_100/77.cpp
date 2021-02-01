class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<bool> visited(n, false);
        vector<int> c(k, 0);
        dfs(ans, visited, n, k, c);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<bool>& visited, int n, int k, vector<int>& c) {
        if (k == 0) {
            ans.push_back(c);
            return;
        }
        int start = c.size() == k ? 0 : c[c.size()-k-1];
        for (int i=start; i<visited.size(); i++) {
            if (!visited[i]) {
                c[ c.size()-k ] = i+1;
                visited[i] = true;
                dfs(ans, visited, n, k-1, c);
                visited[i] = false;
            }
        }
    }
};
