class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int num = points.size();
        vector<vector<int>> dist(num, vector<int>(num, 0));
        for (int i=0; i<num; i++) {
            for (int j=i+1; j<num; j++) {
                dist[i][j] = dist[j][i] = pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2);
            }
        }
        int ans = 0;
        for (int i=0; i<num; i++) {
            unordered_map<int, int> m;
            int d;
            for (int j=0; j<num; j++) {
                d = dist[i][j];
                if (m.find(d) != m.end()) {
                    m[d]++;
                }
                else {
                    m[d] = 1;
                }
            }
            for (auto& iter: m) {
                if (iter.second > 1) {
                    ans += C(iter.second, 2);
                }
            }
        }
        return ans*2;
    }

    inline int C(int a, int b) {
        return fac(a)/(fac(b)*fac(a-b));
    }

    inline int fac(int a) {
        int ans = 1;
        for (int i=1; i<=a; i++) {
            ans *= i;
        }
        return ans;
    }
};
