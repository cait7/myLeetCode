class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len1 = name.size(), len2 = typed.size(), i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            }
            else if (j>0 && typed[j]==typed[j-1]) {
                j++;
            }
            else {
                break;
            }
        }
        
        if (i!=len1) {
            return false;
        }
        else if (i==len1 && j==len2) {
            return true;
        }
        for (; j<len2; j++) {
            if (j>0 && typed[j]==typed[j-1]) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
