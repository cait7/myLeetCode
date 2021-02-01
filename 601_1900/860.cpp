class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> numOfCoins = {0, 0, 0};
        for (int b: bills) {
            switch (b) {
                case 5:
                    numOfCoins[0] += 1;
                    break;
                case 10:
                    numOfCoins[1] += 1;
                    if (numOfCoins[0] <= 0) {
                        return false;
                    }
                    numOfCoins[0] -= 1;
                    break;
                case 20:
                    numOfCoins[2] += 1;
                    if (numOfCoins[0] > 0 && numOfCoins[1] > 0) {
                        numOfCoins[0] -= 1;
                        numOfCoins[1] -= 1;
                    }
                    else if (numOfCoins[0] > 2) {
                        numOfCoins[0] -= 3;
                    }
                    else {
                        return false;
                    }
                    break;

            }
        }
        return true;
    }
};
