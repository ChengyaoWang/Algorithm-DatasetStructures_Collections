# include <vector>
# include <string>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

        int ret = 0;
        unordered_map<char, int> uniqueCharCnter;
        unordered_map<string, int> substrCnter;

        for (int hi = 0; hi < s.size(); ++hi) {
            ++uniqueCharCnter[s[hi]];
            if (hi >= minSize) {
                if (--uniqueCharCnter[s[hi - minSize]] == 0) {
                    uniqueCharCnter.erase(s[hi - minSize]);
                }
            }
            if (hi >= minSize - 1) {
                if (uniqueCharCnter.size() <= maxLetters) {
                    ret = max(ret, ++substrCnter[s.substr(hi - minSize + 1, minSize)]);
                }
            }
        }

        return ret;        
    }
};