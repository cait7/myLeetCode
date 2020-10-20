class Solution {
public:
    string countAndSay(int n) {
        string res[30];
        res[0] = "1";

        for (int i=0; i<n-1; i++) {
            
            int count=1;
            char c=res[i][0];

            for (int k=1; k<res[i].size()+1; k++) {
                if (k==res[i].size()) {
                    res[i+1] += (char)(count + '0');
                    res[i+1] += c;
                }
                else if (res[i][k]!=res[i][k-1]) {
                    res[i+1] += (char)(count + '0');
                    res[i+1] += c;

                    count = 1;
                    c = res[i][k];
                }
                else {
                    count += 1;
                }
            }
        }

        return res[n-1];
    }
};
