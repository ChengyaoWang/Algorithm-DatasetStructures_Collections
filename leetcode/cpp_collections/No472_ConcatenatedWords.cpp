# include <vector>
# include <string>
# include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        vector<string> ret;
        unordered_set<string> baseStrs;
        sort(
            words.begin(), words.end(),
            [](const string& a, const string& b) {
                if (a.size() == b.size())   return a < b;
                return a.size() < b.size();
            }
        );

        for (auto& word: words) {
            int dp = 1;
            for (int i = 1; i <= word.size(); ++i) {
                auto flag = false;
                for (int j = 0; j < i; ++j) {
                    if (dp & (1 << j)) {
                        flag |= baseStrs.find(word.substr(j, i - j)) != baseStrs.end();
                    }
                }
                if (flag)
                    dp |= (1 << i);
            }

            if (dp & (1 << word.size())) {
                ret.push_back(word);
            } else {
                baseStrs.insert(word);
            }
        }

        return ret;
    }
};