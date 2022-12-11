# include <vector>
# include <string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for (auto c: words[i]) {
                mask[i] |= (1 << (c - 'a'));
            }
        }

        int res = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    res = max(res, int(words[i].length() * words[j].size()));
                }
            }
        }

        return res;
    }
};