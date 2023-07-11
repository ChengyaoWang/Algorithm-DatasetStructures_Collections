# include <math.h>
using namespace std;

class Solution {
public:
    int smallestValue(int n) {
        int nNext = 0;
        for (;;) {
            for (int i = 2, ntmp = n; i <= n; ++i) {
                while (ntmp % i == 0) {
                    ntmp /= i;
                    nNext += i;
                }
            }
            if (nNext >= n) break;
            n = nNext;
            nNext = 0;
        }
        return n;
    }
};