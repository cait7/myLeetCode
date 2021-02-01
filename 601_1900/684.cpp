class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int vertices = edges.size();
        for (int i=0; i<vertices; i++) {
            edges[i][0]--;
            edges[i][1]--;
        }
        vector<vector<int>> tb(vertices, vector<int>(vertices, 0));
        for (auto& edge: edges) {
            tb[edge[0]][edge[1]] = tb[edge[1]][edge[0]] = 1;
        }
        for (int i=0; i<edges.size(); i++) {
            int v1 = edges[edges.size()-1-i][0], v2 = edges[edges.size()-1-i][1];
            tb[v1][v2] = tb[v2][v1] = 0;
            if (isUndirectedCycleGraph(vertices, tb, edges[(i+1)%edges.size()][0])) {
                return vector<int>({v1+1, v2+1});
            }
            tb[v1][v2] = tb[v2][v1] = 1;
        }
        return vector<int>();
    }

    bool isUndirectedCycleGraph(int vertices, vector<vector<int>>& tb, int start) {
        if (vertices < 2) {
            return true;
        }
        vector<bool> visited(vertices, false);
        queue<int> q;
        int width = 1, add;
        q.push(start);
        while (!q.empty()) {
            add = 0;
            for (int i=0; i<width; i++) {
                int v = q.front();
                q.pop();
                if (visited[v]) {
                    return false;
                }
                visited[v] = true;
                for (int j=0; j<vertices; j++) {
                    if (tb[v][j] && !visited[j]) {
                        q.push(j);
                        add++;
                    }
                }
            }
            width = add;
        }
        for (int i=0; i<vertices; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};
