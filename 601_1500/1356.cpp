class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), binCmp);
        return arr;
    }

    static bool binCmp(int a, int b) {
        int aBits = 0, bBits = 0, copyA = a, copyB = b;
        while (a > 0) {
            aBits += a & 1;
            a = a>>1;
        }
        while (b > 0) {
            bBits += b & 1;
            b = b>>1;
        }
        return aBits == bBits ? copyA < copyB : aBits < bBits;
    }
};
