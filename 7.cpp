class Solution {
public:
    int reverse(int x) {
       long invert = 0;

       while (x) {
           int bit = x%10;
           
           x = x/10;
           invert = invert * 10 + bit;
       }

        if (invert > 0x7fffffff || invert < int(0x80000000)) {
               return 0;
        }
        else return invert;
    }
};
