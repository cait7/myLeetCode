typedef vector<int> Point;
typedef struct PointToPoint{
    int i;
    int j;
    int len;
    PointToPoint(int _i, int _j, int _len) {
        i = _i;
        j = _j;
        len = _len;
    }
} Edge;

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
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() < 2) {
            return 0;
        }
        vector<Edge> edges;
        for (int i=0; i<points.size(); i++) {
            for (int j=i+1; j<points.size(); j++) {
                edges.push_back(Edge(i, j, mhd(points[i], points[j])));
            }
        }
        sort(edges.begin(), edges.end(), edgeCmp);
        // 贪心搜索
        Disjoint djoint(points.size());
        int ans = 0;
        for (auto &edge: edges) {
            if (djoint.find(edge.i) == djoint.find(edge.j)) {
                continue;
            }
            else {
                ans += edge.len;
                djoint.merge(edge.i, edge.j);
            }
        }
        return ans;
    }

    static bool edgeCmp(Edge& e1, Edge& e2) {
        return e1.len < e2.len;
    }

    inline static int mhd(Point& p1, Point& p2) {
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }

private:
    int ans;
};
