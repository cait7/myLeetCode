class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), myCmp);
        int numOfPeople = people.size(), pos;
        vector<vector<int>> ans = people;
        vector<int> visited(numOfPeople, 0);
        for (vector<int> &p: people) {
            pos = findValidIndex(p[0], p[1], visited, ans);
            ans[pos] = p;
            visited[pos] = 1;
        }
        return ans;
    }

    static bool myCmp(vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }

    int findValidIndex(int h, int k, vector<int> &visited, vector<vector<int>> &ans) {
        int i;
        for (i=0; i<visited.size(); i++) {
            if (visited[i] == 0 || ans[i][0] >= h) {
                k--;
                if (k<0) break;
            }
            else {
                continue;
            }
        }
        return i;
    }
};
