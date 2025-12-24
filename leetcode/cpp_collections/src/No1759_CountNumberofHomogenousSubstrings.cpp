# include <string>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        long long ret = 0LL, cnter = 0LL;
        char c = '0';
        for (auto& i: s) {
            if (i != c) {
                cnter = 1;
            }
            ret += cnter++;
            c = i;
        }
        return (int)(ret % 1000000007);
    }
};