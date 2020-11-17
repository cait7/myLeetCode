class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int size = wordList.size(), endId = -1;
        // 构建邻接矩阵
        vector<vector<int>> graph(size, vector<int>(size, 0));
        for (int i=0; i<size; i++) {
            if (wordList[i] == endWord) {
                endId = i;
            }
            for (int j=i+1; j<size; j++) {
                if (isNeighbor(wordList[i], wordList[j])) {
                   graph[i][j] = graph[j][i] = 1;
                }
            }
        }
        // 不存在这样的转换，返回0
        if (endId == -1) {
            return 0;
        }
        // 初始化dfs
        vector<int> dist(size, INT_MAX), visited(size, 0);
        queue<int> q;
        for (int i=0; i<size; i++) {
            if (isNeighbor(beginWord, wordList[i])) {
                dist[i] = 1;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int nid = q.front();
            q.pop();
            if (visited[nid]) {
                continue;
            }
            else visited[nid] = 1;
            if (nid == endId) {
                return dist[nid] + 1;
            }
            for (int i=0; i<size; i++) {
                if (graph[nid][i]) {
                    q.push(i);
                    dist[i] = min(dist[nid] + 1, dist[i]);
                }
            }
        }
        return 0;
    }

    bool isNeighbor(string &str1, string &str2) {
        int sum = 0;
        for (int i=0; i<str1.size(); i++) {
            sum += str1[i] == str2[i] ? 0 : 1;
        }
        return sum == 1;
    }
};
