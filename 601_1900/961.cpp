class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> m;
        for (int a: A) {
            if (m.find(a)==m.end()) {
                m[a] = 1;
            }
            else {
                return a;
            }
        }
        return -1;
    }
};
