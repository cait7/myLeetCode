class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record(1000, 0);
        int count = 0;
        for (string& s: ops) {
            if (s == "C" && count) {
                count--;
            }
            else if (s == "D" && count) {
                record[count] = record[count-1] * 2;
                count++;
            }
            else if (s == "+" && count > 1) {
                record[count] = record[count-1] + record[count-2];
                count++;
            }
            else {
                record[count++] = atoi(s.c_str());
            }
        }
        int ans = 0;
        for (int i=0; i<count; i++) {
            ans += record[i];
        }
        return ans;
    }
};
