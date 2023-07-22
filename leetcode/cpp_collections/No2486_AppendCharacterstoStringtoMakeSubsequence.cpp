# include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {

        auto it_t = t.begin();
        for (auto& c: s) {
            if (c == *it_t) {
                ++it_t;
            }
            if (it_t == t.end())
                break;
        }

        return t.end() - it_t;
    }
};