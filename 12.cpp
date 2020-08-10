class Solution {
public:
    string intToRoman(int num) {
        int  values[4] = {1000, 100, 10, 1};
        string res;

        for (int i=0; i<4; i++) {
            int digit = num / values[i];
            num = num - digit * values[i];

            res += numsToRoman(digit, values[i]);
        }

        return res;
    }

    string numsToRoman(int digit, int num) {

        if (digit == 4 || digit == 9) {
            switch ( num*digit ) {
                case 4:
                    return "IV";
                case 9:
                    return "IX";
                case 40:
                    return "XL";
                case 90:
                    return "XC";
                case 400:
                    return "CD";
                case 900:
                    return "CM";
            }
        }

        if (digit >= 5) {
            return numsToRoman(1, 5*num) + numsToRoman(digit - 5, num);
        }

        string c[7] = {"I", "V", "X", "L", "C", "D", "M"};
        int nums[7] = {1, 5, 10, 50, 100, 500, 1000};
        int index = 0;
        string res = "";

        for (int i=0; i<7; i++) {
            if (num == nums[i]) {
                index = i;
            }
        }
        while(digit > 0) {
            res += c[index];
            digit--;
        }

        return res;
    }
};
