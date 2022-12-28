class Solution {
public:
    int integerReplacement(int n) {
        int ops = 0;
        long long lln = n;
        while (lln != 1) {
            ++ops;
            if (lln % 2 == 0) lln /= 2;
            else if (lln % 4 == 1 || lln == 3) --lln;
            else ++lln;
        }
        return ops;
    }
};