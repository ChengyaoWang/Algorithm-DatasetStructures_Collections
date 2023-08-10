# include <string>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        unordered_map<int, int> cnter;
        for (auto& c: s) {
            ++cnter[c];
        }

        int ret = 0;
        for (;;) {
            for (auto& c: target) {
                if (--cnter[c] == -1) {
                    return ret;
                }
            }
            ++ret;
        }

        return 0;
    }
};