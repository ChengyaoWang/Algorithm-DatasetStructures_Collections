# include <vector>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        auto cntDigitSum = [](int a) {
            int cumSum = 0;
            while (a) {
                cumSum += a % 10;
                a /= 10;
            }
            return cumSum;
        };

        vector<int> cnter(36 + 1);
        for (int i = 1; i < n; ++i) {
            ++cnter[cntDigitSum(i)];
        }

        int a = -1, b = 0;
        for (auto elem: cnter) {
            if (elem == a) {
                ++b;
            } else if (elem > a) {
                b = 1;
            }
        }

        return b;
    }
};