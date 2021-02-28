class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> states(256, -1), curr, next;
        curr = next = cells;
        prisonAfterOneDay(curr, next);
        unordered_map<int, int> trans;
        for (int i=1; i<=N; i++) {
            if (states[ getState(next) ] != -1) {
                break;
            }
            states[ getState(next) ] = 1;
            trans[i] = getState(next);
            curr = next;
            prisonAfterOneDay(curr, next);
        }
        int peroid = trans.size(), day;
        day = N % peroid;
        return getCells( trans[ day == 0 ? peroid : day ] );
    }

    void prisonAfterOneDay(vector<int>& cells, vector<int>& next) {
        next[0] = next[next.size()-1] = 0;
        for (int j=1; j<cells.size()-1; j++) {
            next[j] = cells[j-1] == cells[j+1];
        }
    }

    int getState(vector<int>& state) {
        int ans = 0;
        for (int i=0; i<state.size(); i++) {
            ans = ans * 2 + state[i];
        }
        return ans;
    }

    vector<int> getCells(int value) {
        vector<int> ans(8, 0);
        for (int i=0; i<8; i++) {
            ans[7-i] = value%2;
            value = value/2;
        }
        return ans;
    }
};
