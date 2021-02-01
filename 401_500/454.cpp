class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m1, m2;
        calSums(A, B, m1);
        calSums(C, D, m2);
        int cnt = 0;
        for (auto it = m1.begin(); it != m1.end(); it++) {
            int v = (*it).first;
            if (m2.find(-1*v) != m2.end()) {
                cnt += m1[v] * m2[-1*v];
            }
        }
        return cnt;
    }

    void calSums(vector<int>& A, vector<int>& B, unordered_map<int, int> &m) {
        for (int a: A) {
            for (int b: B) {
                if (m.find(a+b) != m.end()) {
                    m[a+b]++;
                }
                else {
                    m[a+b] = 1;
                }
            }
        }
    }

};
