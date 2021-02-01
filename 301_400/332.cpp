class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!flowerbed[0] && (flowerbed.size() < 2 || !flowerbed[1])) {
            flowerbed[0] = 1;
            n--;
        }
        for (int i=1; i<flowerbed.size()-1; i++) {
            if (!flowerbed[i-1] && !flowerbed[i] && !flowerbed[i+1]) {
                flowerbed[i] = 1;
                n--;
            }
        }
        if (!flowerbed[flowerbed.size()-1] && (flowerbed.size() > 1 && !flowerbed[flowerbed.size()-2])) {
            n--;
        }
        return n <= 0;
    }
};