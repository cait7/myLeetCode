class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<int> letter2Num({2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9});
        vector<string> ans;
        int i;
        for (auto& str: words) {
            for (i=0; i<num.size(); i++) {
                if (num[i] != letter2Num[ str[i] - 'a' ] + '0' ) {
                    break;
                }
            }
            if (i == num.size()) {
                ans.push_back( str );
            }
        }
        return ans;
    }
};
