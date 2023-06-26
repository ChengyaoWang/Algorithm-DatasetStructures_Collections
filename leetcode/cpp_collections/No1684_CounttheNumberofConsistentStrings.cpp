# include <string>
# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> mem = {};
        for (auto& c: allowed) {
            mem.insert(c);
        }

        int ret = 0;
        for (auto& word: words) {
            bool flag = true;
            for (auto& c: word) {
                flag &= (mem.find(c) != mem.end());
            }
            if (flag) {
                ++ret;
            }
        }

        return ret;
    }
};