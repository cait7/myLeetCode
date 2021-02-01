class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int gives = 1, pos = 0;
        vector<int> ans(num_people, 0);
        while (candies > 0) {
            gives = min(gives, candies);
            pos %= num_people;
            ans[pos] += gives;
            candies -= gives;
            pos++;
            gives++;
        }
        return ans;
    }
};
