class Solution {
public:
    int minJumps(vector<int>& arr) {
        int bCount = 0;
        vector<vector<int>> buckets;
        vector<bool> visited(arr.size(), false);
        unordered_map<int, int> m;
        for (int i=0; i<arr.size(); i++) {
            if (m.find(arr[i])==m.end()) {
                m[arr[i]] = bCount++;
                buckets.push_back({i});
            }
            else {
                buckets[m[arr[i]]].push_back(i);
            }
        }
        vector<int> bVisited(buckets.size(), 0);
        for (int i=0; i<buckets.size(); i++) {
            bVisited[i] = buckets[i].size();
        }
        queue<int> q;
        int curr = 1, next = 0, level = 0;
        q.push(0);
        visited[0] = true;
        bVisited[m[arr[0]]]--;
        while (!q.empty()) {
            while(curr--) {
                int index = q.front();
                q.pop();
                if (index == arr.size()-1) {
                    return level;
                }
                if (index+1 < arr.size() && !visited[index+1]) {
                    visited[index+1] = true;
                    bVisited[m[arr[index+1]]]--;
                    q.push(index+1);
                    next++;
                }
                if (index-1 >= 0 && !visited[index-1]) {
                    visited[index-1] = true;
                    bVisited[m[arr[index-1]]]--;
                    q.push(index-1);
                    next++;
                }
                if (bVisited[m[arr[index]]] == 0) {
                    continue;
                }
                vector<int> bucket = buckets[m[arr[index]]];
                for (int ele: bucket) {
                    if (visited[ele]) {
                        continue;
                    }
                    visited[ele] = true;
                    bVisited[m[arr[index]]]--;
                    q.push(ele);
                    next++;
                }
            }
            curr = next;
            next = 0;
            level++;
        }
        return -1;
    }
};
