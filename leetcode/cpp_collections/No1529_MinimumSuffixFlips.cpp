# include <string>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        char prev = '0';
        int cnt = 0;
        for (auto c: target) {
            cnt += (prev != c);
            prev = c;
        }
        return cnt;
    }
};