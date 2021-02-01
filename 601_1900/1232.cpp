class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() < 2) {
            return true;
        }
        double theta = calTheta(coordinates[1], coordinates[0]);
        bool isInLine = coordinates[0][0] == coordinates[1][0];
        for (int i=2; i<coordinates.size(); i++) {
            if (isInLine && coordinates[0][0] != coordinates[i][0]) {
                return false;
            }
            if (!isInLine && theta != calTheta(coordinates[i], coordinates[0])) {
                return false;
            }
        }
        return true;
    }
    
    inline double calTheta(vector<int>& p1, vector<int>& p2) {
        return (p1[1] - p2[1])*1.0/(p1[0] - p2[0]);
    }
};
