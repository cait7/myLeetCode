class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0]==rec1[2] || rec1[1]==rec1[3] || rec2[0]==rec2[2] || rec2[1]==rec2[3]) {
            return false;
        }
        long height1, height2, width1, width2, wDis, hDis;
        height1 = rec1[3] - rec1[1];
        height2 = rec2[3] - rec2[1];
        width1 = rec1[2] - rec1[0];
        width2 = rec2[2] - rec2[0];
        wDis = max(abs(rec1[3] - rec2[1]), abs(rec2[3] - rec1[1]));
        hDis = max(abs(rec1[2] - rec2[0]), abs(rec2[2] - rec1[0]));
        return wDis < height1 + height2 && hDis < width1 + width2;
    }
};
