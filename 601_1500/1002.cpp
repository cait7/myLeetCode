class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int aTable[26], bTable[26], nums = A.size();
        memset(aTable, 0, sizeof(int)*26);

        if (nums == 0) return A;
        for (int i=0; i<nums; i++) {
            memset(bTable, 0, sizeof(int)*26);

            for (int j=0; j<A[i].size(); j++) {
                bTable[ A[i][j] - 'a' ] += 1;
            }

            if (i==0) {
                for (int j=0; j<26; j++) {
                    aTable[j] = bTable[j];
                }
            }
            else {
                for (int j=0; j<26; j++) {
                    aTable[j] = min(aTable[j], bTable[j]);
                }
            }
        }

        vector<string> result;
        for (int i=0; i<26; i++) {
            while (aTable[i] != 0) {
                result.push_back( string(1,'a'+i) );
                aTable[i]--;
            }
        }

        return result;
    }
};
