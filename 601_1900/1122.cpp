class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> theMap;
        unordered_set<int> theSet;
        vector<int> disapper;
        for (int &i: arr2) {
            theSet.insert(i);
        }
        for (int &i: arr1) {
            if (theSet.find(i) == theSet.end()) {
                disapper.push_back(i);
            }
            else if (theMap.find(i) == theMap.end()) {
                theMap.insert(pair<int, int>(i, 1));
            }
            else {
                theMap[i] += 1;
            }
        }
        vector<int> ans(arr1.size(), 0);
        int index = 0;
        for (int &i: arr2) {
            for (int j=0; j<theMap[i]; j++) {
                ans[index++] = i;
            }
        }
        sort(disapper.begin(), disapper.end());
        for (int &i: disapper) {
            ans[index++] = i;
        }
        return ans;
    }
};
