class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i, j, sPtr, tPtr;
        
        i = j = 0;
        sPtr = s.size();
        tPtr = t.size();

        while (i < sPtr && j < tPtr) {
            if (s[i] == t[j]) {
                i++;
            }
            
            j++;
        }

        return i == sPtr;
    }
};
