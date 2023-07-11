class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int bc2 = __builtin_popcount(num2);

        int res = 0;
        for (int i = 31; i >= 0; --i) {
            auto tmp = num1 & (1 << i);
            if (tmp != 0 && bc2 > 0) {
                res |= (1 << i);
                --bc2;
            }
        }

        for (int i = 0; i < 32; ++i) {
            auto tmp = num1 & (1 << i);
            if (tmp == 0 && bc2 > 0) {
                res |= (1 << i);
                --bc2;
            }
        }

        return res;        
    }
};