class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        string kStr = to_string(K);
        vector<int> kNum(kStr.size(), 0), ans(max(A.size(), kStr.size()), 0);
        for (int i=0; i<kStr.size(); i++) {
            kNum[i] = kStr[i] - '0';
        }
        int aNum = 0, bNum = 0, carry = 0;
        for (int i=0; i<ans.size(); i++) {
            aNum = i < A.size() ? A[A.size()-1-i] : 0;
            bNum = i < kNum.size() ? kNum[kNum.size()-1-i] : 0;
            ans[ans.size()-i-1] = (aNum + bNum + carry)%10;
            carry = aNum + bNum + carry >= 10 ? 1: 0;
        }
        if (carry == 0) {
            return ans;
        }
        else {
            vector<int> ans2({1});
            ans2.insert(ans2.end(), ans.begin(), ans.end());
            return ans2;
        }
    }
};
