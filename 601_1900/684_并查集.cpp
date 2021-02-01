class Disjoint {
public:
    Disjoint(int n) {
        parent = vector<int>(n, 0);
        for (int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int i, int j) {
        int index1 = find(i), index2 = find(j);
        parent[index1] = index2;
    }

private:
    vector<int> parent;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int vertices = edges.size();
        Disjoint djoint(vertices+1);
        for (int i=0; i<edges.size(); i++) {
            int v1 = edges[i][0], v2 = edges[i][1];
            if (djoint.find(v1) != djoint.find(v2)) {
                djoint.merge(v1, v2);
            }
            else {
                return edges[i];
            }
        }
        return vector<int>();
    }
};
