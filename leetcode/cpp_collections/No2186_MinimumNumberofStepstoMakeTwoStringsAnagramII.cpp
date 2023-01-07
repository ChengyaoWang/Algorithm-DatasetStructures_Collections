# include <string>
# include <vector>
# include <numeric>
using namespace std;


class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnter(26, 0);
        for (auto &c: s)    ++cnter[c - 'a'];
        for (auto &c: t)    --cnter[c - 'a'];

        return accumulate(
            cnter.begin(), cnter.end(), 0,
            [](int a, int b){ return a + abs(b); }
        );
        
    }
};