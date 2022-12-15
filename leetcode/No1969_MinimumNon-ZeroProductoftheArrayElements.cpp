
typedef long long ll;

class Solution {
public:
    int minNonZeroProduct(int p) {
        ll MODNUM = 1000000007;
        ll res = ((ll(1) << p) - 1) % MODNUM;
        ll base = ((ll(1) << p) - 2) % MODNUM;
        ll power = (ll(1) << (p - 1)) - 1;
        while (power) {
            if (power % 2) {
                res = (res * base) % MODNUM;
            }
            base = (base * base) % MODNUM;
            power >>= 1;
        }
        return res;
    }
};