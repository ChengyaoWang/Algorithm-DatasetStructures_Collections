# include <string>
# include <vector>
# include <numeric>
# include <unordered_map>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a') || (c == 'e') || (c == 'i') ||
            (c == 'o') || (c == 'u');
    }

    int minValue(unordered_map<int, int>& m) {
        int ret = numeric_limits<int>::max();
        for (auto& [k, v]: m) {
            ret = min(ret, v);
        }
        return ret;
    }

    int countVowelSubstrings(string word) {

        int ret = 0;
        unordered_map<int, int> lastIdx;
        int lo = -1;
        for (auto up = 0; up < word.size(); ++up) {
            
            if (!isVowel(word[up])) {
                lastIdx.clear();
                lo = up;
                continue;
            }

            lastIdx[word[up]] = up;
            if (lastIdx.size() == 5)
                ret += minValue(lastIdx) - lo;
        }

        return ret;
    }
};