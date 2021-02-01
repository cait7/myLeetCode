class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int stations = gas.size();
        for (int i=0; i<stations; i++) {
            int ret = gas[i], visited = 0, j=i;
            while (visited!=stations) {
                if (ret < cost[j]) {
                    break;
                }
                else {
                    ret = ret - cost[j] + gas[(j+1)%stations];
                    j = (j+1)%stations;
                    visited++;
                }
            }
            if (visited==stations) {
                return i;
            }
        }
        return -1;
    }
};
