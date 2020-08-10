class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minValue, maxValue, average, mid, norm;
        int size;

        size = average = norm = mid = 0;
        minValue = 256;
        maxValue = 0;

        for (int i=0; i<256; i++) {
            size += count[i];
            average += i * count[i];

            if (count[i] > count[norm]) {
                norm = i;
            }

            if (count[i] != 0) {
                minValue = minValue > i ? i: minValue;
                maxValue = maxValue > i ? maxValue : i;
            }
        }
        average = average / size;

        int midIndex1, midIndex2, midValue1, midValue2;
        midIndex1 = size/2;
        midIndex2 = size/2 - 1;
        midValue1 = midValue2 = -1;

        for (int i=0; i<256; i++) {

            if (midIndex1 < count[i] && midValue1 == -1) {
                midValue1 = i;
            }
            
            if (midIndex2 < count[i] && midValue2 == -1) {
                midValue2 = i;
            }

            midIndex1 -= count[i];
            midIndex2 -= count[i];

            if (midIndex1 < 0 && midIndex2 < 0)
                break;
        }

        mid = size%2 ? midValue1 : (midValue1 + midValue2)/2.0;

        vector<double> res;
        res.push_back(minValue);
        res.push_back(maxValue);
        res.push_back(average);
        res.push_back(mid);
        res.push_back(norm);

        return res;
    }
};
