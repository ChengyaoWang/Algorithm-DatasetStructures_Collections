# include <vector>
# include <string>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {

        unordered_set<string> mem;
        for (int l = 1; l <= s.size(); ++l) {
            mem.insert(s.substr(0, l));
        }

        int ret = 0;
        for (auto& i: words) {
            ret += (mem.find(i) != mem.end());
        }

        return ret;
    }
};