# include <vector>
# include <string>
# include <numeric>
# include <unordered_map>
using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {
        string tfm_s, black = "";
        unordered_map<string, vector<string>> cnter;
        for (auto s: words) {
            tfm_s.clear();
            for (int i = 1; i < s.size(); ++i) {
                tfm_s += "_" + to_string(s[i] - s[i - 1]);
            };
            cnter[tfm_s].push_back(s);
        }

        for (auto& [_, b]: cnter) {
            if (b.size() == 1)
                return b[0];
        }

        return "";

    }
};