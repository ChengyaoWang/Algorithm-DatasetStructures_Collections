# include <vector>
# include <string>
# include <numeric>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        vector<int> quota(26);
        for (auto& c: chars)
            ++quota[c - 'a'];
        
        int ret = 0;
        vector<int> cnter(26);
        for (auto& w: words) {
            for (auto& c: w) 
                ++cnter[c - 'a'];

            auto flag = true;
            for (int i = 0; i < 26; ++i) {
                flag &= (quota[i] >= cnter[i]);
            }

            if (flag)
                ret += w.size();
            fill(cnter.begin(), cnter.end(), 0);
        }

        return ret;
    }
};