class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), 0);
        int numOfGroup = 0;
        for (int i=0; i<isConnected.size(); i++) {
            if (visited[i]) continue;
            dfs(isConnected, visited, i);
            numOfGroup++;
        }
        return numOfGroup;
    }

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int start) {
        for (int i=0; i<isConnected.size(); i++) {
            if (!visited[i] && isConnected[start][i]) {
                visited[i] = true;
                dfs(isConnected, visited, i);
            }
        }
    }
};
