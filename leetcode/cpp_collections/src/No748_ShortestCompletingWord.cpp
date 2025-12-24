# include <string>
# include <vector>
# include <limits>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        vector<int> tgt = stringCnter(licensePlate, vector<int>(26), false);
        int maxL = numeric_limits<int>::max();
        string ret;
        for (auto& word: words) {
            auto a = stringCnter(word, tgt, true);
            bool cmp = all_of(a.begin(), a.end(), [](int i){return i <= 0;});
            if (cmp && word.size() < maxL) {
                ret = word;
                maxL = word.size();
            }
        }
        return ret;
    }

    vector<int> stringCnter(string s, vector<int> base, bool reverse) {
        for (auto &c: s) {
            if (isdigit(c) || c == ' ')
                continue;
            base[tolower(c) - 'a'] += reverse ? -1: 1;
        }
        return base;
    }
};