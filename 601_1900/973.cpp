//class Solution {
//public:
//    static bool cmp(vector<int> &a, vector<int> &b) {
//        return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
//    }
//
//    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
//        sort(points.begin(), points.end(), cmp);
//
//        return vector<vector<int>>(points.begin(), points.begin()+K);
//    }
//};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<pair<int, int>> q;
        int distance;
        for (int i=0; i<K; i++) {
            distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            q.emplace(pair<int, int>(distance, i));
        }
        for (int i=K; i<points.size(); i++) {
            distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if (distance < q.top().first) {
                q.pop();
                q.emplace(pair<int, int>(distance, i));
            }
        }
        vector<vector<int>> r;
        while (!q.empty()) {
            r.push_back(points[q.top().second]);
            q.pop();
        }
        return r;
    }
};
