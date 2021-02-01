class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {       
        int count = 0;
        unordered_map<string, int> m;
        // 记录节点
        for (vector<string> &eq: equations) {
            for (string &s: eq) {
                if (m.find(s) == m.end()) {
                    m[s] = count++;
                }
            }
        }
        if (count == 0 || queries.size() == 0) {
            return vector<double>();
        }
        // 建立有向图
        vector<vector<double>> dag(count, vector<double>(count, -1.0));
        for (int i=0; i<equations.size(); i++) {
            int start = m[equations[i][0]], end = m[equations[i][1]];
            double v = values[i];
            dag[start][end] = v;
            dag[end][start] = 1.0 / v;
        }
        // 查询问题的答案
        vector<double> ans;
        for (vector<string> q : queries) {
            double res;
            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end()) {
                res = -1.0;
            }
            else {
                vector<int> visited(count, 0);
                res = bfs(dag, visited, m[q[0]], m[q[1]], count);
            }
            ans.push_back(res);
        }
        return ans;
    }

    double bfs(vector<vector<double>>& dag, vector<int>& visited, int start, int end, int count) {
        for (int i=0; i<count; i++) {
            if (dag[start][i] < 0  || visited[i]) {
                continue;
            }
            if (i == end) {
                return dag[start][end];
            }
            visited[i] = 1;
            double ans = bfs(dag, visited, i, end, count);
            if (ans != -1.0) {
                return ans * dag[start][i];
            }
        }
        return -1.0;
    }
};