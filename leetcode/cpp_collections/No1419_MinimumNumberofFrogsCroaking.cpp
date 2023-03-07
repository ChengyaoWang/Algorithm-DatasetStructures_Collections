# include <vector>
# include <string>
# include <numeric>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int ret = 0, tmp = 0;
        vector<int> cnter(5);
        unordered_map<char, int> map = {
            {'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}
        };
        for (auto& c: croakOfFrogs) {
            if (c == 'c') {
                ++tmp;
                ++cnter[0];
            } else {
                auto i = map[c];
                if (cnter[i - 1] == 0) {
                    return -1;
                }
                --cnter[i - 1];
                if (i == 4) {
                    --tmp;
                } else {
                    ++cnter[i];
                }
            }
            ret = max(ret, tmp);
        }
    
        auto remain = accumulate(cnter.begin(), cnter.end(), 0);
        return remain == 0 ? ret: -1;
    }
};