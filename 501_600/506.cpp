class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> m;
        int index = 0;
        for (int i=0; i<score.size(); i++) {
            m[score[i]] = index++;
        }
        sort(score.begin(), score.end());
        vector<string> ans(score.size(), "");
        vector<string> medals({"Gold Medal", "Silver Medal", "Bronze Medal"});
        for (int i=0; i<score.size(); i++) {
            if (score.size()-i <= 3) {
                ans[ m[score[i]] ] = medals[ score.size()-i-1 ];
            }
            else {
                ans[ m[score[i]] ] = to_string( score.size()-i );
            }
        }
        return ans;
    }
};
