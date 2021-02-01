class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int k=0; k<A.size(); k++) {
            if (k%2 && !(A[k]%2)) {
                int s = k+1;
                while (!(A[s]%2) && s<A.size()) {
                    s++;
                }
                if (s<A.size()) swap(A, s, k);
            }
            else if (!(k%2) && A[k]%2) {
                int s = k+1;
                while (A[s]%2 && s<A.size()) {
                    s++;
                }
                if (s<A.size()) swap(A, s, k);
            }

        }
        return A;
    }

    void swap(vector<int>& array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
};
