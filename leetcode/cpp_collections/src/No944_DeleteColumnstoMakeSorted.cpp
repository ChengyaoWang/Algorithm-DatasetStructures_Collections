# include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<char> v(strs[0].size(), 'a' - 1);
        vector<bool> mask(strs[0].size(), false);

        int cnter = 0;
        for (auto &s: strs) {
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] < v[i] && !mask[i]) {
                    mask[i] = true;
                    ++cnter;
                }
                v[i] = s[i];
            }
        }

        return cnter;
    }
};