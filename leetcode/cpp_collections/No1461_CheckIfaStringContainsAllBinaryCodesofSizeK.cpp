# include <string>
# include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        unordered_set<int> mem = {};
        for (int i = 0; i <= s.size() - k; ++i) {
            string sub = s.substr(i, k);
            mem.insert(stoi(sub, nullptr, 2));
        }
        return mem.size() == (1 << k);
    }
};