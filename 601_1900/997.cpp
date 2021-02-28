class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> voted(N+1, 0), voting(N+1, 0);
        for (auto& t: trust) {
            voted[ t[1] ]++;
            voting[ t[0] ]++;
        }
        for (int i=1; i<=N; i++) {
            if (voted[i] == N-1 && voting[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};
