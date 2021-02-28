class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<vector<int>> pairs;
        for (int i=0; i<values.size(); i++) {
            pairs.push_back( vector<int>({ values[i], labels[i] }) );
        }
        sort(pairs.begin(), pairs.end(), mySort);
        // Greedy Algorithm
        int maxSum = 0, value, label;
        unordered_map<int, int> used;
        for (auto &ele: pairs) {
            value = ele[0];
            label = ele[1];
            if (used.find(label) == used.end()) {
                used[label] = 1;
                maxSum += value;
            }
            else if (used[label] < use_limit) {
                used[label] += 1;
                maxSum += value;
            }
            else {
                continue;
            }
            num_wanted--;
            if (!num_wanted) {
                break;
            }
        }
        return maxSum;
    }

    static bool mySort(vector<int>& first, vector<int>& second) {
        return first[0] > second[0];
    }
};
