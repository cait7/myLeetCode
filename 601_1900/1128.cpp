class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int arr[10][10] = {0};
        for (auto& d: dominoes) {
            arr[ d[0] ][ d[1] ]++;
        }
        int ans = 0;
        for (int i=1; i<10; i++) {
            for (int j=i+1; j<10; j++) {
                ans += arr[i][j] * arr[j][i] + arr[i][j] * (arr[i][j]-1) / 2 + arr[j][i] * (arr[j][i]-1) / 2;
            }
        }
        for (int i=1; i<10; i++) {
            ans += arr[i][i] * (arr[i][i] - 1) / 2;
        }
        return ans;
    }
};
