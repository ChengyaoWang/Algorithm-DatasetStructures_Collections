# include <cmath>

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) {
            return false;
        }
        int cumSum = 0, hi = int(sqrt(double(num)));
        for (int i = 1; i <= hi; ++i) {
            if (num % i == 0) {
                cumSum += i + num / i;
            }
        }

        return cumSum == 2 * num;
    }
};