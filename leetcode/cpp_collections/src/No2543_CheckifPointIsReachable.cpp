# include <vector>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (a < b)      swap(a, b);
        if (b == 0)     return a;
        return gcd(a % b, b);
    }

    bool isReachable(int targetX, int targetY) {
        auto res = gcd(targetX, targetY);
        while (res % 2 == 0) {
            res >>= 1;
        }
        return res == 1;
    }
};