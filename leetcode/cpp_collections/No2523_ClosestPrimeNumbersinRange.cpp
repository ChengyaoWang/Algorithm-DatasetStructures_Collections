# include <vector>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {

        vector<char> mem(right + 1, 0);
        vector<int> primes;

        for (int i = 2; i <= right; ++i) {
            if (mem[i] == 0 && i >= left) {
                if (!primes.empty() && (i - primes.back() <= 2))
                    return {primes.back(), i};
                primes.push_back(i);
            }
            auto j = 2 * i;
            while (j <= right) {
                mem[j] |= 255;
                j += i;
            }
        }

        int dis = numeric_limits<int>::max();
        vector<int> ret = {-1, -1};
        if (primes.size() < 2)
            return ret;
        for (int i = 0; i < primes.size() - 1; ++i) {
            if (primes[i + 1] - primes[i] < dis) {
                dis = primes[i + 1] - primes[i];
                ret = {primes[i], primes[i + 1]};
            }
        }

        return ret;
    }
};