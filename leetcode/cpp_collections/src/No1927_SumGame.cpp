# include <string>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        double res = 0.;
        int N = num.length();
        for (int i = 0; i < N; ++i) {
            auto delta = num[i] == '?' ? 4.5: (num[i] - '0');
            res += delta * (i < N / 2 ? 1: -1);
        }
        return abs(res) > 0.001;
    }
};